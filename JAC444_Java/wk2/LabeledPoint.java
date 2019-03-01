/**
* @author Yue Chen
* @Date   2018-10-02
* @version 1.00
* FileName: LabeledPoint.java
*/
package jac444.wk2;
import java.util.Objects;

/**
 * Class Name: LabeledPoint
 * Class detail: subclass
 * Has superClass: Point
 */
public class LabeledPoint extends Point {
	
	protected String label;
	
	/**
	* Default Constructor: none parameter
	* public
	* @param none
	*/
	public LabeledPoint() {
		super();
		label = getClass().getName();
	}
	
	/**
	* Three parameter Constructor
	* public
	* @param _label String: contains _label coordinate value of LabeledPoint
	* @param _x double: contains _x coordinate value of LabeledPoint
	* @param _y double: contains _y coordinate value of LabeledPoint
	*/
	public LabeledPoint(String _label, double _x, double _y){
		super(_x, _y);
		label = _label;
	}
	
	/**
	* Access method: getLabel
	* public
	* @param none
	* @return String
	*/
	public String getLabel(){
		return label;
	}
	
	/**
	* toString method: toString
	* public
	* @param none
	* @return String
	*/	
	public String toString(){
		return super.toString() + "[label=" + label +"]";
	}
	
	/**
	* equals method: equals
	* public
	* @param otherObject PointObject
	* @return boolean
	*/
	public boolean equals(Object otherObject) {
		// Return false if the super class is not equals
		if (!super.equals(otherObject)) return false;
		//Test whether the instance variables have identical values
		LabeledPoint other = (LabeledPoint) otherObject;
		return label.equals( other.label);
	}
	
	/**
	* hashCode method: hashCode
	* public
	* @param none
	* @return integer
	*/
	public int hashCode() {
		int pHash = super.hashCode();
		return Objects.hash(label,pHash);
	}
}
