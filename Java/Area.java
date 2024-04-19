import java.util.Scanner;
class shapes
{
int l,b;
float r,trib,trih;
shapes()
{
r=0;
l=0;
b=0;
trib=0;
trih=0;
}
shapes(float cr,int rl,int rb,float tb,float th)
{
r=cr;
l=rl;
b=rb;
trib=tb;
trih=th;
}
void area(float r)
{
System.out.println("Area of circle is:"+3.14*r*r);
}
void area(int len, int bre)
{
System.out.println("Area of recatangle is:"+len*bre);
}
void area(float b,float h)
{
System.out.println("Area of triangle is:"+(b*h)/2);
}}
class Area
{
public static void main(String args[])
{
Scanner S=new Scanner(System.in);
System.out.println("Enter the radius of the circle:");
float r=S.nextInt();
System.out.println("Enter the length of rectangle:");
int l=S.nextInt();
System.out.println("Enter the breadth of rectangle:");
int b=S.nextInt();
System.out.println("Enter the base of triangle:");
float ba=S.nextFloat();
System.out.println("Enter the height of triangle:");
float h=S.nextFloat();
shapes s=new shapes(r,l,b,ba,h);
s.area(r);
s.area(l,b);
s.area(ba,h);
}}
