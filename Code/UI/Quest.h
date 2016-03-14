//
// Created by richard on 14/03/16.
//

#ifndef INDIVIDUALPROJECT_QUEST_H
#define INDIVIDUALPROJECT_QUEST_H

#include <string>
#include <sstream>
#include <vector>
#include "drawText.h"

using namespace std;

class Quest {
public:
    Quest();

    void findTownsInit(int** towns, int numTowns);
    bool foundTown(int x, int y);

    void killEnemiesInit(int numEnemies);
    bool enemyKilled();

    void currentQuests();

private:
    vector<string> questsText;
    int numQuests;

    int numTownsRemaining;
    vector<int*> townPos;
    int townPlaceInQuests;

    int enemiesRemaining;
    int enemyQuestPlaceInQuests;
};


#endif //INDIVIDUALPROJECT_QUEST_H
