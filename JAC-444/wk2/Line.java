/**
* @author Yue Chen
* @Date   2018-10-02
* @version 1.00
* FileName: Line.java
*/
package jac444.wk2;

/**
 * Class Name: Line
 * Class detail: subclass
 * Has superClass: Shape
 */
public class Line extends Shape implements Measurable{
	protected LabeledPoint to;

	/**
	* Default Constructor: none parameter
	* public
	* @param none
	*/
	Line() {
		super();
		to = new LabeledPoint();
	}
	
	/**
	* Two parameter Constructor
	* @param _from Point: contains _from value of Line
	* @param _to double: contains _to value of Line
	*/
	Line(LabeledPoint _from, LabeledPoint _to){
		super.point = _from;
		to = _to;
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
		return 0.0;
	}
	
	/**
	* @Override Abstract Method: Measurable.getArea
	* @param none
	* @return String
	*/
	@Override
	public String getArea() {
		return "Area: Not Available\n";
	}
}