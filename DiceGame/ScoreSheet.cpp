/*
 * CSI 2772 - Jouer aux dés
 * Adel Araji - 7897476
 * Alexandre Prud'Homme - 7293804
 * Le 6 décembre 2017
 */

#include <stdio.h>
#include "ScoreSheet.h"

/*
 * Constructeur
 * @param std::string name
 */
ScoreSheet::ScoreSheet(std::string name){
    nameOfPlayer = name;
}
//Destructeur
ScoreSheet::~ScoreSheet(){
    
}

/*
 * Cherche le nombre de faillites
 * @return int
 */
int ScoreSheet::getNumberOfFailedAttempts(){
    return numberOfFailedAttempts;
}

/*
 * Attribuer le pointage final
 * @param int score
 * @return void
 */
void ScoreSheet::setFinalScore(int score){
    overallScore = score;
}

/*
 * Cherche le nom du joueur
 * @return std::string
 */
std::string ScoreSheet::getPlayerName(){
    return nameOfPlayer;
}



/**
 A score is entered using this method, sets an individual score for one roll of dice

 @param rd : Roll fo Dice
 @param cl : Colour of Dice
 @param positionFromLeft : Position From Left, set to -1 in case of Qwixx
 @return boolean to check if it is possible to score or note
 */
bool ScoreSheet::score(RollOfDice rd, Colour cl, int positionFromLeft = -1){
    return validate(rd, cl, positionFromLeft);
}


/**
 Sets and returns the FINAL score

 @return int, the final score score of the game
 */
int ScoreSheet::setTotal(){
    overallScore = calcTotal();
    return calcTotal();
}



/**
 Overload the not operator

 @return True if Game has ended, false if not
 */
bool const ScoreSheet::operator!(){
    if (numberOfFailedAttempts == 4)
        return true;
    else
        return false;
}
