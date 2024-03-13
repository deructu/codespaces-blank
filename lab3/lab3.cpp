#include "VECTORS.h"
#include<iostream>

using namespace std;

int main() {

// Вектор 1
	VECTORS first_vector;

// Вектор 2
	VECTORS second_vector;

//Зчитування першого вектора
	cout << "Enter cordinates for first vector: ";
	first_vector.read();
	cout << '\n';

//Зчитування другого вектора
	cout << "Enter cordinates for second vector: ";
	second_vector.read();
	cout << '\n';

// Виведення векторів
	first_vector.rer(second_vector);


// Довжина першого вектора
	cout << "Length of the firs vector = " << first_vector.length() << '\n';

// Довжина другого вектора
	cout << "Length of the second vector = " << second_vector.length() << '\n';
	

// Сумав векторів
	cout << "Sum of vectors = " << first_vector.sum_v(second_vector) << '\n';
	
	
// Різниця векторів
	cout << "Difference of vectors = " <<  first_vector.def_v(second_vector) << '\n';
	
// Скалярний добуток векторів
	cout  << "Scalar product = " << first_vector.scal_v(second_vector) << '\n';

// Косинус кута між векторами
	cout << "The cosinuse of the angle between the vectors =  " << first_vector.cos(second_vector)<<'\n';
	
}