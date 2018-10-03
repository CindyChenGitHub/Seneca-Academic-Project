/**
* @author Yue Chen
* @Date   2018-10-02
* @version 1.00
* FileName: Shape.java
*/
package jac444.wk2;

/**
 * Class Name: Shape
 * Class detail: abstract super class
 * Has SubClass1: Circle
 * Has SubClass2: Rectangle
 * Has SubClass3: Line
 */
abstract class Shape {
	
	protected LabeledPoint point;
	
	/**
	* Default Constructor: none parameter
	* public
	* @param none
	*/
	public Shape() {
		point = new LabeledPoint();
	}
	
	/**
	* Method: moveBy
	* Public
	* @param dx double: contains value of moves the point on x
	* @param dy double: contains value of moves the point on y
	* @return none
	*/
	public void moveBy(double dx, double dy) {
		point.x = point.x + dx;
		point.y = point.y + dy;
	}
	
	/**
	* Abstract Method: getCentre
	* @param none
	* @return Point
	*/
	abstract Point getCentre();
}