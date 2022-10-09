       IDENTIFICATION DIVISION. 
       PROGRAM-ID. ex2.
       DATA DIVISION.
       WORKING-STORAGE SECTION. 
      *A este punto aprendi algo bien perron, y son los indices!
      *voy con una matriz de 2x2 porque es más sencillo ver resultados
       01 WS-A OCCURS 2 TIMES indexed by i.
      *    positivos de dos digitos
           10 WS-B             PIC 9(2).
           10 WS-C OCCURS 2 TIMES indexed by j.
      *    positivos de dos digitos
               15 WS-D         PIC 9(2).  
       
      *Para probar las operaciones de suma y resta...
       01 WS-A2 OCCURS 2 TIMES indexed by k.
      *    positivos de dos digitos
           10 WS-B2            PIC 9(2).
           10 WS-C2 OCCURS 2 TIMES indexed by z.
      *    positivos de dos digitos
               15 WS-D2        PIC 9(2).  
       01 ws-res               pic 9(5).
       
      *para definir las posiciones donde pintar
       01 ws-posX              pic 9(2).
       01 ws-posY              pic 9(2).

      *Para alojar la suma PD: Esto usando un formato sucio, lo se.
      *Ambas matrices tienen lo mismo, su suma es el doble de ella misma
       01 ws-sum               pic 9(01).
       01 ws-sum2              pic 9(01).

      *Para aljar la multiplicación
       01 ws-acum              pic 9(5) value 0.
       01 ws-index             pic 9(01).
       01 ws-mul               pic 9(01).
       01 ws-mul2              pic 9(01).

       PROCEDURE DIVISION.
       move 1 to WS-C(1,1). move 1 to WS-C2(1,1).
       move 2 to WS-C(1,2). move 2 to WS-C2(1,2).
       move 3 to WS-C(2,1). move 3 to WS-C2(2,1).
       move 4 to WS-C(2,2). move 4 to WS-C2(2,2).
       
       move 1 to i.
       move 1 to j.
      * Descomentar el procedimiento esperado quitando el *...
      *perform 00001_watch.
      *perform 00004_transpose.
       perform 00005_sum.
      *perform  00006_multiply.

       stop run.
       
       00001_watch.
           PERFORM 00002_A-for varying i from 1 by 1 UNTIL i > 2.
       
       00002_A-for.
           PERFORM 00003_C-for varying j from 1 by 1 UNTIL j > 2.

       00003_C-for.
           move 10 to ws-posX. move 10 to ws-posY.
           add i to ws-posX. move j to ws-posY.
           display WS-C(i, j) line ws-posX column ws-posY.

      *Ejercicio de obtener la transpuesta
       00004_transpose.
           PERFORM 00002_A-for-t varying i from 1 by 1 UNTIL i > 2.

       00002_A-for-t.
           PERFORM 00003_C-for-t varying j from 1 by 1 UNTIL j > 2.

       00003_C-for-t.
           move 10 to ws-posX. move 10 to ws-posY.
           add i to ws-posX. move j to ws-posY.
           display WS-C(j, i) line ws-posX column ws-posY.
       
      *ejercicio de obtener la suma
       00005_sum.
           PERFORM 00002_A-for-s varying i from 1 by 1 UNTIL i > 2.
       
       00002_A-for-s.
           PERFORM 00003_C-for-s varying j from 1 by 1 UNTIL j > 2.

       00003_C-for-s.
      *    display WS-C2(i, j).
           move WS-C(i, j) to ws-sum.
           move WS-C2(i, j) to ws-sum2.
           add ws-sum to ws-sum2 giving ws-res.
           display ws-sum " + " ws-sum " = " ws-res.
       
      *ejercicio para calcular la multiplicación de dos matrices
       00006_multiply.
           PERFORM 00002_A-for-m varying i from 1 by 1 UNTIL i > 2.
       
       00002_A-for-m.
           PERFORM 00003_C-for-m varying j from 1 by 1 UNTIL j > 2.
       
       00003_C-for-m.
           PERFORM 00002_D-for-m varying ws-index from 1 by 1 UNTIL 
           ws-index > 2.
           display i ", " j " = " ws-acum.
           move 0 to ws-acum.
       00002_D-for-m.
      *    Es la cantidad de columnas de la segunda matriz, al ser 2x2
      *    casi no se nota
           move WS-C(i, ws-index) to ws-mul.
           move WS-C2(ws-index, j) to ws-mul2.
           multiply ws-mul by ws-mul2 giving ws-res.
           add ws-res to ws-acum.
       END PROGRAM ex2.

