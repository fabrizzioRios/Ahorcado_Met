import random

class Coche:
    def __init__(self, marca: str, kilom: int, edad: int):
        self.marca = marca
        self.kilom = kilom
        self.edad = edad

    def check_engine(self):
        if self.kilom < 20000 and self.edad <= 5:
            print(f"Tu {self.marca} esta bien, su kilometraje es {self.kilom} y su edad es de {self.edad} años")
            print(f"Por la edad de tu auto, te recomendariamos que lo llevaras al taller para alargar la vida del auto")

        if (self.kilom > 20000 and self.kilom < 40000) and (self.edad > 5 and self.edad < 10):
            print(f"Se recomienda ir al servicio, su kilometraje de {self.kilom} es mayor al recomendado y su edad de {self.edad} tambien es mayor a la recomendada ")

        if self.kilom > 40000 and self.edad > 10:
            print(f"Check Engine Error\n Debe ir al servicio inmediatamende su kilometraje de {self.kilom} "
                  f"y su edad de {self.edad} pueden dejar inservible el auto")


kilometraje = random.randint(0, 50000)
edad = random.randint(0, 15)

Mycar = Coche("Volkswagen", kilometraje, edad)
Mycar.check_engine()
