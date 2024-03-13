#pragma once
#include <iostream>
#include <cmath>
class VECTORS
{
private:
// Координати векторів
	int x, y, z; 
	
public:

// Зщитування координат векторів
	void read() {
		std::cin >> x >> y >> z;
	}
// Виведення векторів
	void rer(const VECTORS& other) {
		std::cout << "First vector: " << "( " << x << " ; " << y << " ; " << z << " )" << '\n';
		std::cout << "Second vector: " << "( " << other.x << " ; " << other.y << " ; " << other.z << " )" << '\n';
	}
// Довжина векторів
	 double length() {
		double length_v;
		length_v = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
		return length_v;
	}

// Сума векторів
	double sum_v(VECTORS& other)  {
		return abs(length() + other.length());
	}
	
// Різниця векторів
	double def_v(VECTORS& other) {
		return abs(length() - other.length());
	}

// Скалярний добуток
	double scal_v(VECTORS& other) {
		return x * other.x + y * other.y + z * other.z;
	}

// Косинус
	double cos(VECTORS& other) {
		double scal = scal_v(other);
		double mod_v1 = length();
		double mod_v2 = other.length();
		return scal / (mod_v1 * mod_v2);
	}
};