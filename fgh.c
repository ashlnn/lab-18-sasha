#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 100


void input_array(double arr[], int *size, char name) {
    printf("Enter the number of elements for array %c: ", name);
    scanf("%d", size);
    for (int i = 0; i < *size; i++) {
        printf("%c[%d] = ", name, i + 1);
        scanf("%lf", &arr[i]);
    }
}

void process_arrays(double alpha[], int n, double beta[], int m) {
    double s = 0, A = 0, B = 1, C = 0;
    double D = 0, E = 0, F = 0;

    for (int i = 0; i < n; i++) {
        s += alpha[i];
    }

    for (int i = 0; i < n; i++) {
        A += alpha[i] * log10(fabs(alpha[i]));
        B *= alpha[i];
        C += alpha[i] * sin(alpha[i]);
    }
    A *= s;
    C *= s;

    for (int j = 0; j < m; j++) {
        D += alpha[j] * cos(beta[j]);
        E += beta[j];
        F += fabs(beta[j]);
    }

    double omega = (A * cos(B) + C) / (D + E * sin(F));
    printf("\nResults:\n");
    printf("A = %.3lf\n", A);
    printf("B = %.3lf\n", B);
    printf("C = %.3lf\n", C);
    printf("D = %.3lf\n", D);
    printf("E = %.3lf\n", E);
    printf("F = %.3lf\n", F);
    printf("omega = %.3lf\n", omega);
}

int main() {
    double alpha[MAX_SIZE], beta[MAX_SIZE];
    int n, m;

    input_array(alpha, &n, 'α');
    input_array(beta, &m, 'β');

    process_arrays(alpha, n, beta, m);

    return 0;
}
