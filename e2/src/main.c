#include "app.h"

int main(void)
{
	char *inputAmount;
	char *inputCardNumber;
	char *inputCardSecurityCode;

	// Creo los registros: ranges.dat y cards.dat
 	genCardsRegs();

	// Aquí comenzaría la apliación

	inputAmount=RequestPurchaseAmount();
	printf("> MONTO: %s\n",inputAmount);
	inputCardNumber=RequestCardNumber();
	if(_SUCCESS_ == verifyCardNumber(inputCardNumber))
	{
		inputCardSecurityCode=RequestCardSecurutyCode();
		if(NULL==inputCardSecurityCode){
			printf("> Error. No pudo completarse la operación.\n");
		}
		else{ //Si entro aqui es que tengo el código de la tarjeta
			printf("code %s\n",inputCardSecurityCode);
		}
	}

	free(inputCardSecurityCode);
	free(inputAmount);
	free(inputCardNumber);
	return 0;
}
