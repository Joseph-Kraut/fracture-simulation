#ifndef POINTMASS_H
#define POINTMASS_H

#include "CGL/CGL.h"
#include "CGL/misc.h"
#include "CGL/vector3D.h"

using namespace CGL;

// Forward declarations
class Halfedge;

struct PointMass {
  PointMass(Vector3D position, bool pinned)
      : pinned(pinned), start_position(position), position(position),
        last_position(position) {}

  Vector3D normal();
  Vector3D velocity(double delta_t) {
    return (position - last_position) / delta_t;
  }

  inline bool operator==(PointMass pm_a) {
      return pm_a.position == position
                && pm_a.last_position == last_position
                && pm_a.forces == forces;
  }

  inline bool operator==(const PointMass pm_a) const {
      return pm_a.position == position
                && pm_a.last_position == last_position
                && pm_a.forces == forces;
  }

  // static values
  bool pinned;
  Vector3D start_position;

  int cluster;

  // dynamic values
  Vector3D position;
  Vector3D last_position;
  Vector3D forces;
  bool fractured = false;

  // mesh reference
  Halfedge *halfedge;
};

#endif /* POINTMASS_H */
