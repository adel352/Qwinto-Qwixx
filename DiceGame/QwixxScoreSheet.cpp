/*
 * CSI 2772 - Jouer aux dés
 * Adel Araji - 7897476
 * Alexandre Prud'Homme - 7293804
 * Le 6 décembre 2017
 */

#include <stdio.h>
#include "QwixxScoreSheet.h"



/**
 Get vector elememnts in a row of a certain colour

 @param colour
 @return vector
 */
std::vector<int> QwixxScoreSheet::getVectorElementsInRow(Colour cl){
    std::vector<int> returnVector;
    
    if(cl == RED)
        returnVector = redRow.container;
    else if (cl == YELLOW)
        returnVector = yellowRow.container;
    
    return returnVector;
}

/**
 Get list elememnts in a row of a certain colour
 
 @param colour
 @return vector
 */
std::list<int> QwixxScoreSheet::getListElementsInRow(Colour cl){
    std::list<int> returnList;
    
    if(cl == BLUE)
        returnList = blueRow.container;
    else if (cl == GREEN)
        returnList = greenRow.container;
    
    return returnList;
}


/**
 Insert score in a certain row by giving colour and score

 @param score
 @param colour
 */
void QwixxScoreSheet::insertScoreInRow (int score, Colour cl){
    RollOfDice rd;
    Dice d = Dice(cl, score);
    rd.containerOfDice.push_back(d);
    
    if(cl == RED)
        redRow += rd;
    else if (cl == YELLOW)
        yellowRow += rd;
    else if (cl == BLUE)
        blueRow += rd;
    else if (cl == GREEN)
        greenRow += rd;
        
}


/**
 Incrémenter le nombre de faillites
 */
void QwixxScoreSheet::incrementFailedAttempts(){
    ScoreSheet::incrementFailedAttempts();
}

/**
    Validates if it is possible to add a roll in a certain row
 */
bool QwixxScoreSheet::validate(RollOfDice rd, Colour cl, int positionFromLeft) {
    //Condition : if a position is occupied, adding a value AFTER occupied values not before
    bool condition = true;
    
    bool conditionArray1 [11] = {false};
    bool conditionArray2 [11] = {false};
    bool conditionArray3 [11] = {false};
    bool conditionArray4 [11] = {false};
    
    for (std::vector<int>::const_iterator i =  redRow.container.begin(); i != redRow.container.end(); ++i){
        conditionArray1[*i-2] = true;
    }
    
    for (std::vector<int>::const_iterator i =  yellowRow.container.begin(); i != yellowRow.container.end(); ++i){
        conditionArray2[*i-2] = true;
    }
    
    for (std::list<int>::const_iterator i =  blueRow.container.begin(); i != blueRow.container.end(); ++i){
        conditionArray3[12-*i] = true;
    }
    
    for (std::list<int>::const_iterator i =  greenRow.container.begin(); i != greenRow.container.end(); ++i){
        conditionArray3[12-*i] = true;
    }
    
    
    //PositionFromLeft: is the number we're adding here
    //Add validate for occupied cell, go through the vectors and cell and make sure that they are 0
    if(cl == RED){
        for(int i = 0; i < 11; i++){
            if(conditionArray1[i] && (positionFromLeft - 2 <= i))
                condition = false;;//position is occupied
            
        }
        if(redRowLocked)
            condition = false;
    }else if (cl == YELLOW){
        for(int i = 0; i < 11; i++){
            if(conditionArray2[i] && (positionFromLeft - 2 <= i))
                condition = false;;//position is occupied
        }
        if(yellowRowLocked)
            condition = false;
    }else if (cl == GREEN){
        for(int i = 0; i < 11; i++){
            if(conditionArray3[i] && (12 - positionFromLeft <= i))
                condition = false;;//position is occupied
        }
        if(greenRowLocked)
            condition = false;
    }else if (cl == BLUE){
        for(int i = 0; i < 11; i++){
            if(conditionArray4[i] && (12 - positionFromLeft <= i))
                condition = false;;//position is occupied
        }
        if(blueRowLocked)
            condition = false;

    }
    
    return condition;
}


/**
    Returns the total score for Qwixx
 */
int QwixxScoreSheet::calcTotal(){
    
    //Getting the number of entries in each row
    int numOfEntriesRed = 0;
    int numOfEntriesYellow = 0;
    int numOfEntriesGreen = 0;
    int numOfEntriesBlue = 0;
    
    bool isFirstOrLastCheckedInRed = false;
    bool isFirstOrLastCheckedInYellow = false;
    bool isFirstOrLastCheckedInGreen = false;
    bool isFirstOrLastCheckedInBlue = false;
    
    for (std::vector<int>::const_iterator i =  redRow.container.begin(); i != redRow.container.end(); ++i){
        numOfEntriesRed++;
        if((*i == 0) || (*i == 10))
            isFirstOrLastCheckedInRed = true;
    }
    
    for (std::vector<int>::const_iterator i =  yellowRow.container.begin(); i != yellowRow.container.end(); ++i){
        numOfEntriesYellow++;
        if((*i == 0) || (*i == 10))
            isFirstOrLastCheckedInYellow = true;
    }
    
    for (std::list<int>::const_iterator i =  blueRow.container.begin(); i != blueRow.container.end(); ++i){
        numOfEntriesBlue++;
        if((*i == 0) || (*i == 10))
            isFirstOrLastCheckedInBlue = true;
    }
    
    for (std::list<int>::const_iterator i =  greenRow.container.begin(); i != greenRow.container.end(); ++i){
        numOfEntriesGreen++;
        if((*i == 0) || (*i == 10))
            isFirstOrLastCheckedInGreen = true;
    }
    
    //Checking if row is locked or not
    redRowLocked = false;
    yellowRowLocked = false;
    greenRowLocked = false;
    blueRowLocked = false;
    
    if ((numOfEntriesRed >=5) && isFirstOrLastCheckedInRed)
        redRowLocked = true;
    
    if((numOfEntriesYellow >= 5) && isFirstOrLastCheckedInYellow)
        yellowRowLocked = true;
    
    if((numOfEntriesGreen >= 5) && isFirstOrLastCheckedInGreen)
        greenRowLocked = true;
    
    if((numOfEntriesBlue >= 5) && isFirstOrLastCheckedInBlue)
        blueRowLocked = true;
    
    //Calculating total score
    int totalScore = 0;
    
    int scoringTable[12] = {1,3,6,10,15,21,28,36,45,55,66,78};
    //Red Row
    if (redRowLocked)
        numOfEntriesRed++;
    if(numOfEntriesRed != 0)
        totalScore += scoringTable[numOfEntriesRed-1];
    //Yellow Row
    if(yellowRowLocked)
        numOfEntriesYellow++;
    if(numOfEntriesYellow != 0)
        totalScore += scoringTable[numOfEntriesYellow-1];
    //Green Row
    if(greenRowLocked)
        numOfEntriesGreen++;
    if(numOfEntriesGreen != 0)
        totalScore += scoringTable[numOfEntriesGreen-1];
    //Blue Row
    if(blueRowLocked)
        numOfEntriesBlue++;
    if(numOfEntriesBlue != 0)
        totalScore += scoringTable[numOfEntriesBlue-1];
    
    //Substracting failed throws
    int failedAttempts = ScoreSheet::getNumberOfFailedAttempts();
    if (failedAttempts > 0)
        totalScore = totalScore - failedAttempts * 5;
    
    //Setting Final Score in ScoreSheet, still unsusre about this ????
    ScoreSheet::setFinalScore(totalScore);
    
    return totalScore;
}

/**
 Overloading output operator to print the Qwixx ScoreSheet
 */
std::ostream& operator<< (std::ostream& os, QwixxScoreSheet qw){
    
    os << "Player name: " << qw.playerName << "          Points: " << qw.calcTotal();
    os << "\n---------------------------------------\n";
    os << qw.redRow;
    //Check if locked
    if(qw.redRowLocked)
        os << " L";
    else
        os << " U";
    os << "\n---------------------------------------\n";
    os << qw.yellowRow;
    //Check if locked
    if(qw.yellowRowLocked)
        os << " L";
    else
        os << " U";
    os << "\n---------------------------------------\n";
    os << qw.greenRow;
    //Check if locked
    if(qw.greenRowLocked)
        os << " L";
    else
        os << " U";
    os << "\n---------------------------------------\n";
    os << qw.blueRow;
    //Check if locked
    if(qw.blueRowLocked)
        os << " L";
    else
        os << " U";
    os << "\n---------------------------------------\n";
    os << "Failed throws: ";
    if(qw.getNumberOfFailedAttempts() == 0 || qw.getNumberOfFailedAttempts() == 1)
        os << qw.getNumberOfFailedAttempts();
    else if (qw.getNumberOfFailedAttempts() > 1){
        for (int i = 0; i < qw.getNumberOfFailedAttempts(); i++){
            os << i+1 << " ";
        }
    }
    
    return os;
}
