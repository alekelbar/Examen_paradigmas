      *First programa in cobol... 
      *----*************************************************************Notas
      * DATOS SOBRE EL PROGRAMA...
       IDENTIFICATION DIVISION.    
       PROGRAM-ID. EXAM.
      * CONTIENE INFORMACIÓN SOBRE EL ENTORNO DONDE SE EJECUTARA EL PROG
       ENVIRONMENT DIVISION.
      
      *DIVISIÓN PARA GUARDAR VARIABLES...
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       77 WKS-NOMBRE       pic A(60).  
       77 WKS-operando-1   pic 9(5).
       77 WKS-operando-2   pic 9(5).
       77 WKS-result       pic 9(5).
       77 wks-operacion    pic A(1).
       77 wks-opcion       pic 9(01).
                      
      *TIENE TODAS LAS INSTRUCCIONES PARA LLEVAR A CABO EL PROGRAMA...
       PROCEDURE DIVISION.
           perform 00000-calculadora until wks-opcion = 2.
      *DETENER EL PROGRAMA
       STOP RUN.

       00000-calculadora.
           display "1) usar calculadora, 2) salir".
           accept wks-opcion.
           if wks-opcion = 1
               perform 00001-pedir-datos
               perform 00002-realizar-operacion
           else 
               next sentence
               display "Gus bay!".
               
       00001-pedir-datos.
           display "Este programa es una calculadora!".
           display "Capture el primer operando: ".
           accept WKS-operando-1.
           display "Capture el segundo operando: ".
           accept WKS-operando-2.
           display "Inserte la operación: ".
           accept wks-operacion.

       00002-realizar-operacion.
           if wks-operacion = "s"
      *Operación de suma...     
               add WKS-operando-1 to WKS-operando-2 giving WKS-result
           else 
           if wks-operacion = "r"
      *Operación de resta...     
               subtract WKS-operando-1 from WKS-operando-2 giving 
               WKS-result
      *Operación de multiplicación...     
           else
           if wks-operacion = "m"
               multiply WKS-operando-1 by WKS-operando-2 giving 
               WKS-result
           else 
           if wks-operacion = "d"
      *Operación de división...     
               divide WKS-operando-1 into WKS-operando-2 giving 
               WKS-result
           else 
               display "Not operation to do...".
           display "Resultado! " wks-result.
           
           