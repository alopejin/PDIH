import cv2
import sys

#Ejercicio 2: Detección de caras en vídeos

modelo = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

nombre_video = sys.argv[1]

video = cv2.VideoCapture(nombre_video)

while video.isOpened():
    ret, frame = video.read()
    if not ret:
        break

    gris = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    caras = modelo.detectMultiScale(gris, scaleFactor=1.1, minNeighbors=4)

    for (x, y, w, h) in caras:
        cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 2)

    cv2.imshow('Ejercicio 2 - Caras en video', frame)
    if cv2.waitKey(1) & 0xFF == 27:
        break

video.release()
cv2.destroyAllWindows()
