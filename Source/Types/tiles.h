#ifndef TILES_H
#define TILES_H

namespace TileStates {

    enum Terrain : int {
        /*
        TERRAIN / ROADS FOR ROUTES, TOWNS AND CITIES
        SPRITESHEET MATRIX 3X3

        {{TOPLEFTCORNER  TOPCENTER    TOPRIGHT}
         {CENTERLEFT       CENTER     CENTERRIGHT}
         {BOTTOMLEFT    BOTTOMCENTER  BOTTOMRIGHT}}
        */

        TOPLEFTCORNER = 1,
        TOPCENTER = 2,
        TOPRIGHT = 3,
        CENTERLEFT = 4,
        CENTER = 5,
        CENTERRIGHT = 6,
        BOTTOMLEFT = 7,
        BOTTOMCENTER = 8,
        BOTTOMRIGHT = 9
    };

    enum TerrainExt : int {
        /*
        TERRAIN EXTENDED/ ROADS FOR ROUTES, TOWNS AND CITIES
        SPRITESHEET MATRIX 3X4

        {{TOPLEFTCORNER  TOPCENTER1     TOPCENTER2    TOPRIGHT}
         {CENTERLEFT      CENTER1         CENTER2     CENTERRIGHT}
         {BOTTOMLEFT    BOTTOMCENTER1  BOTTOMCENTER2  BOTTOMRIGHT}}
        */

        TOPLEFTCORNER = 1,
        TOPCENTER1 = 2,
        TOPCENTER2 = 3,
        TOPRIGHT = 4,
        CENTERLEFT = 5,
        CENTER1 = 6,
        CENTER2 = 7,
        CENTERRIGHT = 8,
        BOTTOMLEFT = 9,
        BOTTOMCENTER1 = 10,
        BOTTOMCENTER2 = 11,
        BOTTOMRIGHT = 12
    };



};

#endif