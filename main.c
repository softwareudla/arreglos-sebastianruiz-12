#include <stdio.h>

int main() {
    float calificaciones[5][3];

    // Captura de las calificaciones con validación
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            do {
                printf("Introduce la calificación del estudiante %d para la asignatura %d (0-10): ", i + 1, j + 1);
                scanf("%f", &calificaciones[i][j]);
            } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 10);
        }
    }

    // Promedio por estudiante
    for (int i = 0; i < 5; i++) {
        float suma = 0;
        for (int j = 0; j < 3; j++) {
            suma += calificaciones[i][j];
        }
        float promedio = suma / 3;
        printf("Promedio del estudiante %d: %.2f\n", i + 1, promedio);
    }

    // Promedio por asignatura
    for (int j = 0; j < 3; j++) {
        float suma = 0;
        for (int i = 0; i < 5; i++) {
            suma += calificaciones[i][j];
        }
        float promedio = suma / 5;
        printf("Promedio de la asignatura %d: %.2f\n", j + 1, promedio);
    }

    // Calificación más alta y baja por estudiante
    for (int i = 0; i < 5; i++) {
        float max = calificaciones[i][0], min = calificaciones[i][0];
        for (int j = 1; j < 3; j++) {
            if (calificaciones[i][j] > max) max = calificaciones[i][j];
            if (calificaciones[i][j] < min) min = calificaciones[i][j];
        }
        printf("Estudiante %d - Calificación más alta: %.2f, más baja: %.2f\n", i + 1, max, min);
    }

    // Aprobados y reprobados por asignatura
    for (int j = 0; j < 3; j++) {
        int aprobados = 0, reprobados = 0;
        for (int i = 0; i < 5; i++) {
            if (calificaciones[i][j] >= 6) {
                aprobados++;
            } else {
                reprobados++;
            }
        }
        printf("Asignatura %d - Aprobados: %d, Reprobados: %d\n", j + 1, aprobados, reprobados);
    }
    return 0;
}    