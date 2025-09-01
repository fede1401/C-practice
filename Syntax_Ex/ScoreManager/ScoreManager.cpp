#include "ScoreManager.hpp"

ScoreManager::ScoreManager(){}

ScoreManager::ScoreManager(std::string player_name, int n){
    this->player_name = player_name;
    this->n = n;
    this->scores = new int[n];
}


std::string ScoreManager::getPlayerName(){ return player_name; }

int* ScoreManager::getScores(){ return scores; }

int ScoreManager::getN(){ return n; }


void ScoreManager::setPlayerName(std::string player_name){ this->player_name = player_name; }

void ScoreManager::setScores(int* scores){
    this->scores = scores;
}

void ScoreManager::setN(int n){ this->n = n; }


void ScoreManager::fillScores(){

}

void ScoreManager::fillScores(int *scoresFromFile){
    for (int i = 0; i<this->n; i++){
        scores[i] = scoresFromFile[i];
    }
    return;
}


void ScoreManager::printScores(){
    for (int i = 0; i<this->n; i++){ 
        std::cout << "Pos i: " << i+1 << " , value: " << scores[i] << std::endl; 
    }
    std::cout << std::endl;
}


float ScoreManager::middleValueScores(){
    float middleVal = 0.0;
    for (int i = 0; i<this->n; i++){ middleVal+=scores[i]; }
    return middleVal/this->n;
}

int ScoreManager::maxValueScores(){
    int maxVal = 0;
    for (int i = 0; i<this->n; i++){ 
        if (scores[i] > maxVal){
            maxVal = scores[i];
        }
    }
    return maxVal;
}


void ScoreManager::updateScoreInPos(int value, int pos){
    // Check if position in n dimensions
    if (pos < 0 || pos >= n) {
        std::cout << "Value cannot be changed: position out of bounds!" << std::endl;
        return;
    }

    this->scores[pos] = value;
    return;
}


void ScoreManager::addScore(int value) {
    int* newArr = new int[n + 1];
    for (int i = 0; i < n; i++) {
        newArr[i] = scores[i];
    }
    newArr[n] = value;
    delete[] scores;        // libera la memoria precedente
    scores = newArr;
    n++;
}