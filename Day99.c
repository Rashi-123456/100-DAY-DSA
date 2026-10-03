/* Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target. */
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int position;
    int speed;
} Car;
int compare(const void *a, const void *b) {
    const Car *x = (const Car *)a;
    const Car *y = (const Car *)b;
    return y->position - x->position;
}
int carFleet(int target, int position[], int speed[], int n) {
    Car *cars = malloc(n * sizeof(Car));
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }
    qsort(cars, n, sizeof(Car), compare);
    int fleets = 0;
    double lastTime = 0.0;
    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].position) / cars[i].speed;
        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
    }
    free(cars);
    return fleets;
}
int main() {
    int target, n;
    printf("Enter target: ");
    scanf("%d", &target);
    printf("Enter number of cars: ");
    scanf("%d", &n);
    int *position = malloc(n * sizeof(int));
    int *speed = malloc(n * sizeof(int));
    printf("Enter positions of %d cars: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &position[i]);
    printf("Enter speeds of %d cars: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &speed[i]);
    printf("Number of car fleets: %d\n",
           carFleet(target, position, speed, n));
    free(position);
    free(speed);
    return 0;
}