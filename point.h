//============================================================================
// Name        : point.h
// Author      : Emma Redfoot
// Version     :
// Copyright   : Your copyright notice
// Description : Point and PointArray Classes
//============================================================================

#include <iostream>
using namespace std;

//Add function prototypes
class Point { //Create a class with two private doubles named x and y
private:
    double x, y; //two private doubles

public:
    Point(double l=0.0, double m=0.0) : x(l), y(m) {}//overloaded constructor
    // implement a single constructor (unlike the two constructors we learned in class) that,
    //if called with 0 arguments, initializes a point to the origin, but if called with two
    //arguments x and y, creates a point located at x and y

    double getX(); //get the x coordinate

    double getY(); //get the y coordinate

    void setX(double new_x); // set the x coordinate

    void setY(double new_y); //set the y coordinate
};


class PointArray{ //Allows dynamic resizing of the array. Tracks its own length.

private: //Create the class PointArray with two private members

    Point* points; //A Pointer to the start of an array of Points

    int size; //An int that stores the size (length) of the array

    void resize(int n); //9. Add the PointArray::resize(int n) method as specified above to your PointArray class. As this is only being used internally, it is fitting for it to be in the private

public:
    PointArray(); //Implement the default constructor (a constructor with no arguments)

    PointArray(const Point points[], const int size); //implement a constructor that takes a Point array called points and an int a called size as its arguments

    PointArray(const PointArray &pv); //Implement a copy constructor that creates a copy of a given PointArray

    ~PointArray(); //Implement a constructor that deletes the internal array of the PointArray

    void push_back(Point &p); //Add a point to the end of the array

    void insert(int position, Point &p); //Insert a Point at some arbitrary position(subscript) of the array, shifting the elements to the right

    void remove(int pos); //Remove the point at some arbitrary position(subscript) of the array, shifting the remaining elements to the left

    int getSize(); //Get the size of the array

    void clear(); //Remove everything from the array and set its size to 0

    Point* get(const int pos); //Get a pointer to the array at some arbitrary position
};
