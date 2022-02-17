fprintf('Primera matriz: ')
A = [2 5;
     7 2]
     

 fprintf('\nSegunda matriz: ')
B = [1 6;
     9 10]
      
 filas = 2;
 columnas = 2;
 
 fprintf('\nSuma de matrices: \n')
 
 for fil=1:filas;
   fprintf('    ')
   for col=1:columnas;
     fprintf('%d', A(fil,col) + B(fil, col))
     fprintf('\t')
   endfor
   fprintf('\n')
 endfor