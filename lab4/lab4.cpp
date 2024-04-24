#include <iostream>
#include <string>
using namespace std;

class Animal {

private:
int x,y,z;

public:
	Animal(int other_x, int other_y, int other_z) : x(other_x), y(other_y), z(other_z) {}
	
	int getX() const { return x; }

	int getY() const { return y; }

	int getZ() const { return z; }

	void Move() {
		x++;
		y++;
		z++;
	}
};

class Lion :  public Animal {

private:
	int age;
	int weight;
	string sex;
public:
	Lion(int other_x, int other_y, int other_z, int age_val, int weight_val, const string& sex_val)
		: Animal(other_x, other_y, other_z), age(age_val), weight(weight_val), sex(sex_val) {}
	
	
	int GetAge() const { return age; }
	int GetWeight() const { return weight; }
	string GetSex() const { return sex; }

	void Jump() {
		if (weight >= 150) {
			cout << "Lion can`t jump:( " << '\n';
		}
		else
		{
			cout << "The lion jumped " << '\n';
		}
	}
	void Voice() {
		if (age <= 50) {
			cout << "Roaaaaarrrrr!!!!! " << '\n';
		}
		else
		{
			cout << "Lion can`t make ROARR, because he is very old:(((( " << '\n';
		}
		
	}
	
};

int main()
{
	// Тут передаємо координати, вагу та стать тварини
	Lion lion_instance(10, 20, 30, 5, 120, "Female");

	
	cout << "X:" << lion_instance.getX() << ' ' << "Y:" << lion_instance.getY() << ' ' << "Z:" << lion_instance.getZ() << endl;
	cout << "Age: " << lion_instance.GetAge() << " Years" << endl;
	cout << "Weight: " << lion_instance.GetWeight() << " KG" << endl;
	cout << "Sex: " << lion_instance.GetSex() << endl;

	lion_instance.Jump();
	lion_instance.Voice();

	return 0;
}