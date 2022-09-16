//
// Created by Kacper on 16/09/2022.
//
#include <iostream>

using std::cout;

struct Point {
    int  m_x;
    virtual void draw(){ cout<<"Point\n"; }
};

struct Point2D : Point {
    int    m_y;
    void draw(){ cout<<"Point2D\n"; }
};

void draw_point(Point &p) { p.draw(); }

struct Line {
    Point2D m_start;
    Point2D m_end;
    void draw() { cout << "Line\n"; }
};

struct LineAdapter : Point {
    Line& m_line;
    LineAdapter(Line &line) : m_line(line) {}
    void draw(){ m_line.draw(); }
};

template<class T>
struct GenericLineAdapter : Point {
    T& m_line;
    GenericLineAdapter(T &line) : m_line(line) {}
    void draw(){ m_line.draw(); }
};

int main() {
    Line line;
    LineAdapter lineAdapter(line);
    draw_point(lineAdapter);

    GenericLineAdapter<Line> genericLineAdapter(line);
    draw_point(genericLineAdapter);

    return 0;
}