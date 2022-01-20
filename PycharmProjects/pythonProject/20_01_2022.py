import random


class Animal:
    def __init__(self, name: str, age: int = 0):
        self.name = name
        self.age = age


class Dog(Animal):
    def bark(self):
        print(f"{self.name} said Wof wof")


class Cat(Animal):
    def jump(self):
        height = random.randint(0, 100)
        print(f"{self.name} has jumped {height} meters")


class Parrot(Animal):
    def fly(self):
        distance = random.randint(0, 100)
        print(f"{self.name} has flown {distance} meters")


Doberman = Dog("Max", 10)
Michi = Cat("Michi", 5)
Cucu = Parrot("Cucu", 3)

print(f"{Doberman}, {Doberman.name}, {Doberman.age}")
print(f"{Michi}, {Michi.name}, {Michi.age}")
print(f"{Cucu}, {Cucu.name}, {Cucu.age}")

Array = [Doberman, Michi, Cucu]

print(f"{Array[0].bark()}")

Molly = Dachshund()
