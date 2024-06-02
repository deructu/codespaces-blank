#include <iostream>
#include <queue>
#include <string>

using namespace std;


class Davach {
public:
    Davach(double current_value, double min_value, double max_value, string sensor_type, string alarm_signal)
        : current_value(current_value), min_value(min_value), max_value(max_value), sensor_type(sensor_type), alarm_signal(alarm_signal) {}

    double getCurrentValue() const { return current_value; }
    double getMinValue() const { return min_value; }
    double getMaxValue() const { return max_value; }
    string getSensorType() const { return sensor_type; }
    string getAlarmSignal() const { return alarm_signal; }

    
    void setCurrentValue(double value) { current_value = value; }

private:
    double current_value;
    double min_value;
    double max_value;
    string sensor_type;
    string alarm_signal;
};

int main() {
    
    
    queue<Davach> davachQueue;

    
    davachQueue.push(Davach(25, 20, 30, "t", "ALARM1"));
    davachQueue.push(Davach(7, 5, 10, "p", "ALARM2"));
    davachQueue.push(Davach(8.5, 7, 9.5, "pH", "ALARM3"));

   
    Davach removedDavach = davachQueue.front();
    davachQueue.pop();
    cout << "Видалено з черги: " << removedDavach.getSensorType() << endl;

    
    cout << "Перший елемент черги: " << davachQueue.front().getSensorType() << endl;

    
    davachQueue.front().setCurrentValue(26);
    cout << "Нове значення першого елемента черги: " << davachQueue.front().getCurrentValue() << endl;

    
    davachQueue.push(Davach(9, 7, 12, "i", "ALARM4"));

    
    cout << "Усі об'єкти черги:" << endl;
    while (!davachQueue.empty()) {
        Davach davach = davachQueue.front();
        cout << "Тип: " << davach.getSensorType() << ", Поточне значення: " << davach.getCurrentValue() << endl;
        davachQueue.pop();
    }

    return 0;
}