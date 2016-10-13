package shoppingsite;

import shoppingsite.ShoppingTest.PaymentType;

public class Payment {
	private PaymentType type;
	
	/* Add a payment type based on the enum
	 * PaymentType in the ShoppingTest class. */
	public void setPaymentType(PaymentType type) {
		this.type = type;
	}
	
	/* Verify whether or not the payment has gone through by
	 * approving some payment types and rejecting others. */
	public boolean verify() {
		switch (this.type) {
		case CREDIT_CARD: case DEBIT_CARD:
			return true;
		case BITCOIN: default:
			return false;
		}
	}

}
