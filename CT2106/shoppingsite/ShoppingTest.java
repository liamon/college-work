package shoppingsite;

public class ShoppingTest {
	enum PaymentType { CREDIT_CARD, DEBIT_CARD, BITCOIN }
	
	public static void main(String[] args) {
		Customer customer = new Customer();
		ShoppingCart cart = customer.getCart();
		Item[] items = new Item[4];
		
		int total;
		Order order;
		Payment payment;
		boolean isPaymentVerified;
		Email email;
		
		items[0] = new Item(350, 64375L);
		items[1] = new Item(22, 867909L);
		items[2] = new Item(45, 48319L);
		items[3] = new Item(120, 1253617L);
		
		cart.addItem(items[0]);
		cart.addItem(items[1]);
		cart.addItem(items[2]);
		cart.addItem(items[3]);
		
		total = cart.getTotal();
		if (total == 350 + 22 + 45 + 120) {
			System.out.printf("The total is the correct value of %d.\n\n", total);
		} else {
			System.out.print("The value of the total is incorrect.\n\n");
		}
		cart.removeItem(48319L);
		
		order = cart.finalise();
		order.setDeliveryAddress("10 Downing Street, London, United Kingdom");
		order.setBillingAddress("10 Downing Street, London, United Kingdom");
		
		payment = order.finalise();
		payment.setPaymentType(PaymentType.CREDIT_CARD);
		isPaymentVerified = payment.verify();
		email = new Email(order, isPaymentVerified);
		email.send();
	}
}
