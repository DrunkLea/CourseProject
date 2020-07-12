#include <stdio.h>
#include <string.h>

struct complex_s {
  double a, bi;
};

int scan_complex_op(struct complex_s *c1, struct complex_s *c2, char *operator)
{
  char buffer[80];

  if(fgets(buffer, 80, stdin) == NULL)
    return 0;
  if (sscanf(buffer, "(%lf%lfi)%c(%lf%lfi)",
   &c1->a, &c1->bi, &*operator, &c2->a, &c2->bi) != 5){
     printf("Invalid input\n");

     return -1;
   }

  return 1;
}

void print_complex(struct complex_s c)
{
  printf("=(%.2lf%+.2lfi)\n", c.a, c.bi);
}

struct complex_s add_complex(struct complex_s c1, struct complex_s c2)
{
  struct complex_s result;

  result.a = c1.a + c2.a;
  result.bi = c1.bi + c2.bi;

  return result;
}

struct complex_s sub_complex(struct complex_s c1, struct complex_s c2)
{
  struct complex_s result;

  result.a = c1.a - c2.a;
  result.bi = c1.bi - c2.bi;

  return result;
}

struct complex_s mult_complex(struct complex_s c1, struct complex_s c2)
{
  struct complex_s result;

  result.a = c1.a * c2.a - c1.bi * c2.bi;
  result.bi = c1.a * c2.bi + c1.bi * c2.a;
  
  return result;
}

struct complex_s div_complex(struct complex_s c1, struct complex_s c2)
{
  struct complex_s result;

  result.a = (c1.a * c2.a + c1.bi * c2.bi) / (c2.a * c2.a + c2.bi * c2.bi);
  result.bi = (c1.bi * c2.a - c1.a * c2.bi) / (c2.a * c2.a + c2.bi * c2.bi);

  return result;
}


int main(void)
{
  struct complex_s c1, c2, result;
  char operator;

  while((scan_complex_op(&c1, &c2, &operator) == 1)) {
    switch (operator) {
      case '+':
        result = add_complex(c1, c2);
        print_complex(result);
        break;
      case '-':
        result = sub_complex(c1, c2);
        print_complex(result);
        break;
      case '*':
        result = mult_complex(c1, c2);
        print_complex(result);
        break;
      case '/':
        result = div_complex(c1, c2);
        print_complex(result);
        break;
      default:
        printf("Operation '%c' invalid\n", operator);
        break;
      }
  }

  return 0;
}
