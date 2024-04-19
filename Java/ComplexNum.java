class Complex {
    float real, img;
    Complex(float real, float img) {
        this.real = real;
        this.img = img;
    }
    Complex add(Complex c2) {
        Complex result = new Complex(0, 0);
        result.real = real + c2.real;
        result.img = img + c2.img;
        return result;
    }
    Complex subtract(Complex c2) {
        Complex result = new Complex(0, 0);
        result.real = real - c2.real;
        result.img = img - c2.img;
        return result;
    }
    Complex multiply(Complex c2) {
        Complex result = new Complex(0, 0);
        result.real = (real * c2.real) - (img * c2.img);
        result.img = (real * c2.img) + (img * c2.real);
        return result;
    }
    void display() {
        System.out.println(real + " + " + img +"i");
    }
}
class ComplexNum{
    public static void main(String[] args) {
        Complex c1 = new Complex(6.0f, 5.0f);
        Complex c2 = new Complex(7.0f, 6.0f);
        System.out.print("c1: ");
        c1.display();
        System.out.print("c2: ");
        c2.display();
        Complex c3 = new Complex(0, 0);
        c3 = c1.add(c2);
        System.out.println("Addition: ");
        c3.display();
        Complex c4 = new Complex(0, 0);
        c4 = c1.subtract(c2);
        System.out.println("Subtraction: ");
        c4.display();
        Complex c5 = new Complex(0, 0);
        c5 = c1.multiply(c2);
        System.out.println("Multiplication: ");
        c5.display();
    }
}

























