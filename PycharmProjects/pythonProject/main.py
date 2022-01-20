
class Car:
    pay_rate = 0.8  # The pay rate after 20% of discount

    def __init__(self, name: str, price: int, quantity: int):
        # Run validations to the received arguments

        # Assign to self object
        self.name = name
        self.price = price
        self.quantity = quantity

    def calculate_total_price(self):
        return self.price * self.quantity

    def apply_discount(self):
        self.price = self.price * self.pay_rate


car1 = Car("Mercedes", 100, 3)
car2 = Car("Audi", 200, 1)
car1.apply_discount()
print(car1.price)
car2.pay_rate = 0.01
car2.apply_discount()
print(car2.price)

# print(Car.__dict__) #All the attributes for Class level
# print(car1.__dict__) #All the attributes for instance level

