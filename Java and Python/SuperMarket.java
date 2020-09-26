import java.util.*;
public class SuperMarket {
	//this code will accept an input for a customer ID, allow a user to input which foods they are purchasing and in what quantity,
	//calculating subtotal, tax, and applicable discounts, and returning a receipt with the user's total cost of purchase
	
	//class constants
	final static Scanner CONSOLE = new Scanner(System.in);
	final static double TAX_RATE = 0.0625;
	final static double MINOR_DISCOUNT = .1;//for under 19
	final static double SENIOR_DISCOUNT = .2;//for over 59
	
	//arrays for user actions, customer name, types of food and drink, cost of each food or drink, age of each possible user, and whether items can be taxed or not
	public static String actionDesc[] = {"Finish transaction", "Add to cart", "Cancel transaction"};
	static String[] name = {"Aaron", "Priscilla", "Marty", "John", "Bob", "Alicia", "Eve", "Jospeh", "Michael", "Donald"};
	static String[] itemInfo = {"Beans", "Rice", "Banana", "Ice", "Tea", "Bread", "Orange", "Sugar"};
	static double[] itemCost = {3.25, 4.31, 6.88, 3.30, 5.25, 4.89, 6.32, 2.25};
	static int[] age = {18, 15, 42, 25, 29, 75, 15, 38, 62, 68};
	static double[] tax = {0, 0, 0, 1, 1, 0, 0, 1};
	
	//prints header welcoming user 
	public static void printReceiptHeader(){
		  System.out.println("Welcome to your UTSA - Supermarket");
	    
	  }
	
	//prints receipt and goodbye statement
	public static void printReceiptFooter(double subTotalCost, double discountAmount, double taxCost, int customerID){
		System.out.println("---------------------------------");
		System.out.println("Subtotal             :  $ " + subTotalCost);
		
		if(discountAmount == 0.0) {
			System.out.println("                 Tax :  $ " + taxCost);
			System.out.println("---------------------------------");
			System.out.println("Total:               :  $ " + ((subTotalCost + taxCost)));
		}
		if(discountAmount == 0.1) {
			System.out.println("Discount minor       : -$ " + (discountAmount * subTotalCost)); 
			System.out.println("---------------------------------");
			System.out.println("Real Sub-Total:      :  $ " + (subTotalCost - (discountAmount * subTotalCost)));
			System.out.println("                 Tax :  $ " + taxCost);
			System.out.println("---------------------------------");
			System.out.println("Total:               :  $ " + ((subTotalCost - (discountAmount * subTotalCost)) + taxCost));
		}
		if(discountAmount == 0.2) {
			System.out.println("Discount senior       : -$ " + (discountAmount * subTotalCost)); 
			System.out.println("---------------------------------");
			System.out.println("Real Sub-Total:      :  $ " + (subTotalCost - (discountAmount * subTotalCost)));
			System.out.println("                 Tax :  $ " + taxCost);
			System.out.println("---------------------------------");
			System.out.println("Total:               :  $ " + ((subTotalCost - (discountAmount * subTotalCost)) + taxCost));
			
		}
		System.out.println("---------------------------------");
		System.out.println("---------------------------------");
		System.out.println("Thank you for your purchase, " + name[customerID] + "!");
		System.out.println("We hope to see you back soon!");
		
	}
	
	
	 //prompts the user and receives an input 
	 public static int getValidInput(String choices, String option, int totalChoices, String indentation){
		    int val = -1;
		    displayMessage(indentation + option + ":" + indentation +  choices + "\n");
		    displayMessage(indentation + "Select a/an " + option + ": ");
		    val = CONSOLE.nextInt();
		    while(val > totalChoices - 1 || val < 0) {
		    	displayMessage(indentation + "The selected " + option + " is invalid, please, try again\n");
		    	displayMessage(indentation + option + ":" + indentation +  choices + "\n");
		    	displayMessage(indentation + "Select a/an " + option + ": ");
		    	val = CONSOLE.nextInt();
		    }
		   
		    return val;
		  }
	 
	 //displays a string
	 public static void displayMessage(String str){
		 System.out.print(str);
		 
		  }
	 
	 //uses getValidInput to prompt user for customer ID
	 public static int getCustomerID(){
		    int customer = -1;
		    String option = "customer";
		    int totalChoices = name.length;
		    String indent = "";
		    customer = getValidInput(getArrayList(name), option, totalChoices, indent);
		    
		    return customer;
		  }
	 
	 //converts array into a string list using a for loop
	 public static String getArrayList(String[] list){
		    String str = "";
		    for(int i = 0; i < list.length; i++) {
		    	str = str + (i + "-" + list[i] + " ");
		    }
		    return str;
		  }
	 
	 //prompts user for quantity of food or drink selected, and recieves an input
	 public static double getQuantity(String prompt){
		    double val = -1;
		    displayMessage(prompt);
		    val = CONSOLE.nextDouble();
		    
		    return val;
		  }
	 
	 //method that calls previous methods, and uses said methods to calculate the subtotal, tax and discount amount of the transaction
	 public static void genTransaction(){
		 double subtotal = 0;
		 double itemTax = 0;
		 double subTotalAll = 0;
		 double taxAll = 0;
		 double numItems = 0;
		 double discountAmount = 0;
		 String indent = " ";
		 String indent1 = "";
		 String indent2 = "  ";
		 
		 //prompts user for customer ID, followed by a prompt for action
		 int customerID = getCustomerID();
		 System.out.println();
		 String prompt2 = "action";
		 int actionLength = actionDesc.length;
		 int nextChoice = getValidInput(getArrayList(actionDesc), prompt2, actionLength, indent1);
		 
		 //if user cancels transaction, the program ends automatically
		 if(nextChoice == 2) {
			 System.out.println("Transaction aborted");
			 System.exit(0);
		 }
		 
		 
		 //if users picks to add to cart, they pick a food or drink
		 if(nextChoice == 1) {
			System.out.println(" item:" + getArrayList(itemInfo));
			 String prompt3 = " Select a/an item: ";
			 String prompt4 = "item";
			int foodChoices = itemInfo.length;
			double itemNum = getQuantity(prompt3);
			while(itemNum > itemInfo.length - 1) {
				System.out.println(" The selected item " + (int)itemNum + " is invalid, please, try again");
				System.out.println(" item:" + getArrayList(itemInfo));
				itemNum = getQuantity(prompt3);
			}
			
			
			//get tax and subtotal
			String option = (" How much/many of " + itemInfo[(int) itemNum] + " do you want to buy?");
			numItems = getQuantity(option);
			subtotal = itemCost[(int) itemNum] * numItems;
			if(tax[(int) itemNum] == 0 ) {
				itemTax = 0;
				subTotalAll = subTotalAll + subtotal;
			}
			if(tax[(int) itemNum] == 1 ) {
				itemTax =  (subtotal * TAX_RATE);
				taxAll = taxAll + itemTax;
				subTotalAll = subTotalAll + subtotal;
			}
			
			//check for discount
			if(age[customerID] < 19) {
				discountAmount = MINOR_DISCOUNT;
			 
			}
			if(age[customerID] > 59) {
				discountAmount = SENIOR_DISCOUNT;
			}
		 
			//repeat request for action following completion of first request; statement will be followed by a while loop	 
			nextChoice = getValidInput(getArrayList(actionDesc), prompt2, actionLength, indent1);
			
			if(nextChoice == 2) {
				System.out.println("Transaction aborted");
				System.exit(0);
			}
		 
			
			//continue to get tax and subtotal until user is done
			while(nextChoice == 1) {
				
				System.out.println(" item:" + getArrayList(itemInfo));
				itemNum = getQuantity(prompt3);
				while(itemNum > itemInfo.length - 1) {
					System.out.println(" The selected item " + (int)itemNum + " is invalid, please, try again");
					System.out.println(" item:" + getArrayList(itemInfo));
					itemNum = getQuantity(prompt3);
				}
				
				option = (" How much/many of " + itemInfo[(int) itemNum] + " do you want to buy?");
				numItems = getQuantity(option);
				subtotal = itemCost[(int) itemNum] * numItems;
				if(tax[(int) itemNum] == 0 ) {
					itemTax = 0;
					subTotalAll = subTotalAll + subtotal;
				}
				if(tax[(int) itemNum] == 1 ) {
					itemTax =  (subtotal * TAX_RATE);
					taxAll = taxAll + itemTax;
					subTotalAll = subTotalAll + subtotal;
				}
			 
				if(age[customerID] < 19) {
					discountAmount = MINOR_DISCOUNT;
				 
				}
				if(age[customerID] > 59) {
					discountAmount = SENIOR_DISCOUNT;
				}
				
				nextChoice = getValidInput(getArrayList(actionDesc), prompt2, actionLength, indent1);
			
		 }
		 }
		 
		 if(nextChoice == 2) {
			 	System.out.println("Transaction aborted");
				System.exit(0);
			}
		 //print the receipt and goodbye message
		 printReceiptFooter(subTotalAll, discountAmount, taxAll, customerID);
			
		}
	public static void main(String[] args) {
		
		//print header
		printReceiptHeader();
		
		//call genTransaction method
		genTransaction();
		
	}

}
