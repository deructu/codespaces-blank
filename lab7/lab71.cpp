#include <iostream>
#include <vector>
#include <cmath> 

using namespace std;

class ArrayContainer {
private:
    vector<double> array;

public:
    
    ArrayContainer(const vector<double>& arr) : array(arr) {}

    
    double getMaxElement() const {
        if (array.empty()) {
            throw runtime_error("M is not full");
        }
        double maxElement = array[0];
        for (double element : array) {
            if (element > maxElement) {
                maxElement = element;
            }
        }
        return maxElement;
    }

    
    double getSumUntilLastPositive() const {
        double sum = 0;
        int lastPositiveIndex = -1;
        for (size_t i = 0; i < array.size(); ++i) {
            if (array[i] > 0) {
                lastPositiveIndex = i;
            }
        }
        if (lastPositiveIndex == -1) {
            return 0; 
        }
        for (int i = 0; i < lastPositiveIndex; ++i) {
            sum += array[i];
        }
        return sum;
    }

    
    void transformArray(double a, double b) {
        vector<double> newArray;
        for (double element : array) {
            if (abs(element) < a || abs(element) > b) {
                newArray.push_back(element);
            }
        }
        while (newArray.size() < array.size()) {
            newArray.push_back(0);
        }
        array = newArray;
    }

    
    void printArray() const {
        for (double element : array) {
            cout << element << " ";
        }
        cout << std::endl;
    }
};

int main() {
    std::vector<double> data = { 1.5, -2.3, 3.1, 4.0, -5.2, 6.3, 2.5, -1.1, 7.4 };
    ArrayContainer container(data);

    
    double maxElement = container.getMaxElement();
    cout << "Max element: " << maxElement << endl;

    
    double sumUntilLastPositive = container.getSumUntilLastPositive();
    cout << "Sum to last plus element: " << sumUntilLastPositive << endl;

    
    container.transformArray(1.0, 3.0);
    cout << "Reverse massive: ";
    container.printArray();

    return 0;
}