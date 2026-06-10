import cv2
import sys

#Ejercicio 3: Detección de caras de gatos en vídeos

modelo = cv2.CascadeClassifier('haarcascade_frontalcatface_extended.xml')

nombre_video = sys.argv[1]

video = cv2.VideoCapture(nombre_video)

while video.isOpened():
    ret, frame = video.read()
    if not ret:
        break

    gris = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    gatos = modelo.detectMultiScale(gris, scaleFactor=1.05, minNeighbors=5)

    for (x, y, w, h) in gatos:
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 165, 255), 2)
        cv2.putText(frame, 'Gato', (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 165, 255), 2)

    cv2.imshow('Ejercicio 3 - Gatos en video', frame)
    if cv2.waitKey(1) & 0xFF == 27:
        break

video.release()
cv2.destroyAllWindows()
