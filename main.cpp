
// ITP 365 Fall 2021
// HW03 – Towers of Hanoi
// Name: Brian Xu
// Email: brianjxu@usc.edu
// Platform: Mac

#include "towers.h"
#include "gwindow.h"
#include <random>
using namespace std;

int main(int argc, const char* argv[])
{
    //setting up data variables
    //getting how many disks to create
    int numOfDisks = promptForDisks();
    //getting where puzzle starts and where it ends
    int startPegNumber;
    int endPegNumber;
    int tempPegNumber;
    promptForPegs(startPegNumber, endPegNumber);
    
    //determing what the tempPegNumber is
    if ((startPegNumber == 1 && endPegNumber == 2) || (startPegNumber == 2 && endPegNumber == 1)){
        tempPegNumber = 3;
    }
    else if ((startPegNumber == 1 && endPegNumber == 3) ||           (startPegNumber == 3 && endPegNumber == 1)){
        tempPegNumber = 2;
    }
    else if ((startPegNumber == 2 && endPegNumber == 3) ||           (startPegNumber == 3 && endPegNumber == 2)){
        tempPegNumber = 1;
    }
    
    //getting pauseAmount
    int pauseAmount = promptForPause();
    //getting windowSize
    int xWindowSize;
    int yWindowSize;
    promptForWindowSize(xWindowSize, yWindowSize);
    //a vector to hold color strings for discs to construct from
    vector<string>colorStrings;
    colorStrings.push_back("RED");
    colorStrings.push_back("GREEN");
    colorStrings.push_back("CYAN");
    colorStrings.push_back("BLUE");
    colorStrings.push_back("ORANGE");
    colorStrings.push_back("PINK");
    colorStrings.push_back("YELLOW");
    colorStrings.push_back("GRAY");
    colorStrings.push_back("BLACK");
    colorStrings.push_back("MAGENTA");
    
	
    //creating the window,pegs,and discs from inputted info
    GWindow canvas (xWindowSize, yWindowSize);
    
    //creating the pegVector
    vector <Peg> pegVector;
    Peg peg1 = Peg(100, yWindowSize-50, 20, yWindowSize-100);
    Peg peg2 = Peg(xWindowSize/2, yWindowSize-50, 20, yWindowSize-100);
    Peg peg3 = Peg(xWindowSize-100, yWindowSize-50, 20, yWindowSize-100);
    pegVector.push_back(peg1);
    pegVector.push_back(peg2);
    pegVector.push_back(peg3);
    
    
    //creating the discs, this for loop creating the number of disks needed
    for (int i=0; i<numOfDisks; i++){
        Disk newDisk = Disk(6969, 6969, (numOfDisks-i)*30.5, 100, colorStrings[i]);
        //this step is when add the new created disk to the peg inside the pegVector
        pegVector[startPegNumber-1].addDisk(newDisk);
    }
    
    // TODO: call the appropriate functions to run the Tower of Hanoi
    //first "draw" out the canvas to see initial state
    draw(canvas, pegVector, pauseAmount);
    
    towerSolve(canvas, pegVector, pauseAmount, numOfDisks, startPegNumber, endPegNumber, tempPegNumber);
    
    
    //moveDisk(canvas, pegVector, pauseAmount, startPegNumber, endPegNumber);
    //ending test print out hold it
    //draw(canvas, pegVector, 1000000);
    
	return 0;
}






// TODO: write code to test your Disk class
// TODO: write code to test your Peg class
/*GWindow testCanvas(800,800);


Disk disk1 = Disk(100, 400, 200, 100, "GREEN");
Disk disk2 = Disk(300, 400, 100, 50, "RED");
Disk disk3 = Disk(500, 400, 300, 100, "BLUE");
Peg peg1 = Peg();

peg1.addDisk(disk1);
peg1.addDisk(disk2);
peg1.addDisk(disk3);

peg1.draw(testCanvas);



Disk disk4 = Disk(100, 400, 100, 50, "GREEN");
Disk disk5 = Disk(300, 400, 30, 60, "RED");
Disk disk6 = Disk(500, 400, 50, 200, "BLUE");
Peg peg2 = Peg(200,600,50,500);

peg2.addDisk(disk4);
peg2.addDisk(disk5);
peg2.addDisk(disk6);

peg2.draw(testCanvas);



Disk disk7 = Disk(100, 400, 100, 200, "GREEN");
Disk disk8 = Disk(300, 400, 50, 30, "RED");
Disk disk9 = Disk(500, 400, 200, 100, "BLUE");
Peg peg3 = Peg(700,600,50,500);

peg3.addDisk(disk7);
peg3.addDisk(disk8);
peg3.addDisk(disk9);

peg3.draw(testCanvas);

pause(100000);
*/



