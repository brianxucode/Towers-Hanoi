
// ITP 365 Fall 2021
// HW03 – Towers of Hanoi
// Name: Brian Xu
// Email: brianjxu@usc.edu
// Platform: Mac

#pragma once

// TODO: Your code goes here
// At the minimum, include the following

#include <iostream>
#include <string>
#include "gwindow.h"


class Disk
{
public:
	
    //default constructor stub
    Disk();
    //constructor for just int values stub
    Disk(int, int, int, int);
    //constructor for int values + color value stub
    Disk(int, int, int, int, std::string);

	//stub for draw the actual rectangle stub, this takes in a GWindow object passed in reference in main
    void draw(GWindow& gw);

    //setter functions
	void setX(int);
	void setY(int);

    //getter functions
	int getHeight();


//private member variables
private:
	int mX;
	int mY;
	int mW;
	int mH;
	std::string mColor;
};
