package PrintCalendar;
import java.time.LocalDate;
import PrintCalendar.ReadInteger;
public class PrintCalendar {
	private Integer year;
	private Integer month;
	//LocalDate firstDay; 
	
	PrintCalendar(){
		year = LocalDate.now().getYear();
		month = LocalDate.now().getMonthValue();
		//firstDay = LocalDate.of(year, month, 1);
	}
	PrintCalendar(Integer in_year, Integer in_month){
		year = in_year;
		month = in_month;
		//firstDay = LocalDate.of(year, month, 1);
	}
	public void setYear() {
		ReadInteger temYear = new ReadInteger(2000,2050);
		year = temYear.read();
	}
	public void setMonth() {
		ReadInteger temMonth = new ReadInteger(1,12);
		month = temMonth.read();
	}
	public Integer getYear() {
		return year;
	}
	public Integer getMonth() {
		return month;
	}
	private void printTitle() {
		LocalDate firstDay = LocalDate.of(year, month, 1);
		String title = firstDay.getMonth() + " " + firstDay.getYear();
		int blankNum = (28-title.length())/2;
		for (int i = 0; i<blankNum; i++)
			System.out.print(" ");
		System.out.println(title);
		String[] day = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
		for(String s:day)
			System.out.print(" " + s);
		System.out.print('\n');
	}
	private void printBlank() {
		LocalDate firstDay = LocalDate.of(year, month, 1);
		for(int i = 1; i<firstDay.getDayOfWeek().getValue(); i++)
			System.out.print("    ");
	}
	private void printDates() {
		LocalDate firstDay = LocalDate.of(year, month, 1);
		LocalDate date = firstDay;
		while(date.getMonthValue() == month) {
			int dayOM = date.getDayOfMonth();
			int dayOW = date.getDayOfWeek().getValue();
			if(dayOW == 1 && dayOM != 1)
				System.out.printf("\n%4d",dayOM);
			else
				System.out.printf("%4d", dayOM);
			date=date.plusDays(1);
		};
	}
	public void printCalendar() {
		printTitle();
		printBlank();
		printDates();
	}
	public static void main(String[] args) {
		PrintCalendar calendar = new PrintCalendar();
		calendar.setYear();
		calendar.setMonth();
		calendar.printCalendar();
	}
}
//	Output:
//	Please input a integer number between 2000 and 2050: 2012
//	Your input is : 2012
//	~Press Any Key to Continue...
//	
//	Please input a integer number between 1 and 12: 2
//	Your input is : 2
//	~Press Any Key to Continue...
//	
//	       FEBRUARY 2012
//	 Mon Tue Wed Thu Fri Sat Sun
//	           1   2   3   4   5
//	   6   7   8   9  10  11  12
//	  13  14  15  16  17  18  19
//	  20  21  22  23  24  25  26
//	  27  28  29
