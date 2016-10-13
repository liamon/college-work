package shoppingsite;

public class Customer {
	private ShoppingCart cart;
	
	/* Constructor which instantiates a Customer object
	 * with an instance of a ShoppingCart object. */
	public Customer() {
		this.cart = new ShoppingCart();
	}
	
	/* Getter which returns the ShoppingCart object to other objects. */
	public ShoppingCart getCart() {
		return this.cart;
	}
}
