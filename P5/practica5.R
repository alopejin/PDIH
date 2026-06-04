library(tuneR) 
library(seewave) 
library(audio) 

#Ejercicio 2
nombre <- readWave("nombre.wav")
apellidos <- readWave("apellidos.wav")

duracion_nombre <- length(nombre@left)
duracion_apellidos <- length(apellidos@left)

plot( extractWave(nombre, from = 1, to = duracion_nombre) )
plot( extractWave(apellidos, from = 1, to = duracion_apellidos) )

#Ejercicio 3
str(nombre)
str(apellidos)

#Ejercicio 4
nombre_apellidos <- pastew(apellidos, nombre, output="Wave")

#Ejercicio 5
duracion_nombre_apellidos <- length(nombre_apellidos@left)
plot( extractWave(nombre_apellidos, from = 1, to = duracion_nombre_apellidos) )

listen(nombre_apellidos)

#Ejercicio 6
writeWave(nombre_apellidos, "basico.wav")

#Ejercicio 7
filtrado <- bwfilter(nombre_apellidos,f=nombre_apellidos@samp.rate, channel=1, n=1, from=10000, to=20000, bandpass=TRUE, listen = FALSE, output = "Wave")
writeWave(filtrado, "filtrado.wav")

#Ejercicio 8
eco <- echo(filtrado, f=filtrado@samp.rate, amp=c(0.8,0.4,0.2), delay=c(1,2,3), output="Wave")
eco@left <- eco@left * 30000
writeWave(eco, "eco.wav")

alreves <- revw(eco, output="Wave") 
alreves <- normalize(alreves, unit = "16")
writeWave(alreves, "alreves.wav")


