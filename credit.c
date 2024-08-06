#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaração de váriaveis globais
char brandcard[20];
char numbercard[18];
int nsize = 0;

int validate(char x[18])
{
    int pos = nsize - 1;
    int secnumbers = 0;
    char secprod[2];
    int sumnumbers = 0;
    int nconverter;
    int result;
    do
    {
        nconverter = x[pos] - '0';
        nconverter = nconverter * 2;
        if (nconverter >= 10){
            secprod = strcpy(nconverter);
            secnumbers += secprod[0] + secprod[1];
        } else {
            secnumbers += nconverter;
        }
        pos = pos - 2;
    }
    while (pos >= 0);

    printf("Esse foi o resultado das multiplicações %i\n", secnumbers);

    pos = nsize;
    do
    {
        nconverter = x[pos] - '0';
        sumnumbers += nconverter;
        pos = pos - 2;
    }
    while (pos >= 0);

    printf("Esse foi o resultado das somas %i\n", sumnumbers);

    result = sumnumbers + secnumbers;

    printf("Esse foi o resultado final %i\n", result);

    return (result % 10 == 0);
}

void validatebrandcard(void)
{
    int brand = 0;

    for (int i = 1; i >= 0; i--)
    {
        if (i == 1)
        {
            brand = numbercard[i] - '0';
        }
        else
        {
            brand += (numbercard[i] - '0') * 10;
        }
    }

    if (brand == 34 || brand == 37){
        strcpy(brandcard, "American Express");
    } if (brand >= 51 & brand <= 55){
        strcpy(brandcard, "MasterCard");
    } if (numbercard[0] == '4'){
        strcpy(brandcard, "Visa");
    } else {
        strcpy(brandcard, "Other Brand");
    }
}

int main()
{
    printf("Número do Cartão: ");
    scanf("%s", numbercard);
    nsize = strlen(numbercard) - 1;

    if (validate(numbercard))
    {
        validatebrandcard();
        printf("%s\n%s\n", numbercard, brandcard);
    }
    else
    {
        printf("O número do cartão é inválido.\n");
    }
    return 0;
}
