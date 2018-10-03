package jac444.wk1;
import java.util.Random;
public class PrintRandomString {

	public static void main(String[] args) {
		Random random = new Random();
		String randomString = Long.toString(random.nextLong() & Long.MAX_VALUE,36);
		System.out.println(randomString);
	}
}
