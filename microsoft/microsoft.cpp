#include<iostream>
using namespace std;
//question 1 
bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closestx=max(x1,min(xCenter,x2));
        int closesty=max(y1,min(yCenter,y2));
        int sq_distance=(xCenter-closestx)*(xCenter-closestx) + (yCenter-closesty)*(yCenter-closesty);
        return sq_distance<=(radius*radius);
    }

//question 2


int main(){
    cout<<"solving question for company one";
    return 0;
}