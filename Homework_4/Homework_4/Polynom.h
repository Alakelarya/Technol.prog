#pragma once
#ifndef Polynom_H
#define Polynom_H
#include <iostream>
#include <vector>

class Polynom {
public:
	Polynom();
	Polynom(double extent,const std::vector<double>&);
	~Polynom() = default;
	double getCoef(int i) const;
	double result(int x) const;

	friend std::ostream& operator<<(std::ostream& stream, const Polynom& polynom);
	friend  Polynom operator+(const Polynom& first, const Polynom& second);
	friend  Polynom operator-(const Polynom& first, const Polynom& second);
	friend  Polynom operator*(const Polynom& first, const Polynom& second);

private:
	int extent_;
	std::vector<double> coef_;
};

#endif //Polynom_H