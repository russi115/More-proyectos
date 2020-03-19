import random
print("El juego del ahorcado ha iniciado")

intento = 1
board = []

palabras = ["CAMISA", "COMPUTADORA", "LENTES", "pantalones"]
palabra = random.choice(palabras).upper()
letras_incorrectas = set()
letras_correctas = set()

# Esto sirve para ense�ar la cantidad de espacios que contiene la palabra.
for i in range(len(palabra)):
    board.append("__ ")

print(''.join(board))

turnos = len(palabra)
while turnos >= intento:
    letra = input(str(intento) + "� intento: ").upper()
    print(letra)
    isValid = True

    if len(letra) > 1 or len(letra) == 0 or letra == " ":
        print("Escriba una sola letra por favor")
        isValid = False

# Variable para determinar si el intento de letra fue correcto.
    isCorrect = False

    if isValid:
        if letra in letras_correctas or letra in letras_incorrectas:
            print("Ya escribio esa letra!")
            isCorrect = True

        for i in range(turnos):
            if letra == palabra[i]:
                isCorrect = True
                board[i] = letra
                letras_correctas.add(letra)

    if not isCorrect and isValid:
        intento += 1
        letras_incorrectas.add(letra)
        print('La letra ' + letra + ' no es correcta')

    # Si se acaban los intentos, se termina el juego
    if intento > turnos:
        print("Perdiste!")

    if ''.join(board) == palabra:
        print('Ganaste!')
        print(''.join(board))
        break

    print(''.join(board))
