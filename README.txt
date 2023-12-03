Para ejecutar el conversor a escala de grises con hebras, sigue estos pasos: 
1.Abre la terminal y navega hasta la carpeta thread
2.Ejecuta el comando make o make openmp para compilar el programa 
3.Despues de compilar, utiliza el siguiente formato para ejecutar el programa, ingresando la imagen a convertir, el nombre para el archivo de la imagen convertida y el numero de hebras que deseas utilizar
Donde "imagen a convertir.jpg" es el nombre de la imagen que deseas convertir
4.Si deseas eliminar el codigo ya compilado, puedes utilizar el comando make clean en la terminal. 

Ten en cuenta que la imagen a convertir debe estar en el mismo directorio que el archivo "main.cpp". En caso contrario, especifica la ruta correcta en el parametro correspondiente. 