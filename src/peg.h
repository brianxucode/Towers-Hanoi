
// ITP 365 Fall 2021
// HW03 – Towers of Hanoi
// Name: Brian Xu
// Email: brianjxu@usc.edu
// Platform: Mac

#pragma once

// TODO: Your code goes here
// At the minimum, include the following

#include <string>
#include <vector>
#include "gwindow.h"
#include "disk.h"

class Peg
{
public:
	Peg();
	Peg(int, int, int, int);

	void draw(GWindow&);
	void addDisk(Disk);
	Disk removeDisk();
private:
	int mX;
	int mY;
	int mW;
	int mH;
	int xCenter;
	int curTop;

	std::string color;

	std::vector<Disk> diskVect;
};
