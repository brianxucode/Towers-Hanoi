
// ITP 365 Fall 2021
// HW03 – Towers of Hanoi
// Name: Brian Xu
// Email: brianjxu@usc.edu
// Platform: Mac

#include "peg.h"

//default constructor
Peg::Peg(){
    //in all cases, we are referring to mX and mY as if they are the bottom center of the pixel rectangle
    mX = 400;
    mY = 600;
    //thus when drawing the rectangle, we will account for this fact in the values inserted into the fillRect() function
    mW = 30;
    mH = 500;
    color = "black";
}

//parameterized constructor
Peg::Peg(int xInt1, int xInt2, int xInt3, int xInt4){
    //in all cases, we are referring to mX and mY as if they are the bottom center of the pixel rectangle
    mX = xInt1;
    mY = xInt2;
    mW = xInt3;
    mH = xInt4;
    color = "black";
}

//*FIX to do here adjust the mX and mY values accordingly once can see them on the gWindow canvas
//draw the peg into the gWindow canvas
void Peg::draw(GWindow& gW){
    gW.setColor(color);
    gW.fillRect((mX - mW/2), (mY - mH), mW, mH);
    
    //drawing on each disk onto the peg at the right spot
    int relationalY = mY;
    for (int i=0; i<diskVect.size(); i++){
        Disk diskStored = diskVect[i];
        //this centers the disk to be on same xaxis as the peg
        diskStored.setX(mX);
        
        //setting the new x and y coordinates of the disk
        //for 1st disk
        if (i==0){
            relationalY = mY;
            diskStored.setY(relationalY);
            relationalY = relationalY - diskStored.getHeight();
        }
        else{
            //subtracting the y of the new disk from this relationalY which used to determing the y of all future disks as well

            diskStored.setY(relationalY);
            relationalY = relationalY - diskStored.getHeight();
        }

        
        //drawing out the diskStored
        diskStored.draw(gW);
    }
}

//add a disk onto the Peg's diskVect
void Peg::addDisk(Disk xDisk){
    //this the most basic adding on, addressing the data structure itself
    diskVect.push_back(xDisk);
}


Disk Peg::removeDisk(){
    Disk diskToReturn = diskVect[diskVect.size()-1];
    diskVect.pop_back();
    
    return diskToReturn;
}
