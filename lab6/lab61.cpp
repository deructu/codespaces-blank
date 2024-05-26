#include <iostream>

using namespace std;

class Vector2D {
private:
    double x;
    double y;

public:
    
    Vector2D() : x(0.0), y(0.0) {}

    
    Vector2D(double x_val, double y_val) : x(x_val), y(y_val) {}

   
    Vector2D(const Vector2D& other) : x(other.x), y(other.y) {}

    
    Vector2D& operator=(const Vector2D& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

    
    bool operator==(const Vector2D& other) const {
        return (x == other.x && y == other.y);
    }

    
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    
    Vector2D operator*(double scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    
    void print() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};


int main() {
    
    Vector2D v1(2.0, 3.0);
    Vector2D v2(1.0, -1.0);

    
    Vector2D sum = v1 + v2;
    cout << "Sum: ";
    sum.print();

    
    double scalar = 2.5;
    Vector2D scaled = v1 * scalar;
    cout << "Scaled: ";
    scaled.print();

    
    if (v1 == v2) {
        cout << "Vectors are equal" << endl;
    }
    else {
        cout << "Vectors are not equal" << endl;
    }

    return 0;
}