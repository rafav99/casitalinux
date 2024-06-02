#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void swap(char *x, char *y)
{
    char temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void fill_vdata(char **mtx, char *argv[], int n)
{
  int i;
  int a;
  i = 1;
  a = 0;
  while(i < n + 1)
  {
    if (a % 2 == 0)
    {
      mtx[0][i] = argv[1][a];
      mtx[n + 1][i] = argv[1][a + (2 * n)];
      i++;
    }
    a++;
  }
}
void fill_hdata(char **mtx, char *argv[], int n)
{
  int i;
  int a;
  i = 1;
  a = 0;
  while(i < n + 1)
  {
    if (a % 2 == 0)
    {
      mtx[i][0] = argv[1][a + (4 * n)];
      mtx[i][n + 1] = argv[1][a + (6 * n)];
      i++;
    }
    a++;
  }
}
void mat_start(char **mtx, int n) 
{
  int i;
  int a;

  i = 0;
  while(i < n + 2)
  {
    mtx[i] = malloc(n + 2);
    a = 0;
    while(a < n + 2)
    {
      mtx[i][a] = '0' + a;
      a++;
    }
    i++;
  }
  mtx[0][0] = 'n';
}

void write_mat(char **mtx, int n)
{
  int i;
  int a;  
  
  i = 1;
  while(i < n + 1)
  {
    a = 1;
    while (a < n + 1)
    {
      write(1, &mtx[i][a], 1);
      a++;
      if (a != n + 1)
        write(1, " ", 1);
    }
    write(1, "\n", 1);
    i++;
  }
}

int rccomb(char **mtx, int nrow, int n)
{
  int i;
  int maxheight;
  int count;

  count = 0;
  maxheight= '0';
  i = n;
  while(i >= 1)
  {
    if(mtx[nrow][i] > maxheight)
    {
      maxheight = mtx[nrow][i];
      count++;
    }
      i--;
  }
  if(mtx[nrow][n + 1] - '0'== count)
    return (1);
  return(0);
}

int c_comb(char **mtx, int nrow, int n)
{
  int i;
  int maxheight;
  int count;  
  
  count = 0;
  maxheight= '0';
  i = 1;
  while(i < n + 1)
  {
    if(mtx[nrow][i] > maxheight)
    {
      maxheight = mtx[nrow][i];
      count++;
    }
      i++;
  }
  if(mtx[nrow][0] - '0'== count && rccomb(mtx, nrow, n) == 1)
    return (1);
  return(0);
}

int c_peat(char **mtx, int nrow, int n)
{
  int i;
  int a;  
  a = 1;
  while (a < n + 1)
  {
      i = 1;
      while (i < nrow)
      {
        if (mtx[nrow][a] == mtx[i][a])
          return (0);
        i++;
      }
      a++;
  }
  return(1);
}

void vertical(char **mtx, int n, int *allcount, int a)
{
    int i;
    int maxheight;
    int count;

    i = 1;
    count = 0;
    maxheight = '0';
    while (i <= n)
    {
        if(mtx[i][a] > maxheight)
        {
            maxheight = mtx[i][a];
            count++;
        }
        i++;
    }
    if(mtx[0][a] - '0'== count)
        *allcount = *allcount + 1;
}

void rvertical(char **mtx, int n, int *revcount, int a)
{
    int i;
    int maxheight;
    int count;

    i = n;
    count = 0;
    maxheight = '0';
    while (i >= 0)
    {
        if(mtx[i][a] > maxheight)
        {
            maxheight = mtx[i][a];
            count++;
        }
        i--;
    }
    if(mtx[n + 1][a] - '0' == count)
        *revcount = *revcount + 1;
}

int cvert(char **mtx, int n)
{
    int a;
    int allcount;
    int revcount;

    revcount = 0;
    a = 1;
    allcount = 0;
    while (a <= n)
    {
        vertical(mtx, n, &allcount, a);
        rvertical(mtx, n, &revcount, a);
        a++; 
    }
    if (allcount == n && revcount == n)
            return(1);
    else
        return(0);
}

void mtx_comb(char **mtx, int start, int n, int nrow)
{
    int i;
    
    if(start == n)
    {
        if(c_comb(mtx, nrow, n) == 1  && c_peat(mtx, nrow, n) == 1)
        {
            if (nrow < n + 1)
                mtx_comb(mtx, 1, n, nrow + 1);
            if (nrow == n  && cvert(mtx, n) == 1 && mtx[0][0] != 'f')
            {
                mtx[0][0] = 'f';
                write_mat(mtx, n);
            }
        }
        return;
    }
    i = start;
    while(i <= n)
    {
        swap(&mtx[nrow][start], &mtx[nrow][i]);
        mtx_comb(mtx, start + 1, n, nrow);
        swap(&mtx[nrow][start], &mtx[nrow][i]);
        i++;
    }
}

int ismol(int count, char *str)
{
    int i;
    int n;

    n = count / 4 + '0';
    i = 0;
    while(str[i] != '\0')
    {
        if(i % 2 == 0)
        {
            if (str[i] > n)
                return (0);
        }
        i++;
    }
    if (count >= 16 && count % 4 == 0 && str[i - 1] != ' ')
        return (1);
    else
        return (0);
}

int check_input(char *str)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while(str[i] != '\0')
    {
        if (i % 2 == 0)
        {
            if (str[i] < '0' || str[i] > '9' )
                return (-1);
            count ++;
        }
        if  (i % 2 != 0)
        {
            if (str[i] != ' ')
                return (0);
        }
        i++;
    }
    if (ismol(count, str) != 0)
        return (count / 4);
    else
        return (0);
}

void    freemem(char **mtx, int n)
{
    int i;

    i = 0;
    while(i < n + 2)
    {
        free(mtx[i]);
        i++;
    }
    free(mtx);
}
int  main(int argc, char *argv[])
{   
    char **mtx; 
    int     n;

    if (argc != 2)
    {
        write(1, "Error\n", 6);
        return (0);
    }
    n = check_input(argv[1]);
    if(n != 0)
    {
        mtx = malloc((n + 2)*sizeof(*mtx));
        mat_start(mtx, n);
        fill_vdata(mtx, argv, n);
        fill_hdata(mtx, argv, n);
        mtx_comb(mtx, 1, n, 1);
        if (mtx[0][0] == 'n')
            write(1, "Error\n", 6);
        freemem(mtx, n);
    }
    else
        write(1, "Error\n", 6);
    return 0;
}
