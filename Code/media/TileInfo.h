//
// Created by richard on 17/01/16.
//

#ifndef INDIVIDUALPROJECT_TEXTUREINFO_H
#define INDIVIDUALPROJECT_TEXTUREINFO_H

class TileInfo {
public:
    TileInfo(int texture,int xInTerrain, int yInTerrain,
             int xOnScreen, int yOnScreen);

    int getTexture();

    int getXInTerrain();
    int getYInTerrain();

    int getXOnScreen();
    int getYOnScreen();


private:
    int texture;

    //2.5d Coords
    int xInTerrain;
    int yInTerrain;

    int xOnScreen;
    int yOnScreen;
};


#endif //INDIVIDUALPROJECT_TEXTUREINFO_H
