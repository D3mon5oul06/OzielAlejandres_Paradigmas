A = [ 4 7 9 4;
      1 6 4 2;
      7 2 1 3];
filas = 1;
columnas = 1;
fprintf("\nEl resultado es: ");
for fil2=1:filas;
fprintf('    ')
for col2=1:columnas;
fprintf('%d', A(fil2,col2))
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
fprintf('%d', A(fil3,col3))
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
fprintf('%d', A(fil4,col4))
   fprintf('\t')
   endfor
   fprintf('\n')
 endfor
 

fprintf("\nLa traza es: ");
Traz  = A(fil2,col2)+A(fil3,col3)+A(fil4,col4);
fprintf('%d',Traz);

