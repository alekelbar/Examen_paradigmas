       IDENTIFICATION DIVISION. 
       PROGRAM-ID. ex1.
       DATA DIVISION.
       WORKING-STORAGE SECTION. 
      *contador del for externo
       01 wks-contador         pic 9(5) value 10.
      *contador del for interno
       01 wks-contador-interno pic 9(5) value 1.
      *contador para llevar el indice de mostrar
       01 wks-for-index        pic 9(5) value 1.
      *auxiliar para el intercambio burbuja
       01 wks-auxiliar         pic 9(5).
      *Para almacenar el modulo de una operación...
       01 wks-module           pic 9(5).
      *Para almacenar el modulo auxiliar de una operación...
       01 wks-module-aux        pic 9(5).
      *Para almacenar la basura del modulo...
       01 wks-trash            pic 9(5).
      *array de numeros
       01 wks-array-numbers    occurs 10 times.
           05 wks-number       pic 9(5).

       PROCEDURE DIVISION.

       display "# --- Array desordenado! --- #".

       perform 00000-fill until wks-contador = 0.
       perform 00004-mostrar until wks-for-index = 11
       perform 00005-reset.
       
       display "# --- Array ordenado! --- #".
       
       perform 00001-burbuja.
       perform 00004-mostrar until wks-for-index = 11
       perform 00005-reset.

       display "# --- Array modificado! --- #".
      *[1,2,3,4,5,6,7,8,9,10] => [2,4,6,8,10,9,7,5,3,1]

       perform 00001-burbuja-modified.
       perform 00004-mostrar until wks-for-index = 11
       perform 00005-reset.
       stop run.

      * subrutina para llenar de manera acendente 
       00000-fill.
           compute wks-number(wks-contador-interno) = wks-contador.
           subtract 1 from wks-contador giving wks-contador.
           add 1 to wks-contador-interno giving wks-contador-interno.
      * sub rutina para realizar el ordenamiento burbujar
       00001-burbuja.
           perform 00002-for-externo until wks-contador = 11.
      * sub rutina para realizar un recorrido lineal...
       00002-for-externo.
           add 1 to wks-contador giving wks-contador.
           perform 00003-for-interno until wks-contador-interno = 10.
           compute wks-contador-interno = 1.
      * sub rutina para realizar un recorrido lineal... y ordenar..
       00003-for-interno.
      *    display wks-number(wks-contador-interno).
      *    display wks-number(wks-contador-aux).
      * Agregar la condición de desplazamiento
           if wks-number(wks-contador-interno) > 
           wks-number(wks-contador-interno + 1)
               compute wks-auxiliar = wks-number(wks-contador-interno)
               compute wks-number(wks-contador-interno) = 
               wks-number(wks-contador-interno + 1)
               compute wks-number(wks-contador-interno + 1)
               = wks-auxiliar.
           add 1 to wks-contador-interno giving wks-contador-interno.

       00001-burbuja-modified.
           perform 00002-for-externo-modified until wks-contador = 11.
      * sub rutina para realizar un recorrido lineal...
       00002-for-externo-modified.
           add 1 to wks-contador giving wks-contador.
           perform 00003-for-interno-modified 
           until wks-contador-interno = 10.
           compute wks-contador-interno = 1.
      * sub rutina para realizar un recorrido lineal... y ordenar..
       00003-for-interno-modified.
      *    display wks-number(wks-contador-interno).
      *    display wks-number(wks-contador-aux).
      * Agregar la condición de desplazamiento modificada
           perform 00006-module.
           perform 00007-module-2.
           if not(wks-module-aux not equal 0 AND 
           wks-number(wks-contador-interno + 1) < 
           wks-number(wks-contador-interno)) 
           and wks-module not equal 0
               compute wks-auxiliar = wks-number(wks-contador-interno)
               compute wks-number(wks-contador-interno) = 
               wks-number(wks-contador-interno + 1)
               compute wks-number(wks-contador-interno + 1)
               = wks-auxiliar.
           add 1 to wks-contador-interno giving wks-contador-interno.
      * sub rutina para realizar el mostrar datos...       
       00004-mostrar.
           display wks-number(wks-for-index).
           add 1 to wks-for-index giving wks-for-index.
      * sub rutina para realizar una limpieza de datos...
       00005-reset.
           compute wks-contador = 1.
           compute wks-contador-interno = 1.
           compute wks-for-index = 1.
      *sub rutina para saber si el numero principal es odd 
       00006-module.
           divide wks-number(wks-contador-interno) 
           by 2
           giving wks-trash
           remainder wks-module.
      *sub rutina para saber si el numero secundario es odd  
       00007-module-2.
           divide wks-number(wks-contador-interno + 1) 
           by 2
           giving wks-trash
           remainder wks-module-aux.
       END PROGRAM ex1.
