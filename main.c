#include <stdio.h>


int main() {
    float calificaciones[5][3];
     char materias[3][20] = {"Física", "Química", "Matemáticas"};
    char nombres[5][20];  

    for (int i = 0; i < 5; i++) {
        printf("Ingresa el nombre del estudiante %d: ", i + 1);
        fflush(stdin);
        fgets(nombres[i], 20, stdin);

    }


    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            do {
                printf("Ingrese la calificación de %s para %s (Las notas van de 0 a 10): ", nombres[i], materias[j]);
                scanf("%f", &calificaciones[i][j]);
            } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 10);
        }
    }


    for (int i = 0; i < 5; i++) {
        float suma = 0;
        for (int j = 0; j < 3; j++) {
            suma += calificaciones[i][j];
        }
        float promedio = suma / 3;
        printf("Promedio de %s: %.2f\n", nombres[i], promedio);
    }


    for (int j = 0; j < 3; j++) {
        float suma = 0;
        for (int i = 0; i < 5; i++) {
            suma += calificaciones[i][j];
        }
        float promedio = suma / 5;
        printf("Promedio en %s: %.2f\n", materias[j], promedio);
    }


    for (int i = 0; i < 5; i++) {
        float max = calificaciones[i][0], min = calificaciones[i][0];
        for (int j = 1; j < 3; j++) {
            if (calificaciones[i][j] > max) max = calificaciones[i][j];
            if (calificaciones[i][j] < min) min = calificaciones[i][j];
        }
        printf("%s - Calificación más alta: %.2f, más baja: %.2f\n", nombres[i], max, min);
    }


    for (int j = 0; j < 3; j++) {
        int aprobados = 0, reprobados = 0;
        for (int i = 0; i < 5; i++) {
            if (calificaciones[i][j] >= 6) {
                aprobados++;
            } else {
                reprobados++;
            }
        }
        printf("%s ----- Aprobados: %d, Reprobados: %d\n", materias[j], aprobados, reprobados);
    }

    return 0;
}