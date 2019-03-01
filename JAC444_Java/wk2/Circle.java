/**
* @author Yue Chen
* @Date   2018-10-02
* @version 1.00
* FileName: Circle.java
*/
package jac444.wk2;

//import jac444.wk2.Measurable;

/**
 * Class Name: Circle
 * Class detail: subclass
 * Has superClass: Shape
 */
public class Circle extends Shape implements Measurable {
	protected double radius;

	/**
	* Default Constructor: none parameter
	* @param none
	*/
	Circle() {
		super();
		radius = 0.0;
	}
	
	/**
	* Two parameter Constructor
	* @param _centre Point: contains _centre value of Circle
	* @param _radius double: contains _radius value of Circle
	*/
	Circle(LabeledPoint _centre, double _radius){
		super.point = _centre;
		radius = _radius;
	}
	
	/**
	* @Override Abstract Method: Shape.getCentre
	* @param none
	* @return Point
	*/
	@Override
	Point getCentre() {
		return super.point;
	}
	
	/**
	* @Override Abstract Method: Measurable.countryArea
	* @param none
	* @return double
	*/
	@Override
	public double countryArea() {
		double area = Math.PI * Math.pow(radius, 2);
		return area;
	}
	
	/**
	* @Override Abstract Method: Measurable.getArea
	* @param none
	* @return String
	*/
	@Override
	public String getArea() {
		return "Area: " + countryArea() + " units squared\n";
	}
}
