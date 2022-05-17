#include <pthread.h>
#include <stdio.h>

struct z {
    int * x;
    int s;
};

int c(int * x, int q, int p) {
    int s = 0;
    for (int i = q; i < p; i++) {
        s += *(x + i);
    }
    return s;
}

void * f(void * args) {
    struct z * y = (struct z *) args;
    y->s = c(y->x, 4, 7);
    return NULL;
}

int main(int argc, char * argv[]) {
    int a[] = {9, 7, 2, 3, 2 , 6, 4};
    int w = 0;
    pthread_t p;
    struct z y;
    y.x = a;
    y.s = 0;

    if (pthread_create(&p, NULL, f, &y) != 0) {
        return 1;
    }

    w = c(a, 0, 3);

    if (pthread_join(p, NULL) != 0) {
        return 2;
    }

    printf("%d\n", *(y.x));
    printf("%d\n", y.x[5]);
    printf("%d\n", w);
    printf("%d\n", c(y.x, 3, 4));
    printf("%d\n", y.s);
    return 0;
}
