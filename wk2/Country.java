/**
* @author Yue Chen
* @Date   2018-10-02
* @version 1.00
* FileName: Country.java
*/
package jac444.wk2;
import java.util.Scanner;

/**
 * Class Name: Country
 * Class detail: main function inside
 */
public class Country implements Measurable {
	String name;	
	double area;
	
	/**
	* Two parameter Constructor
	* @param _neme
	* @param _area
	*/
	Country(String _name, double _area){
		name = _name;
		area = _area;
	}
	
	/**
	* @Override Abstract Method: Measurable.getArea
	* @param none
	* @return String
	*/
	@Override
	public String getArea() {
		return "Country: " + name + ", Area: " + area +" units squared";
	}
	
	/**
	* @Override Abstract Method: Measurable.countryArea
	* @param none
	* @return double
	*/
	@Override
	public double countryArea() {
		return area;
	}
	
	/**
	* Menu method: showCountry
	* @param none
	* @return void
	*/
	static void showCountry() {
		System.out.println("***************");
		System.out.println("* Set country *");
		System.out.println("***************");
		System.out.println("1: Canada");
		System.out.println("2: Amarica");
		System.out.println("3: French");		
		System.out.println("0: exit");
		System.out.print("Please enter a chioce: ");
	}
	
	/**
	* Menu method: showShape
	* @param none
	* @return void
	*/
	static void showShape() {
		System.out.println("*********************");
		System.out.println("* Set country shape *" );
		System.out.println("*********************");
		System.out.println("1: Circle");
		System.out.println("2: Line");
		System.out.println("3: Rectangle");		
		System.out.println("0: exit");
		System.out.print("Please enter a chioce: ");
	}
	
	/**
	* Menu method: playAgain
	* @param none
	* @return void
	*/
	static void playAgain() {
		System.out.println("\n" + "Play again?");
		System.out.println("1: yes");
		System.out.println("0: no");
		System.out.print("Please enter a chioce: ");
	}
	
	/**
	* Main method: main
	* @param none
	* @return void
	*/
	public static void main(String[] args) {
		// Identify available
		LabeledPoint point;
		String _countryName = null;
		boolean next = true;
		
		// set center/\leftTop point
		Scanner input = new Scanner(System.in);	
		System.out.println("******************************");
		System.out.println("* Set a Centre/leftTop Point *");
		System.out.println("******************************");
		System.out.print("Please enter a double for x: ");
		Double _x = input.nextDouble();
		System.out.print("Please enter a double for y: ");
		Double _y = input.nextDouble();
		point = new LabeledPoint("Point", _x, _y);
		
		// display center/\leftTop point
		System.out.println("--------------------------------------------------");
		System.out.println(point.toString());
		System.out.println("--------------------------------------------------");
		
		// set and calculate country/shape
		do {
			// set country
			showCountry();
			switch(input.nextInt()) {
				case 0:
					System.out.print('\n');
					System.out.println("***************************");
					System.out.println("* Program end, thank you. *");
					System.out.println("***************************");
					System.exit(0);
				case 1:
					_countryName = "Canada";
					break;
				case 2:
					_countryName = "Amerca";
					break;
				case 3:
					_countryName = "French";
					break;
			}
			System.out.print('\n');
			
			// set, calculate, and display shape
			showShape();
			switch (input.nextInt()) {
				case 0:
					System.out.print('\n');
					System.out.println("***************************");
					System.out.println("* Program end, thank you. *");
					System.out.println("***************************");
					System.exit(0);
				case 1:
					System.out.print('\n');
					System.out.println("**************");
					System.out.println("* Set Circle *");
					System.out.println("**************");
					System.out.print("Please enter a double for radius; ");
					Double _r = input.nextDouble();
					
					point.label = "Circle Centre Point";
					Circle circle = new Circle(point, _r);
					Country circleCountry = new Country(_countryName, circle.countryArea());
					System.out.println("--------------------------------------------------");
					System.out.println("Circle Centre: " + point.toString());
					System.out.println("Circle Radius: " + _r);
					System.out.println(circleCountry.getArea());
					System.out.println("--------------------------------------------------");
					break;
				case 2:
					System.out.print('\n');
					System.out.println("************");
					System.out.println("* Set Line *");
					System.out.println("************");
					System.out.print("Please enter a double for endPoint x: ");
					Double _cx = input.nextDouble();
					System.out.print("Please enter a double for endPoint y: ");
					Double _cy = input.nextDouble();
					
					point.label = "Line from point";
					LabeledPoint toPoint = new LabeledPoint("Line to point", _cx, _cy);
					Line line = new Line(point, toPoint);
					Country lineCountry = new Country(_countryName, line.countryArea());
					System.out.println("--------------------------------------------------");
					System.out.println("Line From: " + point.toString());
					System.out.println("Line To  : " + toPoint.toString());
					System.out.println(lineCountry.getArea());
					System.out.println("--------------------------------------------------");
					break;
				case 3:
					System.out.print('\n');
					System.out.println("*****************");
					System.out.println("* Set Rectangle *");
					System.out.println("*****************");
					System.out.print("Please enter a double for width: ");
					Double _width = input.nextDouble();
					System.out.print("Please enter a double for height: ");
					Double _height = input.nextDouble();
					
					point.label = "Rectangle leftTop point";
					Rectangle rectangle = new Rectangle(point, _width, _height);
					Country rectangleCountry = new Country(_countryName, rectangle.countryArea());
					System.out.println("--------------------------------------------------");
					System.out.println("Rectangle centre: " + point.toString());
					System.out.println("Rectangle width: " + _width + ", height: " + _height);
					System.out.println(rectangleCountry.getArea());
					System.out.println("--------------------------------------------------");
					break;			
			}
			
			// set play again
			playAgain();
			switch(input.next().charAt(0)) {
			case '0':
			case 'n':
			case 'N':
				System.out.print('\n');
				System.out.println("***************************");
				System.out.println("* Program end, thank you. *");
				System.out.println("***************************");
				next = false;
				break;
			case '1':
			case 'y':
			case 'Y':
				next = true;
				break;
			}
			System.out.print('\n');
		}while (next);
		input.close();
	}
}