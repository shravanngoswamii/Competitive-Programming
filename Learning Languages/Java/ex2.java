abstract class Figure {
	double dim1;
	double dim2;
	Figure(double a, double b) {
		dim1 = a;
		dim2 = b;
	}
	abstract double area();
}
class Rectangle extends Figure {
	Rectangle(double a, double b) {
		super(a,b); 
	}
}



// Practical 11 - Desribe abstract class called Say which has three subclasses Triangle, Rectangle and Circle, define a method area() in the abstract class and override this method in this three subclasses to calculate four specific objects that is area of triangle subclass should calculate area of triangle same for rectangle and circle.

