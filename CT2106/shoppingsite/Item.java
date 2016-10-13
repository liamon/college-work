package shoppingsite;

public class Item {
	private int cost;
	private long id;

	/* Constructor which instantiates an Item object with a cost and an ID. */
	public Item(int cost, long id) {
		this.cost = cost;
		this.id = id;
	}
	
	/* Getters to return the cost and ID of an instance of Item. */
	public int getCost() {
		return this.cost;
	}
	public long getID() {
		return this.id;
	}
	
}
