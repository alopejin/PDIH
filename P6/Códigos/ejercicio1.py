import cv2
import sys

#Ejercicio 1: Detección de caras en imágenes

modelo = cv2.CascadeClassifier('haarcascade_frontalface_alt.xml')

nombre_imagen = sys.argv[1]

imagen = cv2.imread(nombre_imagen)
gris = cv2.cvtColor(imagen, cv2.COLOR_BGR2GRAY)

caras = modelo.detectMultiScale(gris, scaleFactor=1.05, minNeighbors=5)

print(f"Se han detectado {len(caras)} rostro(s)")

for (x, y, w, h) in caras:
    cv2.rectangle(imagen, (x, y), (x + w, y + h), (0, 255, 0), 2)

cv2.imshow('Ejercicio 1 - Caras en imagen', imagen)
cv2.waitKey(0)
cv2.destroyAllWindows()
