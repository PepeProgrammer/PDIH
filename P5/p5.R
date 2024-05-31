
# install.packages('tuneR', dep=TRUE)
# install.packages('seewave', dep=TRUE)
# install.packages('soundgen', dep=TRUE)

library(tuneR)
library(seewave)
#library(soundgen)
library(audio)

# establecer el path concreto en cada caso a la carpeta de trabajo
setwd("./Desktop/PDIH/P5")


# cargar archivos de sonido (wav/mp3):
nombre <- readWave('nombre.wav')
nombre
apellido <- readWave('apellidos.wav')
apellido


# mostrar los campos del archivo de sonido
str(nombre)
str(apellido)

# calcular la duración exacta del sonido (con tres decimales)
round(length(nombre@left) / nombre@samp.rate, 3)


f <- nombre@samp.rate    #44100

# mostrar la onda del sonido:
oscillo(nombre)
oscillo(apellido)


# escuchar una porción del sonido original:
listen(nombre, f=f, from=1.5, to=2.5)

#Obtenemos las cabeceras de los audios
summary(nombre)
summary(apellido)

# cortar segmentos de un objeto “wave”:
nombre_corto <- cutw(nombre, from=1.5,to=2.5, output="Wave")
nombre_corto
oscillo(nombre_corto)
listen(nombre_corto)

apellido_corto <- cutw(apellido, from=1.3,to=2.5, output="Wave")
apellido_corto
oscillo(apellido_corto)
listen(apellido_corto)

#unimos los 2 sonidos cortados

union <- pastew(apellido_corto, nombre_corto, output="Wave")
oscillo(union)
listen(union)

#aplicamos filtro de frecuencia
filtro <- bwfilter(union,f=f, channel=1, n=1, from=10000, 
                  to=20000, bandpass=TRUE, listen = FALSE, output = "Wave")
oscillo(filtro)
listen(filtro)

str(filtro)

#Normalizamos el filtro
nfiltro <- normalize(filtro, unit = "16") 


#Guardar sonido
writeWave(nfiltro, file.path("mezcla.wav")) 
listen(nfiltro)

#cargamos el archivo
nom_ap <- readWave('mezcla.wav')

nom_ap <- echo(nom_ap,f=f,amp=c(0.8,0.4,0.2),delay=c(1,2,3), 
                output="Wave")
listen(nom_ap)

alreves <- revw(nom_ap, output="Wave")
listen(alreves)

#Normalizamos el filtro
alreves <- normalize(alreves, unit = "16") 

# Convertir los datos a enteros
alreves@left <- as.integer(alreves@left)


writeWave(alreves, file.path("alreves.wav")) 


