def apply_discount(price):

    return price * 0.05

def checkout(item_price, tax):

    discounted_price = apply_discount(item_price)
    return discounted_price + tax

filnal_price = checkout(1000, 100)
print(f'Final price: (final_price)')
