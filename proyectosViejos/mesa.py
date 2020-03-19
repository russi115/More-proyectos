def mesa():


global variable_global
if Opcion == 1:

        print("Cuanto deseas acreditar a tu balance? (Solo Numeros Enteros)")
        Acreditacion = int(input())
        ActualizarSaldo(Acreditacion)
        print('')

        print("Tu saldo actual es: ", SaldoActual)

        Numero = NumeroAleatorio()

        print("Numero generado: ", Numero)

        Opcion = 0


print("Hola")

mesa()
