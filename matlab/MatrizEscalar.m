fprintf("\nLos numeros que conforman la matriz son: " );

A = [ 2 5 1 4;
      3 2 8 7;
      2 9 1 2;
      6 7 1 9];
filas = 1;
columnas = 1;
fprintf("\nEl resultado es: ");
for fil2=1:filas;
fprintf('    ')
for col2=1:columnas;
fprintf('%d', A(fil2,col2)=-2)
   fprintf('\t')
   endfor
   fprintf('\n')
 endfor

filas = 2;
columnas = 2;
fprintf("\nEl resultado es: ");
for fil3=2:filas;
fprintf('    ')
for col3=2:columnas;
fprintf('%d', A(fil3,col3)=-2)
   fprintf('\t')
   endfor
   fprintf('\n')
 endfor
 
 filas = 3;
columnas = 3;
fprintf("\nEl resultado es: ");
for fil4=3:filas;
fprintf('    ')
for col4=3:columnas;
fprintf('%d', A(fil4,col4)=-2)
   fprintf('\t')
   endfor
   fprintf('\n')
 endfor
 
 
 filas = 4;
columnas = 4;
fprintf("\nEl resultado es: ");
for fil5=4:filas;
fprintf('    ')
for col5=4:columnas;
fprintf('%d', A(fil5,col5)=-2)
   fprintf('\t')
   endfor
   fprintf('\n')
 endfor
 
 filas = 4;
columnas = 4;
fprintf("\nEl resultado es: \n");
for fil6=1:filas;
fprintf('    ')
for col6=1:columnas;
fprintf('%d', 0*A(fil6,col6))
   fprintf('\t')
   endfor
   fprintf('\n')
 endfor