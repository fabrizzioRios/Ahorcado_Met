
class Car:
    def __init__(self, color: str, mileage: int):
        self.color = color
        self.mileage = mileage

    def show_c(self):
        print(f"The {self.color} car has {self.mileage} miles")

blue_car = Car("blue", 20000)
red_car = Car("red", 30000)

blue_car.show_c()
red_car.show_c()
