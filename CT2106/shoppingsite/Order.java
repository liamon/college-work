package shoppingsite;
import java.util.ArrayList;

public class Order {
	private ArrayList<Item> items;
	private String deliveryAddress;
	private String billingAddress;
	
	/* Instantiates an Order object with an ArrayList of items. */
	public Order(ArrayList<Item> items) {
		this.items = items;
	}
	
	/* Finalise the order by instantiating a Payment object. */
	public Payment finalise() {
		Payment payment = new Payment();
		return payment;
	}
	
	/* Getter which returns the ArrayList of Item objects. */
	public ArrayList<Item> getItems() {
		return this.items;
	}
	
	/* Setters and getters for the delivery and billing addresses. */
	public void setDeliveryAddress(String deliveryAddress) {
		this.deliveryAddress = deliveryAddress;
	}
	public void setBillingAddress(String billingAddress) {
		this.billingAddress = billingAddress;
	}
	public String getDeliveryAddress() {
		return this.deliveryAddress;
	}
	public String getBillingAddress() {
		return this.billingAddress;
	}
}
