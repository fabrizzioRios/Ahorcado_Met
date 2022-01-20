print("Hello world")


# creamos nuestra clase Persona

class Persona:

    # inicializamos nuestros atributos

    def __init__(self, nombre: str, edad: int):

        self.nombre = nombre

        self.edad = edad

    # imprimimos los datos

    def imprimir(self):

        print(f"\nSu nombre es: {self.nombre} y su edad es: {self.edad}")

    # comprobamos si es mayor de edad o no

    def mayor_edad(self):

        if self.edad >= 18:

            print("\nEs mayor de edad")

        else:

            print("\nNo es mayor de edad")


person_amount = int(input(print("\n¿Cuantas personas son?\n")))
if person_amount == 1:

    # bloque principal

    nombre = str(input(print("\n¿Cual es su nombre?")))
    edad = int(input(print("¿Cual es su edad?\n")))

    persona1 = Persona(nombre, edad)

    # imprimimos datos y comprobamos si es mayor de edad
    persona1.imprimir()
    persona1.mayor_edad()

elif person_amount > 1:

    des = range(person_amount)

    for person in des:
        nombre = str(input(print("\n¿Cual es su nombre?")))
        edad = int(input(print("¿Cual es su edad?\n")))

        persona = Persona(nombre, edad)

        persona.imprimir()
        persona.mayor_edad()
else:
    print("No es un valor valido")
