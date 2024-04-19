class Circle{
 float radius;
 Circle(){
 radius=1f;
}
 Circle(float r){
 radius=r;
}
 public float getCir(){
 return 6.18f*radius;
}
}
 class Circumference{
  public static void main(String args[]){
  Circle c1=new Circle();
  Circle c2=new Circle(5);
  
  float p1=c1.getCir();
  float p2=c1.getCir();
  System.out.println("Circumference of Default:"+p1);
  System.out.println("Circumference of Parameterized:"+p2);
 }
} 
