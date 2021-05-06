
#include "AxisRemap.h"

int main(int argc, char *argv[])
{

    AxisRemap *w = new AxisRemap();

    // Not necessary for settings only
    // w->newIMU();

    // unsigned char axis_map = AXIS_MAP_DEFAULT;
    // unsigned char sign_map = SIGN_MAP_DEFAULT;
    unsigned char axis_map = 0b00001001;
    unsigned char sign_map = 0b00000000;

    int status = w->remap(axis_map, sign_map);

    return status;
}

