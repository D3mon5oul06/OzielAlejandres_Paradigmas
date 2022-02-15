%Matriz cuadrada de orden 3 x 3
A = [0 1 2;
     3 4 5;
     6 7 8];
 % impresion de matriz usando 2 ciclos anidados    
 renglones = 3;
 columnas = 3;
 fprintf('Impresion de matriz de orden 3x3 \n');
 for ren = 1 : renglones;
     for col = 1:columnas; 
       fprintf('%d', A(ren, col))
     end
     fprintd('\n');
 end
