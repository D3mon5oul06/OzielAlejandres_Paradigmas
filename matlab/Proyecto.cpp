// hopfield.cpp

#include <iostream>
#include <fstream>
using namespace std;

// initialize the weigth matrix W with the patterns 
void printw(int **W, int N)
{

  for (int i=0; i<N; i++)
  {
    for (int j=0; j<N; j++)
    {
     cout << W[i][j] << " ";
    }
    cout << endl;
  }
}

void weigths(int **W,  int *NumRom1, int *NumRom2, int *NumRom3, int *NumRom4, int *NumRom5, int *NumRom6, int *NumRom7 ,int N)
{

  for (int i=0; i<N; i++)
  for (int j=0; j<N; j++)
  {
    W[i][j] =  NumRom1[i]*NumRom1[j] + NumRom2[i]*NumRom2[j] + NumRom3[i]*NumRom3[j] + NumRom4[i] *NumRom4[j] + NumRom5[i]*NumRom5[j] + NumRom6[i] *NumRom6[j] + NumRom7[i]*NumRom7[j];
  }
  for (int k=0; k<N; k++)
    W[k][k]=0;

}
// calculation of sum over j of W * S

void mul(int **W, int *s, int *h, int N)
{ 
  
  for (int i=0; i<N; i++)
  {
    int sum=0;
    for (int j=0; j<N; j++)
    { 
      sum += W[i][j] * s[j];
    }
    h[i] = sum;
  }

}

// energy of the configuration - Ising model

int energy(int **W, int *s, int N)
{

  int E=0;
  for (int i=0; i<N; i++)
    for (int j=0; j<N; j++)
      E += W[i][j] * s[i] * s[j];
  return -E;
}

int sign(int y)
{
  if (y>0) return 1;
  else return -1;
}

int check(int *v1, int *v2, int N)
{

    for (int i=0; i<N; i++)
    {
      if (v1[i] != v2[i]) return 0;
    }
    return 1;
}


int readfile(string file, int *v1, int col, int N)
{
    std::ifstream infile(file);
    int a1, a2, a3, a4, a5, a6, a7,a8;
    int row=0;
   
    while(infile >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8 ) {
        std::cout << a1 << a2 << a3 << a4 << a5 << a6 << a7 << a8 << endl;
        v1[(row*col) + 0] = a1;
        v1[(row*col) + 1] = a2;
        v1[(row*col) + 2] = a3;
        v1[(row*col) + 3] = a4;
        v1[(row*col) + 4] = a5;
        v1[(row*col) + 5] = a6;
        v1[(row*col) + 6] = a7;
        v1[(row*col) + 7] = a8;
       

        row++;
   }

   for (int i=0; i<N; i++)
   { 
     if (v1[i] == 0)
       v1[i] = -1;
     //cout << v1[i];
  
     //if (((i+1)%col) == 0 )
      // cout << endl;
   }
   cout << endl;
 return 0;
}

int main(void)
{
  int N = 80;
  int col = 8;
  int *NumRom1 = new int[N];
  int *NumRom2 = new int[N];
  int *NumRom3 = new int[N];
  int *NumRom4 = new int[N];
  int *NumRom5 = new int[N];
  int *NumRom6 = new int[N];
  int *NumRom7 = new int[N];
  
  
  cout << "iterations " << endl;

  readfile("NumRom1.txt", NumRom1,  col, N);
  readfile("NumRom2.txt", NumRom2,  col, N);
  readfile("NumRom3.txt", NumRom3,  col, N);
  readfile("NumRom4.txt", NumRom4,  col, N);
  readfile("NumRom5.txt", NumRom5,  col, N);
  readfile("NumRom6.txt", NumRom6,  col, N);
  readfile("NumRom7.txt", NumRom7,  col, N);
  


  int **W = NULL;  // allocating memory for W
  W = new int *[N];
  for (int i=0; i<N; i++)
  {
    W[i] = new int[N];
  }

  
  for (int i=0; i<N; i++)
    for (int j=0; j<N; j++)
      W[i][j]=0;

  weigths(W,  NumRom1, NumRom2, NumRom3, NumRom4, NumRom5,NumRom6,NumRom7, N);
  printw(W, N);

  int *s = new int[N]; // allocation memory for s

  readfile("x1.txt", s,  col, N);

  // start configuration
/*  s[0] = -1;
  s[1] = -1;
  s[2] = -1;
  s[3] = -1;
*/
 
  int E = energy(W,s,N);
  cout << " energy of initial configuration : " << E << endl;

  int *h = new int[N]; // allocation memory for h

  for (int p=0; p<N; p++)
  {
    h[p] = 0;
  }

  int *s1 = new int[N];

  for (int i=0; i<N; i++)
  {
    s1[i] = s[i];
  }

  int result, count;
  count = 0;
   
   cout << "Elemento a buscar" << endl;
   for (int i=0; i<N; i++)
    {
      if (s[i] == -1)
        cout << "0" << " ";
      else
        cout << s[i] << " ";
      if (((i+1)%col) == 0 )
        cout << endl;
    }
    cout << endl;
   
   
  do
  {

    for (int i=0; i<N; i++)
    {
      s1[i] = s[i];
    }

    mul(W,s,h,N);

   
    for (int j=0; j<N; j++)
    {
      if (h[j] !=0)
      {
        s[j] = sign(h[j]);
      }

      if (h[j]==0) {
        s[j] = s1[j];
      }
    }

    result = check(s, s1, N);
    count++;

/*
    for (int i=0; i<N; i++)
    {
      cout << h[i] << " ";
      if (((i+1)%col) == 0 )
        cout << endl;
    }
    cout << endl;
*/
	

    //for (int i=0; i<N; i++)
    //{
      //if (s[i] == -1)
        //cout << "0" << "";
      //else
        //cout << s[i] << "";
      //if (((i+1)%col) == 0 )
       //cout << endl;
    //}
    //cout << endl;

  } while ((count < 150) && (result != 1));

	cout << "Elemento encontrado: " << endl;
	for (int i=0; i<N; i++)
    {
      if (s[i] == -1)
        cout << "0" << " ";
      else
        cout << s[i] << " ";
      if (((i+1)%col) == 0 )
        cout << endl;
    }
    cout << endl;


  cout << "\n Number of iterations " << count << endl;

  E = energy(W,s,N);
  cout << " energy of end configuration : " << E << endl;
 

  delete[] s;
  delete[] s1;
  delete[] h;

  for (int i=0; i<N; i++) {
    delete[] W[i];
  }

  delete[] W;

}
