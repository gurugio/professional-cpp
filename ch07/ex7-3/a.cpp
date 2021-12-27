#include <iostream>
#include <memory>
#include <fmt/core.h>

using namespace std;

class Point3D
{
public:
    Point3D(int x, int y, int z) : m_x{x}, m_y{y}, m_z{z}
    {
        cout << fmt::format("constructor: {} {} {}\n", m_x, m_y, m_z);
    }
    ~Point3D(void)
    {
        cout << fmt::format("destructor: {} {} {}\n", m_x, m_y, m_z);
    }
    void show(void)
    {
        cout << fmt::format("coordinate: x={} y={} z={}\n", m_x, m_y, m_z);
    }

    int getX(void) { return m_x; }
    int getY(void) { return m_y; }
    int getZ(void) { return m_z; }

private:
    int m_x, m_y, m_z;
};

void anotherShow(unique_ptr<Point3D> &p)
{
    cout << fmt::format("coordinate: x={} y={} z={}\n", p->getX(), p->getY(), p->getZ());
}

int main()
{
    unique_ptr<Point3D> point{make_unique<Point3D>(1, 2, 3)};
    anotherShow(point);
    point->show();
}