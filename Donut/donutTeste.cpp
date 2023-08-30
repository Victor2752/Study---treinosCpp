#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define Rotation(mul, shift, x, y) \
  tan = x; \
  x -= mul * y >> shift; \
  y += mul * tan >> shift; \
  tan = 3145728 - x * x - y * y >> 11; \
  x = x * tan >> 10; \
  y = y * tan >> 10;

int8_t b[1760], z[1760];

int main() {
  int senA=1024, // seno A
      cosA=0,   // coseno A
      senB=1024, // seno B
      cosB=0,  // coseno B
      tan; // tangente
  for (;;) {
    memset(b, 32, 1760);  // text buffer
    memset(z, 127, 1760);   // z buffer

    int senJ=0, cosJ=1024; // seno e cosseno do angulo j
    int senI = 0, cosI = 1024;  // seno e coseno do angulo i

    for (int j = 0; j < 90; j++) {
      for (int i = 0; i < 324; i++) {
        int R1 = 1, R2 = 2048, K2 = 5120*1024;

        int x0 = R1*cosJ + R2,
            x1 = cosI*x0 >> 10,
            x2 = cosA*senJ >> 10,
            x3 = senI*x0 >> 10,
            x4 = R1*x2 - (senA*x3 >> 10),
            x5 = senA*senJ >> 10,
            x6 = K2 + R1*1024*x5 + cosA*x3,
            x7 = cosJ*senI >> 10,
            x = 40 + 30*(cosB*x1 - senB*x4)/x6,
            y = 12 + 15*(cosB*x4 + senB*x1)/x6,
            N = (-cosA*x7 - cosB*((-senA*x7>>10) + x2) - cosI*(cosJ*senB >> 10) >> 10) - x5 >> 7;

        int o = x + 80 * y;
        int8_t zz = (x6-K2)>>15;
        if (22 > y && y > 0 && x > 0 && 80 > x && zz < z[o]) {
          z[o] = zz;
          b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0]; 
        }
        Rotation(5, 8, cosI, senI)  // rotate i
      }
      Rotation(9, 7, cosJ, senJ)  // rotate j
    }

    for (int k = 0; 1761 > k; k++)
      putchar(k % 80 ? b[k] : 10);

    Rotation(5, 7, cosA, senA);
    Rotation(5, 8, cosB, senB);
    usleep(15000);
    printf("\x1b[23A");
  }
}


