// class Queue
#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
class Queue;  // pre-declare the template class itself
template<typename T>
std::ostream& operator<<(std::ostream& out, const Queue<T>& aQueue);


template<typename T>
class Queue {
public:
    Queue();
    Queue(const Queue&);                   // ����������� �����������
    Queue(Queue&&) noexcept;               // ����������� �����������
    ~Queue();                               // ����������

    Queue& operator=(const Queue&);        // ������������� �������� ����������� ������������
    Queue& operator=(Queue&&) noexcept;    // ������������� �������� ������������� ������������

    void swap(Queue&) noexcept;            // ����� ���� �������� ���������� (������������ � ��������� ������������)
    void put(const T& d, int p);                  // �������� ������� � ������� � �����������
    T take();                               // ����� ������� �� �������
    void removeTill(int);             // ������� �������� � ����������� ���� ��� ������ ����������
//                                              � ��������������� �������
    void print(std::ostream& stream) const  // ����� ������� �� �����
    {
        node_t* temp = head_;
        while (temp) {
            std::cout << temp->data << '\n';
            temp = temp->next;
        }
    }

    friend std::ostream& operator<<<>(std::ostream&, const Queue<T>& aQueue);


private:
    struct node_t           // ������� �������
    {
        T data;             // ������
        int prioryty;       // ���������
        node_t* next;       // ��������� �� ��������� �������
    };

    node_t* head_;          // ��������� �� ������ �������
    node_t* tail_;          // ��������� �� ����� �������


};

template<typename T>
Queue<T>::Queue() :

    head_(nullptr),
    tail_(nullptr) {}


// ����������� �����������

template<typename T>
Queue<T>::Queue(const Queue& queue) :
    head_(nullptr),
    tail_(nullptr) {
    // �������� ����� ������� ������ ���������� �������, ����� �� ��������� ������ ������
    // � ������ ������������� ���������� ��� �������� ������ ��� ��������� �������
    Queue temp;
    node_t* src = queue.head_;
    while (src) {
        temp.put(src->data, src->prioryty);
        src = src->next;
    }
    swap(temp);
}

// ����������� �����������
template<typename T>
Queue<T>::Queue(Queue&& queue) noexcept :
    head_(nullptr),
    tail_(nullptr) {
    swap(queue);
}

// ����������
template<typename T>
Queue<T>::~Queue() {
    while (head_) {
        node_t* temp = head_;
        head_ = head_->next;
        delete temp;
    }
}

// �������� ����������� ������������
template<typename T>
Queue<T>& Queue<T>::operator=(const Queue& queue) {
    // ���� ����������� ������ ������ ����, �� ������ ������ �� �����
    if (this == &queue) {
        return *this;
    }
    // ������ ����� ������������� �������
    Queue tempQueue(queue);
    // ������ ���������� ��������� ����� � ������������ �������
    swap(tempQueue);
    // ���������� ������ �� ����������� ������
    return *this;

    // ��������� ������ tempQueue ����� ��������� ��� ���������� ������
    // � ��� ���������� ��������� ������, ������� ���������� ����������� �������;
    // ����� ���� ��������� ��������� ������������ ���������� copy-and-swap
}

// �������� ������������� ������������
template<typename T>
Queue<T>& Queue<T>::operator=(Queue&& queue) noexcept {
    swap(queue);
    return *this;
}

// ����� ���������� ��������� � ������������ ������� (������ ������ ���������)
template<typename T>
void Queue<T>::swap(Queue& queue) noexcept {
    std::swap(head_, queue.head_);
    std::swap(tail_, queue.tail_);
}


// ���������� �������� �� �������
template<typename T>
T Queue<T>::take() {
    if (!head_) {
        throw std::logic_error("Queue is empty");
    }
    T res = head_->data;
    node_t* temp = head_;
    if (head_ == tail_)
    {
        head_ = tail_ = nullptr;
    }
    else
    {
        head_ = head_->next;
    }
    delete temp;
    return res;
}




// ���������� �������� � ������� c �����������
template<typename T>
void Queue<T>::put(const T& d, int p)
{
    node_t* input = new node_t;
    input->data = d;
    input->prioryty = p;
    input->next = nullptr;


    if (!head_)
    {
        head_ = tail_ = input;
    }
    else if (head_->prioryty < input->prioryty)
    {
        input->next = head_;
        head_ = input;
    }
    else
    {
        node_t* temp = head_;
        while (temp != tail_)
        {
            if (temp->prioryty > input->prioryty && temp->next->prioryty <= input->prioryty)
            {
                input->next = temp->next;
                temp->next = input;
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
        if (temp == tail_) {
            tail_->next = input;
            tail_ = tail_->next;
        }
    }
}


template<typename T>
void Queue<T>::removeTill(int mark)
{
    if (!head_) { throw std::logic_error("Queue is empty"); }

    node_t* temp = head_;

    if (head_->prioryty <= mark)
    {
        head_ = tail_ = nullptr;
        delete temp;
        std::cout << "Queue has been emptened\n";
    }
    else
    {
        while (temp != tail_)
        {
            if (temp->next->prioryty > mark) { temp = temp->next; }
            else
            {
                delete temp->next;
                tail_ = temp;
                tail_->next = nullptr;
            }
        }
    }
}

#endif //_TASK5_QUEUE_H

template<typename T>
std::ostream& operator<<(std::ostream& out, const Queue<T>& aQueue) {
    aQueue.print(out);
    return out;
}

