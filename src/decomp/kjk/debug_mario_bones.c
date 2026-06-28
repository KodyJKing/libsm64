#include "../../debug_print.h"
#include "../include/types.h"
#include "debug_mario_bones.h"

#define BONE_AXIS_LENGTH 30.0f

extern s16 gMatStackIndex;
extern Mat4 gMatStack[32];

/**
 * Draws local coordinate frames for each of Mario's bones. Using RGB for X, Y, and Z axes respectively.
 */
void draw_bone_frame(void) {
    Mat4 *m = &gMatStack[gMatStackIndex];
    float ox = (*m)[3][0];
    float oy = (*m)[3][1];
    float oz = (*m)[3][2];

    // X axis - Red
    DEBUG_LINE(ox, oy, oz,
               ox + BONE_AXIS_LENGTH * (*m)[0][0],
               oy + BONE_AXIS_LENGTH * (*m)[0][1],
               oz + BONE_AXIS_LENGTH * (*m)[0][2],
               0xFF0000FF, 2);

    // Y axis - Green
    DEBUG_LINE(ox, oy, oz,
               ox + BONE_AXIS_LENGTH * (*m)[1][0],
               oy + BONE_AXIS_LENGTH * (*m)[1][1],
               oz + BONE_AXIS_LENGTH * (*m)[1][2],
               0x00FF00FF, 2);

    // Z axis - Blue
    DEBUG_LINE(ox, oy, oz,
               ox + BONE_AXIS_LENGTH * (*m)[2][0],
               oy + BONE_AXIS_LENGTH * (*m)[2][1],
               oz + BONE_AXIS_LENGTH * (*m)[2][2],
               0x0000FFFF, 2);
}
