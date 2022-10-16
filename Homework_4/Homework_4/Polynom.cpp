#include "Polynom.h"
#include <cmath>
#include <vector>


Polynom::Polynom() : extent_(0), coef_(0) {
	//	coef_[0] = 0;
}


Polynom::Polynom(double extent, const std::vector<double>& coef) :
	extent_(extent),
	coef_(coef) {
}

double Polynom::getCoef(int i) const {
	return coef_[i];
}

double Polynom::result(int x) const {
	double result = 0;
	for (int i = 0; i <= extent_; i++) {
		result += (getCoef(i) * pow(x, i));
	}
	return result;
}


std::ostream& operator<<(std::ostream& stream, const Polynom& polynom) {
	for (int j = polynom.extent_; j >= 0; j--) {
		if (j == 0) {
			stream << (polynom.coef_[j] < 0 ? "" : "+") << polynom.coef_[j];
			continue;
		}
		if (polynom.coef_[j] == 0) {
			continue;
		}
		stream << (polynom.coef_[j] < 0 ? "" : "+") << polynom.coef_[j] << "x^" << j;
	}
	return stream;
}


Polynom operator+(const Polynom& first, const Polynom& second) {
	Polynom sum;
	int i;
	if (first.extent_ < second.extent_) {
		sum.extent_ = second.extent_;
		sum.coef_.resize(second.coef_.size());
		for (i = 0; i <= first.extent_; i++) {
			sum.coef_[i] = first.coef_[i] + second.coef_[i];
		}
		sum.coef_[i] = second.coef_[i];
	}
	else if(first.extent_ > second.extent_) {
		sum.extent_ = first.extent_;
		sum.coef_.resize(first.coef_.size());
		for (i = 0; i <= second.extent_; ++i) {
			sum.coef_[i] = first.coef_[i] + second.coef_[i];
		}
		sum.coef_[i] = first.coef_[i];
	}
	else {
		sum.extent_ = first.extent_;
		sum.coef_.resize(first.coef_.size());
		for (i = 0; i <= second.extent_; ++i) {
			sum.coef_[i] = first.coef_[i] + second.coef_[i];
		}
	}
	return sum;
}
Polynom operator-(const Polynom& first, const Polynom& second) {
	Polynom sub;
	int i;
	if (first.extent_ < second.extent_) {
		sub.extent_ = second.extent_;
		sub.coef_.resize(second.coef_.size());
		for (i = 0; i <= first.extent_; i++) {
			sub.coef_[i] = first.coef_[i] - second.coef_[i];
		}
		sub.coef_[i] = second.coef_[i];
	}
	else if (first.extent_ > second.extent_) {
		sub.extent_ = first.extent_;
		sub.coef_.resize(first.coef_.size());
		for (i = 0; i <= second.extent_; ++i) {
			sub.coef_[i] = first.coef_[i] - second.coef_[i];
		}
		sub.coef_[i] = first.coef_[i];
	}
	else {
		sub.extent_ = first.extent_;
		sub.coef_.resize(first.coef_.size());
		for (i = 0; i <= second.extent_; ++i) {
			sub.coef_[i] = first.coef_[i] - second.coef_[i];
		}
	}
	return sub;
}

Polynom operator*(const Polynom& first, const Polynom& second) {
	Polynom multi;
	multi.extent_ = first.extent_ * second.extent_;
	multi.coef_.resize(second.coef_.size() * first.coef_.size());

	for (int i = 0; i <= first.extent_; ++i)
		for (int j = 0; j <= second.extent_; ++j) {
			multi.coef_[i + j] += first.coef_[i] * second.coef_[j];
		}
	return multi;

}