#ifndef LINE_H
#define LINE_H

#include "Point.h"
#include "SimpleFigure.h"

class Line: public SimpleFigure
{
public:
	Line();
	Line(const Point &begin, const Point &end);

	Point getBeginPoint() const;
	Point getEndPoint() const;
	Point getDownPoint() const;
	Point getUpPoint() const;
	Point getCenterPoint() const;

	void setBeginPoint(const Point &p);
	void setEndPoint(const Point &p);
	void setLine(const Point &begin, const Point &end);

	void translate(const Point &offset); //平移
	void rotate(double angle); //绕中点旋转
	void scale(double s); //以中点为基准进行放缩

	bool cut(const Point &leftDown, int width, int height); //根据矩形窗口裁剪，若不在窗口中则返回false

	void markDraw(); //只负责绘制draw以外的标记，不绘制直线本身

private:
	Point begin;
	Point end;
	Point *left;
	Point *right;
	Point *up;
	Point *down;

	void updateParameters();
	void calculatePoints();
	void bresenham01(int dx, int dy);
	void bresenham_10(int dx, int dy);
	void bresenham1inf(int dx, int dy);
	void bresenham_inf_1(int dx, int dy);
};

#endif // !LINE_H

