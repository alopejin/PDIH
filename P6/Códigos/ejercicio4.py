import cv2
import sys

#Ejercicio 4: Detección simultánea de cuerpos y caras en vídeos

modelo_cara = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
modelo_cuerpo = cv2.CascadeClassifier('haarcascade_fullbody.xml')

nombre_video = sys.argv[1]

video = cv2.VideoCapture(nombre_video)

while video.isOpened():
    ret, frame = video.read()
    if not ret:
        break

    gris = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    caras = modelo_cara.detectMultiScale(gris, scaleFactor=1.1, minNeighbors=4)
    cuerpos = modelo_cuerpo.detectMultiScale(gris, scaleFactor=1.1, minNeighbors=3)

    for (x, y, w, h) in caras:
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)
        cv2.putText(frame, 'Cara', (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 255, 0), 2)

    for (x, y, w, h) in cuerpos:
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 0, 255), 2)
        cv2.putText(frame, 'Cuerpo', (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 0, 255), 2)

    cv2.imshow('Ejercicio 4 - Cuerpos y caras', frame)
    if cv2.waitKey(1) & 0xFF == 27:
        break

video.release()
cv2.destroyAllWindows()
