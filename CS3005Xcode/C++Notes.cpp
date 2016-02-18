circle = mCenter, mRadius (x,y,r)
triangle = x[3], y[3]
rectangle = x,y,w,h

inside glut program
void display()
//drawing of circles, triangles, rectangles
	for(i=0;i < ns;i++)circles:
	shapes[i]->draw();
//repeat for triangles
//repeat for rectangles

circle, triangle, rectange all have a draw method.

GLOBAL
int nc = 0;
Circle circles[100];
Triangle triangles[100];
Rectangle rectangle[100];

instead....

Shapes *shapes[100];

void mouse(int x, int y, int state, int button) 
{
  if(mode == circleMode && 2nd click)
  {
    Shapes[nr] = new circle(x,y,r);
    nc++;
  }
//repeat for triangle and rectangle
}
//Shape has to have a draw method	

Circle c;
Triangle t;
Rectangle r;

Shape *ptr;
ptr = &c;
