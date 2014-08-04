#ifndef SAIL_BOAT_H_
#define SAIL_BOAT_H_

#include <cairo.h>
#include <librsvg/rsvg.h>

typedef struct _images {
    RsvgHandle *hull;
    RsvgHandle *sail;
    RsvgHandle *rudder;
    RsvgDimensionData *hull_dimensions;
    RsvgDimensionData *sail_dimensions;
    RsvgDimensionData *rudder_dimensions;
} SVGImages;

struct _boat;

typedef struct _boat {
    double x, y; // coordinates of boat
    double angle; // orientation of boat
    double sail_angle;
    double rudder_angle;
    int sail_is_free; // is the sail free to move?

    double theta, v, rotational_velocity, ell; // state variables
    double drift_coefficient, Jz, rg, rv, rudder_lift, sail_lift, alphaf, alphatheta, l, m; // parameters
    double gamma,deltav;  // link variables

    SVGImages* images;
} Boat;

Boat* sail_boat_new();
void sail_boat_free(Boat *boat);

double sail_boat_get_angle(const Boat *boat);
double sail_boat_get_rudder_angle(const Boat *boat);
double sail_boat_get_sail_angle(const Boat *boat);
double sail_boat_get_velocity(const Boat *boat);

#endif
