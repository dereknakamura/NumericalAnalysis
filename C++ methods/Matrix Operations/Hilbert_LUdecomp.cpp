#include<stdio.h>
#include<math.h>
#include<iostream>

void print(double **matrix, int h, int w) {
   for (int i=0; i<h; i++, printf("\n"))
      for (int j=0; j<w; j++)
         printf("%lf ", matrix[i][j]);
}

double **Hilbert(int n) {
    double **H = new double*[n];
  
    for(int i = 0; i < n; i++) {
        H[i] = new double[n]; 
        for(int j = 0; j < n; j++) { 
            H[i][j] = (double)1.0 /((i + 1) + (j + 1) - 1.0); 
        }
    }
    return H;
}

void luDecomposition(double **a, double **u, double **l, int N) {
    double sum;
    for(int i=0; i<N; i++) {
        l[i][i] = 1;
        for(int j=i; j<N; j++) {
            for(int k=0; k<i-1; k++) {
                sum += l[i][k] * u[k][j];
         }
         u[i][j] = a[i][j] - sum;
      }

      for(int j=i+1; j<N; j++) {
         sum = 0;
         for(int k=0; k<i-1; k++) {
            sum += l[j][k] * u[k][i];
         }
         l[j][i] = (a[j][i] - sum)/u[i][i];
      }
    }
    printf("L:\n");
    for (int i=0; i<N; i++, printf("\n"))
        for (int j=0; j<N; j++)
            printf("%lf ", l[i][j]);
    printf("U:\n");
    for (int i=0; i<N; i++, printf("\n"))
        for (int j=0; j<N; j++)
            printf("%lf ", u[i][j]);
}

int main() { 
	for(int n = 2; n<7; n++) {
		printf("Hilbert for %d:\n", n);
		double **H = Hilbert(n);
		print(H, n, n);
        double **l = new double*[n];
        double **u = new double*[n];
        for (int i=0; i< n; i++) {
        	l[i] = new double[n]; 
        	u[i] = new double[n]; 
        }
		luDecomposition(H, u, l, n);
    }
    return 0; 
} 
