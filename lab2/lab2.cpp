#include<cmath>
#include <iostream>
using namespace std;

void calculate(int, int, int, int, int, int, int, int, double&, double&);//функція для обчислення периметру і площі

int main()
{
    double S = 1.0;
    double P = 1.0;
    
    // Введення вершин чотирикутника

    int x1,y1;//вершина A
    cout << "Enter Coordinates for x1, y1: ";
    cin >> x1 >> y1;

    int x2, y2;//вершина B
    cout << "Enter Coordinates for x2, y2: ";
    cin >> x2 >> y2;

    int x3, y3;//вершина C
    cout << "Enter Coordinates for x3, y3: ";
    cin >> x3>> y3;

    int x4, y4;//вершина D
    cout << "Enter Coordinates for x4, y4: " ;
    cin >> x4 >> y4;
    cout << '\n';

    calculate( x1, y1, x2, y2, x3, y3, x4, y4, S, P);
    
    cout << "P= "<< P  << '\n';
    
    cout << "S= "<< S << '\n';
    
}
void calculate(int x1,int y1, int x2, int y2, int x3, int y3, int x4, int y4, double& S,double& P)
{ 
    // Знаходимо сторони чотирикутника
    double AB;
    AB = pow(x2 - x1, 2) + pow(y2 - y1, 2);

    double BC;
    BC = pow(x3 - x2, 2) + pow(y3 - y2, 2);

    double CD;
    CD = pow(x4 - x3, 2) + pow(y4 - y3, 2);

    double DA;
    DA = pow(x4 - x1, 2) + pow(y4 - y1, 2);

    // Периметр чотирикутника
    //double P;
    P = sqrt(AB) + sqrt(BC) + sqrt(CD) + sqrt(DA);
    //cout << "P = " << P << '\n';

    // Знаходимо діагоналі чотирикутника
    double AC;
    AC = pow(x3 - x1, 2) + pow(y3 - y1, 2);

    double BD;
    BD = pow(x2 - x4, 2) + pow(y2 - y4, 2);
     
    // vec dob AC =av, BD = bv
    double ax;
    ax = x3-x1;
    
    double ay;
    ay = y3-y1;
    

    double bx;
    bx = x2 - x4;
    
    double by;
    by = y4 - y2;
    
    double dob_v;
    dob_v = ax * bx + ay * by;
    
    double mod_ax;
    mod_ax = sqrt((ax * ax) + (ay * ay));
    
    double mod_bx;
    mod_bx = sqrt((bx * bx) + (by * by));
    
    double dob_mod;
    dob_mod = mod_ax * mod_bx;
    double cos1;
    cos1 = dob_v / dob_mod;
    double acos1;
    acos1 = acos(cos1);
    
    //Знаходження площі

    //double S;

    S = 0.5 * (sqrt(BD) * sqrt(AC) * acos1);
    //cout << "S = " << S;;
      
}