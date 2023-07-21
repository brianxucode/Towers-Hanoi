
// ITP 365 Fall 2021
// HW03 – Towers of Hanoi
// Name: Brian Xu
// Email: brianjxu@usc.edu
// Platform: Mac

#pragma once

// TODO: Your code goes here
// At the minimum, include the following

#include <vector>
#include "disk.h"
#include "peg.h"
#include "gwindow.h"

int promptForDisks();
void promptForPegs(int&, int&);
int promptForPause();
void promptForWindowSize(int&, int&);
void draw(GWindow&, std::vector<Peg>&, int);
void moveDisk(GWindow&, std::vector<Peg>&, int, int, int);
void towerSolve(GWindow&, std::vector<Peg>&, int, int, int, int, int);

const int MINSCREENWIDTH = 800;
const int MINSCREENHEIGHT = 600;
const int MAXSCREENWIDTH = 4096;
const int MAXSCREENHEIGHT = 2160;
const int MINDISKS = 2;
const int MAXDISKS = 10;
const int NUMPEGS = 3;
const int MAXPAUSELEN = 1000000;
