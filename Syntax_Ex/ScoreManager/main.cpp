#include "ScoreManager.hpp"

int main(){
    ScoreManager scoreMan = ScoreManager("Federico", 5);

    int scoreFede[5] = {10, 10, 20, 50, 100};
    int *pointScoreFede = &scoreFede[0];

    scoreMan.fillScores(pointScoreFede);

    scoreMan.printScores();

    std::cout << "Middle value: " << scoreMan.middleValueScores() << std::endl;
    std::cout << "Max value: " << scoreMan.maxValueScores() << std::endl;

    scoreMan.updateScoreInPos(200, 0);
    scoreMan.printScores();

    scoreMan.updateScoreInPos(200, 8);
    scoreMan.printScores();

    scoreMan.updateScoreInPos(200, -2);
    scoreMan.printScores();

    scoreMan.addScore(400);
    scoreMan.printScores();

}