'''
Here is a shopping cart script, The developer says it should calculate the total price with quantity and a dicsount rule 
- but the final total is wrong.

Business requirement --> if cost more than 500 offer 10% discount.
'''


def calculate_item_total(price, quantity):
    return price * quantity

def apply_discount(subtotal):
    if subtotal > 500:
        return subtotal * 0.1
    return 0

def calculate_cart_total(cart_items):
    total = 0
    total_discount = 0

    for item in cart_items:
        name = item["name"]
        price = item["price"]
        quantity = item["quantity"]

        item_total = calculate_item_total(price, quantity)
        discount = apply_discount(item_total)

        print(f"{name} - Subtotal: {item_total}, Discount: {discount}")

        total += item_total - discount
        total_discount += discount

    return total, total_discount

cart = [
    {"name": "Keyboard", "price": 200, "quantity": 2},
    {"name": "Monitor", "price": 600, "quantity": 1},
    {"name": "USB Cable", "price": 100, "quantity": 1}
]

final_total, total_discount = calculate_cart_total(cart)
print("\nFinal Total:", final_total)
print("Total Discount Applied:", total_discount)