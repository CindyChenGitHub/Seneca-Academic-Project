/**
* @author Yue Chen
* @Date   2018-10-02
* @version 1.00
* FileName: Rectangle.java
*/
package jac444.wk2;
//import jac444.wk2.Measurable;

/**
 * Class Name: Rectangle
 * Class detail: subclass
 * Has superClass: Shape
 */
public class Rectangle extends Shape implements Measurable{
	protected double width;
	protected double height;

	/**
	* Default Constructor: none parameter
	* public
	* @param none
	*/
	Rectangle() {
		super();
		width = 0.0;
		height = 0.0;
	}
	
	/**
	* Three parameter Constructor
	* @param _topLeft Point: contains _topLeft value of Rectangle
	* @param _width double: contains _width value of Rectangle
	* @param _height double: contains _height value of Rectangle
	*/
	Rectangle(LabeledPoint _topLeft, double _width, double _height){
		super.point = _topLeft;
		width = _width;
		height = _height;
	}
	
	/**
	* @Override Abstract Method: Shape.getCentre
	* @param none
	* @return Point
	*/
	@Override
	LabeledPoint getCentre() {
		return super.point;
	}
	
	/**
	* @Override Abstract Method: Measurable.countryArea
	* @param none
	* @return double
	*/
	@Override
	public double countryArea() {
		double area = width * height;
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