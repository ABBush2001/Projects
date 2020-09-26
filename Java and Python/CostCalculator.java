/* this program is made to take inputs of food quantity and price from the user, as well as tax ability, and 
 * calculate the cost of purchasing the food. It also greets the user by name based 
 * on the number they initially input */
import java.util.Scanner;
public class CostCalculator {
	//create class constants
	final static Scanner CONSOLE = new Scanner(System.in);
	final static double TAX_RATE = 0.0625;

	public static void main(String[] args) {
		
		//create the five customer IDs
		String sarah = "Sarah";
		String john = "John";
		String matthew = "Matthew";
		String michelle = "Michelle";
		String ethan = "Ethan";
		
		//create header; welcome and prompt user
		
		System.out.println("Welcome to your preferred store.");
		System.out.print("What's your customer ID?");
		int name = CONSOLE.nextInt();
		
		//based on number(1-5), print out a name
		//use a while loop to require the user to input values until they input a number between 1-5
		
		while(name < 1 || name > 5) {
			System.out.print("Try again, please: Between 1 and 5.");
			name = CONSOLE.nextInt();
		}
		if(name == 1) {
			System.out.println("Welcome " + sarah + "!");
		}
		if(name == 2) {
			System.out.println("Welcome " + john + "!");
		}
		if(name == 3) {
			System.out.println("Welcome " + matthew + "!");
		}
		if(name == 4) {
			System.out.println("Welcome " + michelle + "!");
		}
		if(name == 5) {
			System.out.println("Welcome " + ethan + "!");
		}
		
		/*establish sub-total variable for use in the for loop,
		 as well as item total and quantity, tax and number of items*/
		
		double subtotal = 0;
		double itemTotal = 0;
		double itemQuantity = 0;
		double itemTax = 0;
		double subTotalAll = 0;
		double taxAll = 0;
		int numItems;
		int taxable;
		
		//create the for loop, where i(iterations) is equal to the number of items being bought
		
		System.out.print("How many items are you buying?");
		numItems = CONSOLE.nextInt();
		
		for(int i = 1; i <= numItems; ++i) {
			System.out.print("Enter quantity of item " + i + ": ");
			itemQuantity = CONSOLE.nextDouble();
			System.out.print("Enter price of item " + i + ": ");
			itemTotal = CONSOLE.nextDouble();
			//calculate sub-total
			subtotal = (itemTotal * itemQuantity);
			//check for tax and calculate
			System.out.print("Is item " + i + " taxable? 1 - Yes or 0 - No ");
			taxable = CONSOLE.nextInt();
			//create while loop for input other than 1 or 0
			
			while(taxable < 0 || taxable > 1) {
				System.out.print("Try again, please: 1 - Yes or 0 - No ");
				taxable = CONSOLE.nextInt();
			}
			//print out item sub-total and tax(if stated yes)
			if(taxable == 1) {
				itemTax =  (subtotal * TAX_RATE);
				System.out.println("Item " + i + " subtotal is: " + subtotal);
				System.out.println("Item " + i + " tax: " + itemTax);
				taxAll = taxAll + itemTax;
			}
			if(taxable == 0){

				System.out.println("Item " + i + " subtotal is: " + subtotal);
			}
			//create overall sub-total
			
			subTotalAll = subTotalAll + subtotal;
			
		}
		//create footer(receipt)
		System.out.println("------------------------------");
		System.out.println("Subtotal: $" + subTotalAll);
		System.out.println("Tax: $" + taxAll);
		System.out.println("Total: $" + (subTotalAll + taxAll));
		System.out.println("Thank you for shopping with us!");

	}

}
