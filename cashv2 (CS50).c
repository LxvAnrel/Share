#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h> //não está sendo utilizado neste código

// Variáveis globais
int count = 0;
int twfive = 0;
int ten = 0;
int five = 0;
int one = 0;
float valPay;
float valTroco;
float troco;

// Declaração das funções
void rtntroco(void);

int main(void)
{
    float valSale = get_float("Por favor, digite o valor da compra: \n(Use '.', não ',') R$");

    do
    {
        valPay = (get_float("Por favor, digite o valor pago: \n(Use '.', não ',') R$")*100);
    }
    while (valPay < valSale * 100);

    valTroco = valPay - (valSale * 100); // Calcula o valor do troco
    troco = valTroco;

    rtntroco();
}

void rtntroco(void)
{
    while (valTroco > 0) // Enquanto o troco não for '0' continue a subtrair o valor
    {
        if (valTroco >= 25) // -25 cents
        {
            count++;
            twfive++;
            valTroco -= 25;
        }
        else if (valTroco >= 10) // -10 cents
        {
            count++;
            ten++;
            valTroco -= 10;
        }
        else if (valTroco >= 5) // -5 cents
        {
            count++;
            five++;
            valTroco -= 5;
        }
        else // -1 cent
        {
            count++;
            one++;
            valTroco -= 1;
        }
    }
    printf(
        "Você precisará de %i moedas para o troco (R$%.2f):\n%i de 0,25 Cents\n%i de 0,10 Cents\n"
        "%i de 0,05 Cents\n%i de 0,01 Cents\n",
        count, troco / 100, twfive, ten, five, one);
}

