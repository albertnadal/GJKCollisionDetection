#include <iostream>
#include <collision/collision.h>

using namespace collision;
using namespace std;

int main()
{
        Polygon triangle({vec2<unsigned short>(1, 1),
                          vec2<unsigned short>(3, 4),
                          vec2<unsigned short>(4, 1)});

        Polygon polygon({vec2<unsigned short>(3, 2),
                         vec2<unsigned short>(5, 2),
                         vec2<unsigned short>(6, 4),
                         vec2<unsigned short>(4, 6),
                         vec2<unsigned short>(3, 5)});

        Polygon rectangle({vec2<float>(0.25f, 5.75f),
                           vec2<float>(0.25f, 6.43f),
                           vec2<float>(5.89f, 6.43f),
                           vec2<float>(5.89f, 5.75f)});

        GJKCollisionDetector collisionDetector;
        bool collision = collisionDetector.detect(triangle, polygon);
        cout << "Do we have a collision between triangle and polygon: " << collision << endl;

        collision = collisionDetector.detect(rectangle, polygon);
        cout << "Do we have a collision between rectangle and polygon: " << collision << endl;

        collision = collisionDetector.detect(rectangle, triangle);
        cout << "Do we have a collision between rectangle and triangle: " << collision << endl;

        return 0;
}
