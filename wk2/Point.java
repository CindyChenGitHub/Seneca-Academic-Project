/**
* @author Yue Chen
* @Date   2018-10-02
* @version 1.00
* FileName: Point.java
*/
package jac444.wk2;
import java.util.Objects;

/**
 * Class Name: Point
 * Class detail: super class
 * Has SubClass: LabeledPoint
 */
public class Point {

	protected double x;
	protected double y;
	
	/**
	* Default Constructor: none parameter
	* @param none
	*/
	protected Point(){
		x = 0.0;
		y = 0.0;
	}
	
	/**
	* Two parameterConstructor
	* @param _x double: contains _x coordinate value of Point
	* @param _y double: contains _y coordinate value of Point
	*/
	protected Point(double _x, double _y) {
		x = _x;
		y = _y;
	}
	
	/**
	* Access method: getX
	* @param none
	* @return double
	*/
	protected double getX() {
		return x;
	}
	
	/**
	* Access method: getY
	* @param none
	* @return double
	*/
	protected double getY() {
		return y;
	}
	
	/**
	* toString method: toString
	* public
	* @param none
	* @return String
	*/
	public String toString() {
		return "In class: " + getClass().getName() + ": [x=" + x + ", y=" + y + "]";
	}
	
	/**
	* equals method: equals
	* public
	* @param otherObject PointObject
	* @return boolean
	*/
	public boolean equals(Object otherObject) {
		// A quick test to see if the objects are identical
		//if (this != otherObject) return false;
		
		// Must return false if the parameter is null
		if (otherObject == null) return false;
		// Check that otherObject is an Point
		else if (getClass() != otherObject.getClass()) return false;
		else {
			// Test whether the instance variables have identical values
			Point other = (Point) otherObject;
			return x == other.x && y == other.y;
		}
	}

	/**
	* hashCode method: hashCode
	* public
	* @param none
	* @return integer
	*/
	public int hashCode() {
		return Objects.hash(x,y);
	}
}


