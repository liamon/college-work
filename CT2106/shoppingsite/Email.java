package shoppingsite;
import java.util.ArrayList;

public class Email {
	private Order order;
	private boolean paymentSuccess;
	private ArrayList<Item> items;
	private int totalCost = 0;
	
	/* Constructor which instantiates an Email object with
	 * the order and whether or not the payment succeeded. */
	public Email(Order order, boolean paymentSuccess) {
		this.order = order;
		this.paymentSuccess = paymentSuccess;
		this.items = order.getItems();
	}
	
	/* "Send an email" (really print out to the screen) about the order, going through each member
	 * of the ArrayList items to print out each ID and cost individually and to get a total cost. */
	public void send() {
		System.out.print("Thank you for shopping with us.\n\n");
		if (this.paymentSuccess == false) {
			System.out.println("Unfortunately, this order was unsuccessful.");
		} else {
			System.out.println("ITEM NUMBERS:      COSTS:");
			for (Item item : items) {
				long id = item.getID();
				int cost = item.getCost();
				System.out.printf("%-11d %12d\n", id, cost);
				totalCost += cost;
			}
			System.out.printf("TOTAL COST: %12d\n\n", totalCost);
			System.out.printf("Delivering to:\n%s\n\n", order.getDeliveryAddress());
			System.out.printf("Billed to:\n%s\n\n", order.getBillingAddress());
		}
	}
}
