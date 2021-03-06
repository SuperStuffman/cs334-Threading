// Bach Nguyen
// OS Spring 2018

#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <math.h>       /* sqrt */
using namespace std;
#define INTERVAL 10000
template <typename T>
struct Point{
    T x;
    T y;
};

typedef struct{
    Point<int> center;
    int r;
}Circle;

typedef struct{
    Point<int> tl;
    Point<int> br;
}Square;


double randomDouble(double min, double max)
{
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

double calculatePI()
{
    // Define a circle
    Circle _circle;
    Square _square;
    
    // (0,0), r = 1
    _circle.center.x=0;
    _circle.center.y=0;
    _circle.r=1;
    // Base of the relationship between the circle in the square
    _square.tl.x=_circle.center.x-_circle.r;
    _square.tl.y=_circle.center.y+_circle.r;
    
    _square.br.x=_circle.center.x+_circle.r;
    _square.br.y=_circle.center.y-_circle.r;
    
    /*Find the random point in the circle under
     2 conditions
     tl.x <= _rand_point.x <= br.x
     br.y <= _rand_point.y <= tl.y
     */
    Point<double> _rand_point;
    cout << "Circle("<< _circle.center.x << "," << _circle.center.y << "), R=" << _circle.r << endl;
    cout << "Square TL("<< _square.tl.x << "," << _square.tl.y << ")"<<", BL("<< _square.br.x << "," << _square.br.y << ")" << endl<<endl;
    
    
    double PI=0;
    
    
    //Find all the points in the circle and count how many points in the square
    int count_circle_points = 0, count_square_points = 0;
    for (double i = 0; i < INTERVAL; i++)
    {
        _rand_point.x = randomDouble(_square.tl.x,_square.br.x);
        _rand_point.y = randomDouble(_square.br.y,_square.tl.y);
        double check_inside_circle;
        check_inside_circle=_rand_point.x*_rand_point.x + _rand_point.y*_rand_point.y;
    
        if (check_inside_circle <= 1)
        {
            count_circle_points++;
        }
        
        count_square_points++;
        PI = double(4 * count_circle_points) / count_square_points;
        //cout <<"["<<check_inside_circle<<"]"<<"("<<_rand_point.x <<"," <<_rand_point.y<<")" << count_square_points
        // << " " << count_square_points << " - " << PI << endl << endl;
        // getchar();
        
    }
    return PI;
}

int main()
{
    double pi=calculatePI();
    cout << "Estimation of Pi = " << pi;
    return 0;
}

