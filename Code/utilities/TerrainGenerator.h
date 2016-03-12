//
// Created by richard on 08/02/16.
//

#ifndef INDIVIDUALPROJECT_TERRAINGENERATOR_H
#define INDIVIDUALPROJECT_TERRAINGENERATOR_H


#include "TextureInfo.h"
#include "textures.h"
#include "PerlinNoise.h"
#include "TerrainNode.h"
#include "random.h"

class TerrainGenerator {
public:
    TerrainGenerator(int **terrain, int **terrainDetail);

private:
    void generateTerrain();

    int generateOcean(int x, int y, int edgeSandLine, double value);

    int generateLand(double value);

    /**
     * Adds 4 major towns, one in each corner of the map
     * Adds between 0 and 4 random hidden towns,
     * these are not on any connecting roads
     */
    void placeTowns();

    /**
     * Adds roads to the map. These roads pave a way between the 4 major towns
     */
    void placeRoads();

    /**
     * Add trees around the map
     */

    /**
     * Finds the route for roads
     */
    TerrainNode* aStarSearch(int startX, int startY, int endX, int endY);

    /**
     * Finds the best node to move to next for the search
     */
    int findBestNode(vector<TerrainNode*> unExpNodes,
                     int endX, int endY, TerrainNode* curNode);

    /**
     * Places trees on the map using random numbers and
     * weights depending on the terrain type
     */
    void placeTrees();

    /**
     * Places waves on the ocean and lakes
     */
    void placeWaves();



    int **terrain;
    int **terrainDetail;

    int const MAX_OCEAN_LINE = 200;
    int const MAX_BEACH_LINE = 400;

    int const TERRAIN_SCALE = 50;

    //Number of towns on the map, between 4 and 8
    int numTowns;
    //First for x coord, second for y coord, and third for type
    int townPositions[8][3];

    enum TownType {
        Sand,
        Plains,
        Mountain,
        Water
    };
};


#endif //INDIVIDUALPROJECT_TERRAINGENERATOR_H