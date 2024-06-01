#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void fill_vdata(char **row, char *argv[])
{
  int i;
  int a;
  i = 1;
  a = 0;
  while(i < 5)
  {
    if (a % 2 == 0)
    {
      row[0][i] = argv[1][a];
      row[5][i] = argv[1][a + 8];
      i++;
    }
    a++;
  }
}

void fill_hdata(char **row, char *argv[])
{
  int i;
  int a;
  i = 1;
  a = 0;
  while(i < 5)
  {
    if (a % 2 == 0)
    {
      row[i][0] = argv[1][a + 16];
      row[i][5] = argv[1][a + 24];
      i++;
    }
    a++;
  }
}

void mat_start(char **row) {
  int i;
  int a;
  i = 0;
  while(i < 6)
  {
    row[i] = malloc(6);
    a = 0;
    while(a < 6)
    {
      row[i][a] = '0' + a;
      a++;
    }
    i++;
  }
}

void write_mat(char **row)
{
  int i;
  int a;

  i = 0;
  while(i < 6)
  {
    a = 0;
    while (a < 6)
    {
      write(1, &row[i][a], 1);
      a++;
    }
    write(1, "\n", 1);
    i++;
  }
}

int rev_checkcomb(char **row, int nrow)
{
  int i;
  int maxheight;
  int count;
  count = 0;
  maxheight= '0';
  i = 4;
  while(i >= 1)
  {
    if(row[nrow][i] > maxheight)
    {
      maxheight = row[nrow][i];
      count++;
    }
      i--;
  }
  if(row[nrow][5] - '0'== count)
    return (1);
  return(0);
}

int check_vcomb(char **row, int rpos)
{
 
 
  return(1);

}

int check_comb(char **row, int nrow)
{
  int i;
  int maxheight;
  int count;

  count = 0;
  maxheight= '0';
  i = 1;
  while(i < 5)
  {
    if(row[nrow][i] > maxheight)
    {
      maxheight = row[1][i];
      count++;
    }
      i++;
  }
  if(row[nrow][0] - '0'== count &&  rev_checkcomb(row, nrow) == 1)
    return (1);
  return(0);
}

void row_comb(char **row, int start, int n, int nrow)
{
  int i;
  int a;
  if(start == n)
  {
    if(check_comb(row, nrow) == 1 )
    {
      a = nrow + '0';
      write(1, "nrow es ", 8);
      write(1, &a, 1);
            write(1, "\n", 1); 

      write_mat(row);
      write(1, "\n", 1); 
      if (nrow < 2)
      {
        row_comb(row, 1, 4, nrow + 1);
      }
      
    }
   
    
    return;
  }
  i = start;
  while(i <= n)
  {
    swap(&row[nrow][start], &row[nrow][i]);
    row_comb(row, start + 1, n, nrow);
    swap(&row[nrow][start], &row[nrow][i]);
    i++;
  }

}
int  main(int argc, char *argv[])
{
  char **row;

  row = malloc(6*sizeof(*row));

  mat_start(row);
  fill_vdata(row, argv);
  fill_hdata(row, argv);

  write_mat(row);
  write(1, "\n\n\n", 3);

  row_comb(row, 1, 4, 1);


  /* code */
  return 0;
}
