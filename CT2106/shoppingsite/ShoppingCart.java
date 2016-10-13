package shoppingsite;
import java.util.ArrayList;

public class ShoppingCart {
	private ArrayList<Item> items;
	
	/* Constructor which instantiates a ShoppingCart object with an ArrayList of items. */
	public ShoppingCart() {
		this.items = new ArrayList<Item>(4);
	}
	
	/* Adds an item to the shopping cart */
	public void addItem(Item item) {
		this.items.add(item);
	}
	
	/* Goes through each item in the ArrayList items, adds the cost of
	 * each one to a total and returns the total cost of all items. */
	public int getTotal() {
		int total = 0;
		for (Item item : items) {
			total += item.getCost();
		}
		return total;
	}
	
	/* Finalise the Order by creating an instance of Order. */
	public Order finalise() {
		Order order = new Order(items);
		return order;
	}
	
	/* Given an ID, looks through the IDs of each item and
	 * removes the item with the matching ID from the cart. */
	public void removeItem(long id) {
		int i;
		for (i = 0; i < items.size(); i++) {
			if (items.get(i).getID() == id) {
				break;
			}
		}
		items.remove(i);
	}
}
