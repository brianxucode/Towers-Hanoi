
// ITP 365 Fall 2021
// HW03 – Towers of Hanoi
// Name: Brian Xu
// Email: brianjxu@usc.edu
// Platform: Mac

#include "disk.h"

using namespace std;
//default constructor
Disk::Disk(){
    //in all cases, we are referring to mX and mY as if they are the bottom center of the pixel rectangle
    mX = 0;
    mY = 0;
    mW = 0;
    mH = 0;
    mColor = "";
}

//parameterized constructor for no color inputted
Disk::Disk(int xInt1, int xInt2, int xInt3, int xInt4){
    //in all cases, we are referring to mX and mY as if they are the bottom center of the pixel rectangle
    mX = xInt1;
    mY = xInt2;
    mW = xInt3;
    mH = xInt4;
    mColor = "";
}

//parameterized constructor for color inputted
Disk::Disk(int xInt1, int xInt2, int xInt3, int xInt4, string xColor){
    mX = xInt1;
    mY = xInt2;
    mW = xInt3;
    mH = xInt4;
    mColor = xColor;
}

//draw function
void Disk::draw(GWindow& gW){
    //if no color provided, default is gray
    if (mColor == ""){
        gW.setColor("GRAY");
        gW.fillRect((mX - mW/2), (mY - mH), mW, mH);
    }
    //if color was provided
    else{
        gW.setColor(mColor);
        gW.fillRect((mX - mW/2), (mY - mH), mW, mH);
    }
}

//the key is this here
//so from these 2 functions we will get the exact x and y coordinate of where we want the bottom center of the object to be
void Disk:: setX(int xCoordinate){
    mX = xCoordinate;
}
void Disk:: setY(int yCoordinate){
    mY = yCoordinate;
}


//getHeight functiion
int Disk:: getHeight(){
    return mH;
}


