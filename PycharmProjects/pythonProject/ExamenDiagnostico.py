import random

from time import sleep


class Car:
    def __init__(self, tanque_gas: int):
        self.tanque_gas = tanque_gas


def llenar_gas():
    opt = int(input(print("¿Desea llenar el tanque?\n si = 1\n no = 0")))
    if opt == 1:
        car1.tanque_gas = var
        tot = car1.tanque_gas = 50
        print(f"Su gasolina es {tot} litros de gasolina")
        sleep(2)
    elif opt == 0:
        lit = int(input(print("¿Cuantos litros necesita?")))
        car1.tanque_gas = var
        tot = car1.tanque_gas + lit
        print(f"Su gasolina es {tot} litros de gasolina")
        sleep(2)


def checar_gas():
    car1.tanque_gas = var
    gas = car1.tanque_gas
    des = int(input(print(f"Su tanque contiene {gas} litros de gasolina, ¿Le gustaria recargar gasolina?\n si=1 \n no=0")))
    sleep(2)
    if des == 1:
        llenar_gas(var)
    else:
        pass


loop = 0

while loop == 0:
    n = random.randint(0, 50)
    car1 = Car(n)

    if n < 15:
        des = int(input(print("Bienvenido usuario,¿Que desea realizar?\n 1.- Recargar gasolina\n "
                              "2.- Checar cuanta gasolina tiene\n 3.- Salir")))
        var = n
        if des == 1:
            llenar_gas(var)
        elif des == 2:
            checar_gas(var)
        elif des == 3:
            loop = 1

        else:
            print("No es una decision valida")
    elif n > 40 or n == 50:
        print("Su tanque tiene suficiente combustible")
        sleep(2)
