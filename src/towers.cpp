
// ITP 365 Fall 2021
// HW03 – Towers of Hanoi
// Name: Brian Xu
// Email: brianjxu@usc.edu
// Platform: Mac

#include "towers.h"
#include "gwindow.h"

using namespace std;

//function to get how many disks
int promptForDisks(){
    bool catalyst = true;
    
    int numOfDisks;
    while (catalyst == true){
        cout << "Please enter number of disks to start with (2-10): " << endl;
        
        //check that userInput is an int
        try {
            cin >> numOfDisks;
            
            //check if userInput is between 2 and 10
            if (numOfDisks>= MINDISKS && numOfDisks <=MAXDISKS){
                catalyst = false;
                return numOfDisks;
            }
            else{
                cout << "invalid number please try again" << endl;
            }
        } catch (exception e) {
        cout << "an exception occured: that was probably not a number " << endl;
        }
    }
}

//function to get what the start and end peg numbers are
void promptForPegs(int& xstartPegNumber, int& xendPegNumber){
    //loop1 to get startPegNumber
    bool catalyst1 = true;
    int startPegNumber;
    
    while (catalyst1 == true){
        cout << "Enter a starting peg number: " << endl;
        
        //variable to store startPegNumber
        cin >> startPegNumber;
        while (cin.fail()){
            cout << "Error not a number. Try again: " << endl;
            //reclear the cin buffer
            cin.clear();
            cin.ignore(246,'\n');
            //reallow entry for startPegNumber
            cin >> startPegNumber;
        }
        
        //check to see that startPegNumber is 1,2,or 3
        if (startPegNumber == 1 || startPegNumber == 2 || startPegNumber == 3){
            xstartPegNumber = startPegNumber;
            catalyst1 = false;
        }
        else{
            cout << "Not a valid number. Must be 1,2,or 3. Try again." << endl;
        }
    }
    
    //loop2 to get endPegNumber
    bool catalyst2 = true;
    int endPegNumber;
    
    while (catalyst2 == true){
        cout << "Enter an ending peg number: " << endl;
        
        //variable to store startPegNumber
        cin >> endPegNumber;
        while (cin.fail()){
            cout << "Error not a number. Try again: " << endl;
            //reclear the cin buffer
            cin.clear();
            cin.ignore(246,'\n');
            //reallow entry for startPegNumber
            cin >> endPegNumber;
        }
        
        //check to see that startPegNumber is 1,2,or 3
        if (endPegNumber == startPegNumber){
            cout << "End peg number cant be start peg number. try again." << endl;
        }
        else if ((endPegNumber == 1 || endPegNumber == 2 || endPegNumber == 3)){
            xendPegNumber = endPegNumber;
            catalyst2 = false;
        }
        else{
            cout << "Not a valid number. Must be 1,2,or 3. Try again." << endl;
        }
    }
    
}

//funct to get how long to pause for
int promptForPause(){
    bool catalyst = true;
    int pauseNumber;
    
    while (catalyst == true){
        cout << "Enter a pause number (in milliseconds): " << endl;
        
        //variable to store pauseNumber
        cin >> pauseNumber;
        while (cin.fail()){
            cout << "Error not a number. Try again: " << endl;
            //reclear the cin buffer
            cin.clear();
            cin.ignore(246,'\n');
            //reallow entry for pauseNumber
            cin >> pauseNumber;
        }
        
        //check to see that pauseNumber is in valid range
        if (pauseNumber>=1 && pauseNumber<=1000000){
            catalyst = false;
            return pauseNumber;
        }
        else{
            cout << "Not a valid number. Must be between 1 and 1000000. Try again." << endl;
        }
    }
}

//funct to get how large the window size
void promptForWindowSize(int& xWindowSize, int& yWindowSize){
    //loop1 to get startPegNumber
    bool catalyst1 = true;
    int holderXSize;
    
    while (catalyst1 == true){
        cout << "Enter a window width size: " << endl;
        
        //variable to store startPegNumber
        cin >> holderXSize;
        while (cin.fail()){
            cout << "Error not a number. Try again: " << endl;
            //reclear the cin buffer
            cin.clear();
            cin.ignore(246,'\n');
            //reallow entry for startPegNumber
            cin >> holderXSize;
        }
        
        //check to see that startPegNumber is 1,2,or 3
        if (holderXSize>=MINSCREENWIDTH && holderXSize<=MAXSCREENWIDTH){
            xWindowSize = holderXSize;
            catalyst1 = false;
        }
        else{
            cout << "Not a valid number. Must be between 800 and 4096. try again." << endl;
        }
    }
    
    //loop2 to get endPegNumber
    bool catalyst2 = true;
    int holderYSize;
    
    while (catalyst2 == true){
        cout << "Enter a window height size: " << endl;
        
        //variable to store startPegNumber
        cin >> holderYSize;
        while (cin.fail()){
            cout << "Error not a number. Try again: " << endl;
            //reclear the cin buffer
            cin.clear();
            cin.ignore(246,'\n');
            //reallow entry for startPegNumber
            cin >> holderYSize;
        }
        
        //check to see that startPegNumber is 1,2,or 3
        if (holderYSize>=MINSCREENHEIGHT && holderYSize<=MAXSCREENHEIGHT){
            yWindowSize = holderYSize;
            catalyst2 = false;
        }
        else{
            cout << "Not a valid number. Must be between 600 and 2160. Try again." << endl;
        }
    }
}

//funct to draw the pegs vector (and subsequently the disks on it) onto the parsed in gWindow canvas
void draw(GWindow& xWindow, vector<Peg>& pegsVector, int pauseAmount){
    
    //clear the parsed in gWindow canvas
    xWindow.clear();
    
    //open up the pegs vector and draw all of the pegs onto the canvas
    for (int i=0; i<pegsVector.size(); i++){
        pegsVector[i].draw(xWindow);
    }
    
    //add in pauseAmount for subsequent animation
    pause(pauseAmount);
}

//this is the helper recursive function
void moveDisk(GWindow& xWindow, vector<Peg>&pegsVector, int pauseTime, int initialPegNumber, int destPegNumber){
    
    //removes and returns the disk from the startPeg, then adds it to the destPeg
    pegsVector[destPegNumber-1].addDisk(pegsVector[initialPegNumber-1].removeDisk());
    
    //then draws the new canvas again
    draw(xWindow, pegsVector, pauseTime);
}

//this is the main recursive function
//this is what will be called onetime in the main file
void towerSolve(GWindow& xWindow, vector<Peg>&pegsVector, int pauseTime, int numOfDisks, int startPegNumber, int endPegNumber, int tempPegNumber){
    
    //base case where only 1 left on the "startingPeg"
    if (numOfDisks == 1){
        //this the helper function that actually performs the move
        moveDisk(xWindow, pegsVector, pauseTime, startPegNumber, endPegNumber);
        return;
    }
    towerSolve(xWindow, pegsVector, pauseTime, numOfDisks-1, startPegNumber, tempPegNumber, endPegNumber);
    moveDisk(xWindow, pegsVector, pauseTime, startPegNumber, endPegNumber);
    towerSolve(xWindow, pegsVector, pauseTime, numOfDisks-1, tempPegNumber, endPegNumber, startPegNumber);
    
}
