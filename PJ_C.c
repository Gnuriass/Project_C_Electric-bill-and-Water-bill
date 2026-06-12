#include <stdio.h>
#include <stdlib.h>
float all = 0, water = 0, electric = 0;
void calElectric();
void calWater();

int main()
{
  int a = 0, day = 0;
  float avg = 0;
  char reset;
  do
  {
    printf("------------------------------\n");
    printf("Electric bill (1) or Water bill (2)\n");
    printf("------------------------------\n");
    printf("Ender Number (1) or (2) : ");
    scanf("%d", &a);
    printf("------------------------------\n");
    switch (a)
    {

    case 1:
      calElectric();
      day++;
      break;
    case 2:
      calWater();
      day++;
      break;

    default:
      printf("No case found\n");
    }
    printf("Reset (y/n) : ");
    fflush(stdin);
    scanf("%s", &reset);
  } while (reset == 'y');
  avg = all / day;
  printf("Your average cost is %.2f bath\n", avg);
  if (electric > water)
  {
    printf("Your Electric bill cost more than your Water bill by %.2f bath\n", electric - water);
  }
  else if (electric < water)
  {
    printf("Your Water bill cost more than your Electric bill by %.2f bath\n", water - electric);
  }

  printf("\n---Thank you for using the service.---\n");

  return 0;
}

void calElectric()
{
  float meter_inp, tl, ft = 0.9343, sv = 8.19;
  printf("Electric bill \n");
  printf("----------------\n");
  printf("Electric input : ");
  scanf("%f", &meter_inp);

  if (meter_inp >= 0 && meter_inp <= 15)
  {
    tl = meter_inp * 2.3488;
  }
  else if (meter_inp >= 16 && meter_inp <= 25)
  {
    tl = (15 * 2.3488) + ((meter_inp - 15) * 2.9882);
  }
  else if (meter_inp >= 26 && meter_inp <= 35)
  {
    tl = (15 * 2.3488 + 10 * 2.9882) + ((meter_inp - 25) * 3.2405);
  }
  else if (meter_inp >= 36 && meter_inp <= 100)
  {
    tl =
        (15 * 2.3488 + 10 * 2.9882 + 10 * 3.2405) + ((meter_inp - 35) * 3.6237);
  }
  else if (meter_inp >= 101 && meter_inp <= 150)
  {
    tl = (15 * 2.3488 + 10 * 2.9882 + 10 * 3.2405 + 65 * 3.6237) +
         ((meter_inp - 100) * 3.7171);
  }
  else if (meter_inp >= 151 && meter_inp <= 400)
  {
    tl = (15 * 2.3488 + 10 * 2.9882 + 10 * 3.2405 + 65 * 3.6237 + 50 * 3.7171) +
         ((meter_inp - 150) * 4.2218);
  }
  else if (meter_inp >= 401)
  {
    tl = (15 * 2.3488 + 10 * 2.9882 + 10 * 3.2405 + 65 * 3.6237 + 50 * 3.7171 +
          250 * 4.2218) +
         ((meter_inp - 400) * 4.4217);
  }

  if (meter_inp >= 0)
  {
    printf("Electric bill %.2f baht \n", tl);
    printf("Service        %.2f baht \n", sv);
    printf("Electric Ft   %.2f baht \n", ft * meter_inp);
    printf("tax 7%%         %.2f baht \n", ((tl + sv + ft * meter_inp) * 0.07));
    printf("Total         %.2f baht \n", (tl + sv + ft * meter_inp) * 1.07);
    all = all + (tl + sv + ft * meter_inp) * 1.07;
    electric = electric + (tl + sv + ft * meter_inp) * 1.07;
  }
}

void calWater()
{
  float cst = 0, meter_size = 0, total = 0, service = 0;
  printf("Water Bill \n");
  printf("----------------\n");
  printf("Meter Size : ");
  scanf("%f", &meter_size);
  printf("Water consumption : ");
  scanf("%f", &cst);

  if (meter_size < 0)
  {
    printf("erorr\n");
  }
  else if (meter_size == 0)
  {
    service = 0;
  }
  else if (meter_size <= 0.5)
  {
    service = 25;
  }
  else if (meter_size <= 0.75)
  {
    service = 40;
  }
  else if (meter_size <= 1)
  {
    service = 50;
  }
  else if (meter_size <= 1.5)
  {
    service = 80;
  }
  else if (meter_size <= 2)
  {
    service = 300;
  }
  else if (meter_size <= 3)
  {
    service = 400;
  }
  else if (meter_size <= 4)
  {
    service = 500;
  }
  else if (meter_size <= 6)
  {
    service = 900;
  }
  else if (meter_size <= 8)
  {
    service = 1100;
  }
  else if (meter_size <= 12)
  {
    service = 3500;
  }
  else if (meter_size <= 16)
  {
    service = 5000;
  }
  else
  {
    printf("\n Error : invalid Meter size\n");
    return;
  }

  for (int i = 1; i <= cst; i++)
  {
    if (i <= 30)
    {
      total += 8.50;
    }
    else if (i > 30 && i <= 40)
    {
      total += 10.03;
    }
    else if (i > 40 && i <= 50)
    {
      total += 10.35;
    }
    else if (i > 50 && i <= 60)
    {
      total += 10.68;
    }
    else if (i > 60 && i <= 70)
    {
      total += 11;
    }
    else if (i > 70 && i <= 80)
    {
      total += 11.33;
    }
    else if (i > 80 && i <= 90)
    {
      total += 12.50;
    }
    else if (i > 90 && i <= 100)
    {
      total += 12.82;
    }
    else if (i > 100 && i <= 120)
    {
      total += 13.15;
    }
    else if (i > 120 && i <= 160)
    {
      total += 13.47;
    }
    else if (i > 160 && i <= 200)
    {
      total += 13.80;
    }
    else
    {
      total += 14.45;
    }
  }
  if (meter_size >= 0)
  {
    printf("Water bill \t %.2f\tbaht \n", total);
    printf("Water \t\t %.2f\tbaht \n", cst * 0.15);
    printf("Service \t %.2f\tbaht \n", service);
    printf("tax 7%% \t\t %.2f\tbaht \n", (total + service + cst * 0.15) * 0.07);
    printf("Total \t\t %.2f\tbaht \n", (total + service + cst * 0.15) * 1.07);
    all = all + (total + service + cst * 0.15) * 1.07;
    water = water + (total + service + cst * 0.15) * 1.07;
  }

  cst = 0, meter_size = 0, total = 0, service = 0;
}

#include <stdio.h>
#include <stdlib.h>
float all = 0, water = 0, electric = 0;
void calElectric();
void calWater();

int main()
{
  int a = 0, day = 0;
  float avg = 0;
  char reset;
  do
  {
    printf("------------------------------\n");
    printf("Electric bill (1) or Water bill (2)\n");
    printf("------------------------------\n");
    printf("Ender Number (1) or (2) : ");
    scanf("%d", &a);
    printf("------------------------------\n");
    switch (a)
    {

    case 1:
      calElectric();
      day++;
      break;
    case 2:
      calWater();
      day++;
      break;

    default:
      printf("No case found\n");
    }
    printf("Reset (y/n) : ");
    fflush(stdin);
    scanf("%s", &reset);
  } while (reset == 'y');
  avg = all / day;
  printf("Your average cost is %.2f bath\n", avg);
  if (electric > water)
  {
    printf("Your Electric bill cost more than your Water bill by %.2f bath\n", electric - water);
  }
  else if (electric < water)
  {
    printf("Your Water bill cost more than your Electric bill by %.2f bath\n", water - electric);
  }

  printf("\n---Thank you for using the service.---\n");

  return 0;
}

void calElectric()
{
  float meter_inp, tl, ft = 0.9343, sv = 8.19;
  printf("Electric bill \n");
  printf("----------------\n");
  printf("Electric input : ");
  scanf("%f", &meter_inp);

  if (meter_inp >= 0 && meter_inp <= 15)
  {
    tl = meter_inp * 2.3488;
  }
  else if (meter_inp >= 16 && meter_inp <= 25)
  {
    tl = (15 * 2.3488) + ((meter_inp - 15) * 2.9882);
  }
  else if (meter_inp >= 26 && meter_inp <= 35)
  {
    tl = (15 * 2.3488 + 10 * 2.9882) + ((meter_inp - 25) * 3.2405);
  }
  else if (meter_inp >= 36 && meter_inp <= 100)
  {
    tl =
        (15 * 2.3488 + 10 * 2.9882 + 10 * 3.2405) + ((meter_inp - 35) * 3.6237);
  }
  else if (meter_inp >= 101 && meter_inp <= 150)
  {
    tl = (15 * 2.3488 + 10 * 2.9882 + 10 * 3.2405 + 65 * 3.6237) +
         ((meter_inp - 100) * 3.7171);
  }
  else if (meter_inp >= 151 && meter_inp <= 400)
  {
    tl = (15 * 2.3488 + 10 * 2.9882 + 10 * 3.2405 + 65 * 3.6237 + 50 * 3.7171) +
         ((meter_inp - 150) * 4.2218);
  }
  else if (meter_inp >= 401)
  {
    tl = (15 * 2.3488 + 10 * 2.9882 + 10 * 3.2405 + 65 * 3.6237 + 50 * 3.7171 +
          250 * 4.2218) +
         ((meter_inp - 400) * 4.4217);
  }

  if (meter_inp >= 0)
  {
    printf("Electric bill %.2f baht \n", tl);
    printf("Service        %.2f baht \n", sv);
    printf("Electric Ft   %.2f baht \n", ft * meter_inp);
    printf("tax 7%%         %.2f baht \n", ((tl + sv + ft * meter_inp) * 0.07));
    printf("Total         %.2f baht \n", (tl + sv + ft * meter_inp) * 1.07);
    all = all + (tl + sv + ft * meter_inp) * 1.07;
    electric = electric + (tl + sv + ft * meter_inp) * 1.07;
  }
}

void calWater()
{
  float cst = 0, meter_size = 0, total = 0, service = 0;
  printf("Water Bill \n");
  printf("----------------\n");
  printf("Meter Size : ");
  scanf("%f", &meter_size);
  printf("Water consumption : ");
  scanf("%f", &cst);

  if (meter_size < 0)
  {
    printf("erorr\n");
  }
  else if (meter_size == 0)
  {
    service = 0;
  }
  else if (meter_size <= 0.5)
  {
    service = 25;
  }
  else if (meter_size <= 0.75)
  {
    service = 40;
  }
  else if (meter_size <= 1)
  {
    service = 50;
  }
  else if (meter_size <= 1.5)
  {
    service = 80;
  }
  else if (meter_size <= 2)
  {
    service = 300;
  }
  else if (meter_size <= 3)
  {
    service = 400;
  }
  else if (meter_size <= 4)
  {
    service = 500;
  }
  else if (meter_size <= 6)
  {
    service = 900;
  }
  else if (meter_size <= 8)
  {
    service = 1100;
  }
  else if (meter_size <= 12)
  {
    service = 3500;
  }
  else if (meter_size <= 16)
  {
    service = 5000;
  }
  else
  {
    printf("\n Error : invalid Meter size\n");
    return;
  }

  for (int i = 1; i <= cst; i++)
  {
    if (i <= 30)
    {
      total += 8.50;
    }
    else if (i > 30 && i <= 40)
    {
      total += 10.03;
    }
    else if (i > 40 && i <= 50)
    {
      total += 10.35;
    }
    else if (i > 50 && i <= 60)
    {
      total += 10.68;
    }
    else if (i > 60 && i <= 70)
    {
      total += 11;
    }
    else if (i > 70 && i <= 80)
    {
      total += 11.33;
    }
    else if (i > 80 && i <= 90)
    {
      total += 12.50;
    }
    else if (i > 90 && i <= 100)
    {
      total += 12.82;
    }
    else if (i > 100 && i <= 120)
    {
      total += 13.15;
    }
    else if (i > 120 && i <= 160)
    {
      total += 13.47;
    }
    else if (i > 160 && i <= 200)
    {
      total += 13.80;
    }
    else
    {
      total += 14.45;
    }
  }
  if (meter_size >= 0)
  {
    printf("Water bill \t %.2f\tbaht \n", total);
    printf("Water \t\t %.2f\tbaht \n", cst * 0.15);
    printf("Service \t %.2f\tbaht \n", service);
    printf("tax 7%% \t\t %.2f\tbaht \n", (total + service + cst * 0.15) * 0.07);
    printf("Total \t\t %.2f\tbaht \n", (total + service + cst * 0.15) * 1.07);
    all = all + (total + service + cst * 0.15) * 1.07;
    water = water + (total + service + cst * 0.15) * 1.07;
  }

  cst = 0, meter_size = 0, total = 0, service = 0;
}

