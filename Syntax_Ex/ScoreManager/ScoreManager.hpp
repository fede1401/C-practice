#ifndef SCORE_MANAGER_H
#define SCORE_MANAGER_H

#include <string>
#include <iostream>

class ScoreManager{

    private:
        std::string player_name;
        int * scores;
        int n;

    public:
        ScoreManager();
        ScoreManager(std::string player_name, int n);

        //Getter and setter
        std::string getPlayerName();
        int* getScores();
        int getN();

        void setPlayerName(std::string playerName);
        void setScores(int* scores);
        void setN(int n);


        void fillScores();
        void fillScores(int *scoresFromFile);

        void printScores();
        float middleValueScores();
        int maxValueScores();

        void updateScoreInPos(int value, int pos);

        void addScore(int value);
};


#endif