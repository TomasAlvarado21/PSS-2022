=================================================
Esta es la documentación para compilar y ejecutar
=================================================

Se está ejecutando el comando: less README.txt

***************************
*** Para salir: tecla q ***
***************************

Para avanzar a una nueva página: tecla <page down>
Para retroceder a la página anterior: tecla <page up>
Para avanzar una sola línea: tecla <enter>
Para buscar un texto: tecla / seguido del texto (/...texto...)
         por ejemplo: /ddd

-----------------------------------------------

Este directorio contiene los siguientes programas:

variables.c: Ejemplos de uso de variables y punteros
string.c: Ejemplos de uso de strings
malloc-segfault.c: Modifica el string constante "hello" gatillando seg. fault
malloc-strcpy.c: Usa strcpy para crear una copia de "hello" y modificarlo (*)
malloc-bad.c: La función copiar retorna la direccion de un arreglo local
malloc-good.c: La función copiar retorna un arreglo dinámico usando malloc (*)
malloc-leak.c: No se libera el arreglo, convirtiéndose en un memory leak
malloc-dangling.c: Se usa el arreglo después de haberlo liberado con free

Las únicas versiones correctas son las marcadas con (*)

-----------------------------------------------

Maneras de compilar y ejecutar malloc-bad.c y el resto de los programas:

make malloc-good.run: Compila y ejecuta con opciones de optimización
make malloc-good.run-g: Compila y ejecuta con opciones de debugging
make malloc-good.run-san: Compila y ejecuta con opciones para verificar el uso
          correcto de los punteros con sanitize
make malloc-good.run-vg: Compila y ejecuta con opciones para verificar el uso
          correcto de los punteros con valgrind
make malloc-good.ddd: Compila con opciones de depuración y ejecuta con ddd,
          colocando breakpoints al inicio y al término del programa
make malloc-good.ddd-san: Compila con opciones para la verificación del uso
          correcto de los punteros con sanitize, y ejecuta con ddd,
          colocando breakpoints al inicio y al término del programa

Para compilar y ejecutar malloc-strcpy.c por ejemplo, substituya malloc-good
por malloc-strcpy.  Lo mismo con los demás programas incluidos.  Puede
experimentar con sus propias variantes de estos programas y
compilar/ejecutar de la misma manera.

Video con ejemplos de uso de ddd: https://youtu.be/FtHZy7UkTT4
Archivos con los ejemplos: https://www.u-cursos.cl/ingenieria/2020/2/CC3301/1/novedades/r/demo-ddd.zip

Para diagnosticar el error en malloc-dangling.c ejecute uno de estos:
make malloc-dangling.run-san
make malloc-dangling.ddd-san

Para diagnosticar el memory leak en malloc-leak.c ejecute:
make malloc-leak.run-vg

Sanitize no es capaz de detectar el leak, pero si descomenta el printf,
¡sí lo detecta!

-----------------------------------------------

Limpieza de archivos

make clean: hace limpieza borrando todos los archivos que se pueden volver
            a reconstruir a partir de los fuentes: *.o *.bin* etc.

-----------------------------------------------

Acerca del comando make

El comando make sirve para automatizar el proceso de compilación asegurando
recompilar el archivo binario ejecutable cuando cambió uno de los archivos
fuentes de los cuales depende.

La especificación de los archivos de los cuales depende está en el archivo
Makefile, que es muy complicado de entender.  Es el profesor el que los
elabora.

Durante la invocación, make muestra los comandos que está ejecutando,
junto a otros mensajes.  Ud. puede invocar manualmente estos comandos
en el terminal y obtendrá el mismo resultado, si los invoca en el
mismo orden.

A veces es útil usar make con la opción -n para que solo muestre
exactamente qué comandos va a ejecutar, sin ejecutarlos de verdad.
Por ejemplo en la tarea 1, para determinar qué comandos ejecutará make run,
esto es lo que mostrará la invocación de: make clean; make -n run

  cc -O  recortar.c test-recortar.c -lm -o test-recortar.bin
  echo "Midiendo cuanto demora la solución del profesor"
  rm -f tiempo-ref.txt
  ./prof.binref ref | tee tiempo-ref.txt
  echo "Verificando y comparando con su solución"
  ./test-recortar.bin `cat tiempo-ref.txt`

También es útil usar make con la opción -B para forzar la recompilación
de los fuentes a pesar de que no han cambiado desde la última compilación.
Por ejemplo:

make -B run

Recompilará para generar el archivo test-recortar.bin
Si a continuación invoca:

make run

No recompilará nada porque los fuentes no han cambiado desde la última
compilación.  Solo ejecutará el binario.  Este ahorro no es relevante en
esta tarea que consiste en solo 2 archivos fuentes.  Pero un programa
grande puede consistir en cientos o miles de archivos y recompilar
todo puede tomar mucho tiempo.  Si se se cambia un solo archivo, make
solo recompilará lo que dependa de ese archivo economizando un tiempo
considerable.

Si ahora invoca:

make -B run

Se recompilará nuevamente todo, producto de la opción -B, a pesar de que
los fuentes no han cambiado.
