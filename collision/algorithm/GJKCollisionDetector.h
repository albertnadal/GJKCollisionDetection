#pragma once

#include <memory>
#include <vector>
#include <structures/vec2.hpp>
#include <geometry/Polygon.h>
#include <math/Transform2.h>

using namespace std;

namespace collision
{

class MinkowskiSum;

class GJKCollisionDetector
{
  public:
    GJKCollisionDetector();
    bool detect(const Polygon &convex1, const Polygon &convex2);

  private:
    collision::vec2<float> calcInitialDirection(const Polygon &convex1, const Transform2 &transform1, const Polygon &convex2, const Transform2 &transform2);
    bool detect(const MinkowskiSum &minkowskiSum, vector<collision::vec2<float>> &simplex, collision::vec2<float> &direction);
    bool checkSimplex(vector<collision::vec2<float>> &simplex, collision::vec2<float> &direction);
};

} // namespace collision
