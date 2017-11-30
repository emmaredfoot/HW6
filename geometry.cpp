//============================================================================
// Name        : HW_6_ER.cpp
// Author      : Emma Redfoot
// Version     :
// Copyright   : Your copyright notice
// Description : Polygon
//============================================================================

#include <iostream>
#include <cmath>
#include </Users/emmaredfoot/eclipse-workspace/Homework/HW6/geometry.h>
using namespace std;

double Point::getX(){ //get the x coordinate
    return x;
}
double Point::getY(){ //get the y coordinate
    return y;
}
void Point::setX(double new_x){
    x = new_x;
}
void Point::setY(double new_y){
    y = new_y;
}
int PointArray::getSize(){
    return size;
}

PointArray::PointArray(){ //Default constructor

    cout << "here" << endl;
    size = 0;
    points = new Point[0];

}

//Implement a constructor that takes a Point array called points and an int
//called size as its arguments. It should initialize a PointArray with the specified size
//copying the values from points
PointArray::PointArray(const Point p[], const int length)
{
    size = length;
    cout << "s= " << size << endl;
    //new operator is used to allocate memory
    points = new Point[size];//You will need to dynamically allocate the PointArray's internal array to the specified size (ie, used the new operator)

    for (int i = 0; i < size; i++)
    {
        points[i] = p[i];
    }
}

PointArray::PointArray(const PointArray &pcopy) //Finally, implement a constructor that creates a copy of a given PointArray (a copy constructor)
{
    size = pcopy.size;
    points = new Point[size];
    for(int i = 0; i < size; i++) {
        points[i] = pcopy.points[i];
        cout << i <<endl;
    }
}

PointArray::~PointArray() //Define a destructor that deletes the internal array of the PointArray
{
    delete[] points;
}

void PointArray::resize(int n) //Create a method resize that allocates a new array of size n, copies the first
//min(previous array size, n) existing elements into it, and deallocates the old array
{
    Point* newPoints = new Point[n];

    // copy existing elements into a new array
    //Use the conditional operator to determine if the previous size or n is bigger
    for (int i = 0; i < n; i++){
        newPoints[i] = points[i];
    }

    // deallocate old array
    delete[] points;

    //make sure that the size has been appropriately adjusted and that newPoints is freed up to be redefined
    points = newPoints;
    size = n;
}

void PointArray::push_back(Point &p) //Add a point to the end of the array
{
    cout << "size " << size << endl;
    resize(size + 1); //make the length of the array one more than it previously was.
    //The n value in resize will now be one greater than the previous size
    points[size -1] = p; //add the new point p to the end of the array
}

void PointArray::clear()
{
    resize(0); //Passes in 0 to the resize function
}

void PointArray::remove(int position)
{
//Make sure that the position being called is within the range of the array
if(position >=0 && position < size){
    // shift elements from position onwards
    for (int i = position; i < size - 2; i++)
        points[i] = points[i+1];

    // resize array
    resize(size - 1);
    }
}

//Insert a Point at some arbitrary position (subscript) of the array
//shifting the remaining elements to the left

void PointArray::insert(int position, Point &p)
{
    // make sure there is room for one more element in our array
    resize(size + 1);
    cout << "new = " << size <<endl;

    //Shift all of the elements that are to the right of the position we want
    //one over to the right, counting back from the end
    for (int i = size - 1; i > position; i--)
        points[i] = points[i-1];

    // insert the point into the desired position in the array points
    points[position] = p;
}
Point *PointArray::get(const int position) {
    cout << points << endl;
    if (position > 0 && position < size){ //Make sure that the position passed is within the constraints of the range of the array
        return(points + position);
    }
    else{
        return NULL;
    }
}
void instance_points () {
    //Shows that an instance of a point can be initialized with both no values and two values
    Point p1 = Point();
    Point p2 = Point(5, 25);

    //Print out the two X points to show that they have been initialized
    cout << "point 1= "<< p1.getX() << endl;
    cout << "point 2= " << p2.getX() << endl;

    //Set the x and y points for point 1 from (0,0) to (85,95)
    p1.setX(85);
    p1.setY(95);

    //Print out the two points after they have been reset
    cout << "point 1 X= " << p1.getX() << endl;
    cout << "point 1 Y= " << p1.getY() << endl;

}

//Implement a constructor that creates a polygon using the points in an
//existing PointArray that is passed as an argument.
Polygon::Polygon(const PointArray &parray) : points(points) {
    static int tracker;
    tracker++;
}

//Implement a constructor  that creates a Polygon from an array of points and the length of the array.
//Use member initializer syntax to initialize the internal PointArray object of the Polygon.
Polygon::Polygon(Point parray[], int tracker) : points(parray, tracker) {
    tracker++;
}

//ll lower left

Point constructorPoints[4];

Point* updateConstructorPoints(const Point &p1, const Point &p2, const Point &p3, const Point &p4 = Point(0,0)){
    constructorPoints[0]=p1;
    constructorPoints[1]=p2;
    constructorPoints[2]=p3;
    constructorPoints[3]=p4;
    return constructorPoints;
}

//Create a rectangle given two points
Rectangle::Rectangle(Point &ll, Point &ur):
Polygon(updateConstructorPoints(ll, Point(ll.getX(), ur.getY()), ur, Point(ur.getX(), ll.getY())), 4) {}

//Create a rectangle given four points
Rectangle::Rectangle(const int x1, const int y1, const int x2, const int y2):
Polygon(updateConstructorPoints(Point(x1, y1), Point(x1, y2), Point(x2, y1), Point(x2, y2)), 4) {}

//override the Polygon area function for a rectangle
//if I am going to use the virtual class from Polygon, I will need to find a way to pass in the points
//without including them in the function header
double Rectangle::area(){



    double width=0;
    double height = 0;
    double area = 0;
    //cout << points.getPoints()[0] << endl;
    // double diff = ur.getX()-ll.getX();
    // width = abs (diff);
    // cout << "w= " << width << endl;
    // height = abs(ur.getY()-ll.getY());
    // area = width*height;
    return(area);
}

//Write a subclass called triangle that models a Triangle
Triangle::Triangle(Point &a, Point &b, Point &c) :
Polygon(updateConstructorPoints(a,b,c), 3) {}

//write a function that will find the distance between two points
double Point::distance_Points(Point &i1, Point &i2) {
    //Find the length between two points, the instance point, and some other point
    double diff_x = i1.getX()-i2.getX();
    double x = abs (diff_x);
    double diff_y = i1.getY()-i2.getY();
    double y = abs (diff_y);
    return sqrt(x*x+y*y);
}

//Calculate the area using Heron's formula
double Triangle::area() {

    // //get the lengths of each of the sides
    // double length_1 = a.distance_Points(a,b);
    // double length_2 = b.distance_Points(b,c);
    // double length_3 = c.distance_Points(c,a);
    // double s = length_1+2*length_2+length_3;
    // cout << s << endl;
    return(0);
}

//Write a function that prints the area of the polygon and prints the (x,y) ciirduates of all its points
void printAttributes(Polygon *P){
    //Try using the this -> ability.  If I call the this pointer, I can access the address of
    //the object I am calling the pointer on.
    //Print the x,y of each of the points
    cout << "printAttributes called" << endl;


}

int main() {

    //Homework 6 additions. Triangle points
    Point a = Point(1,1);
    Point b = Point(2,3);
    Point c = Point(4,1);

    Triangle T = Triangle(a, b, c);

    printAttributes(&T);

    //Rectangle points with the upper right and lower left
    Point ll = Point(0,0);
    Point ur = Point(2,2);
    Rectangle R1 = Rectangle(ll, ur);

    //Rectangle points - four points
    Rectangle R2 = Rectangle(0, 0, 5, 5);





    //Test out my classes and methods, especially ensuring that the
    //default point constructor works
    //instance_points creates and augments two points, testing the default and 2 parameter constructors
    instance_points();


    //Work with PointArray to ensure that it works
    //PointArray with the default constructor
    PointArray emptyArray = PointArray();
    cout << "Empty Array: " << emptyArray.getSize() << endl;

    //PointArray with point and a double
    Point example2[2] = {Point(1.3, 2.5), Point(2.3, 3.4)};
    PointArray secondArray = PointArray(example2, 2);

    //Add a point to the end of the array
    Point pushplace = Point(2,3);
    secondArray.push_back(pushplace);
    cout << "size of secondArray: " << secondArray.getSize() << endl;
    //
    //Insert a Point at some arbitrary position of the array
    secondArray.insert(1, pushplace);

    //Get the size of the array
    cout << "Array Size: " << secondArray.getSize() << endl;

    //Get a Pointer to the element at some arbitrary position in the array, where positions
    //start at 0 as with arrays
    cout << "2nd Position:" << secondArray.get(2) << endl; //Prints out pointer to the second position

    //Remove everything from the array and set its size to 0
    secondArray.clear();

    cout << "Array Size after clearing: " << secondArray.getSize() << endl;

    return 0;
}
