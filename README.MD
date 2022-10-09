# Examen de paradigmas de programación

## Estudiante: Alexander B. Gutiérrez.

Instrucciones: Desarrollar los siguientes procedimientos en los siguientes lenguajes de programación Cobol, y C++. **15 pts** cada procedimiento.
- 10 pts corresponderán a la descripción del entorno de desarrollo utilizado por lenguaje.

- Puntos Extras: 15 pts demuestren que lograron implementar recursividad en los dos lenguajes para ambos problemas.

### Problema 1. Diseñar y desarrollar el siguiente procedimiento. (Cobol, y C++.) C/U 15 pts

> Diseñar y Desarrollar una aplicación que, dado un vector de números reales, escriba un método que ordene 
>los elementos del vector de tal forma que los números pares aparezcan antes que los números impares. 
>Además, los números pares deberán estar ordenados de forma ascendente, mientras que los números impares 
>deberán estar ordenados de forma descendente. Esto es, el vector `{1,2,3,4,5,6}` quedará como `{2,4,6,5,3,1}`.

### Problema 2. Diseñar y desarrollar el siguiente procedimiento. (Cobol, y C++.) C/U 15 pts

> Crear una clase Matriz para manipular matrices que encapsule un array bidimensional de números reales.
>1. Incluya en la clase métodos que nos permitan acceder y modificar de forma segura los elementos de la matriz (esto es, las variables de instancia deben ser privadas y los métodos han de comprobar la validez de sus parámetros).
>2. Escriba un método que nos permita sumar matrices.
>3. Implemente un método que nos permita multiplicar matrices.
>4. Cree un método con el que se obtenga la traspuesta de una matriz.


### Implementación resultante.

Dentro de la carpeta include podra encontrar la documentación adecuada tanto para las funciones del
ejercicio #1, como la definición de la clase template de una matriz. <br/>
Por otro lado, en la carpera SRC podra encontrar un ejemplo del programa ejecutando:<br/>

`❯ g++ *.cpp -o ./../bin/main` 
`╰─ ./../bin/main --test` 
<br/>

En cuanto a cobol, en la carpeta COBOl, encontrara los programas homologos a los contruidos en c++
pero con algo menos de estilo, por lo cual me disculpo. Podra ejecutarlos de la siguiente manera: <br/>

`cobc -x ex2.cbl`
`./ex{k}` 
<hr>

- NOTE: Altere K para cambiar los ejercicios, cada código fuente trae instrucciones por si mismas, y cada carpeta BIN cuenta con ejecutables simplemente para facilitar algunos aspectos.
