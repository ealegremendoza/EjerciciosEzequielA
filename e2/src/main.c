#include "app.h"

int main(void)
{
	char *RequestMessage;
	char *inputAmount;
	char *inputCardNumber;
	char *inputCardSecurityCode;

	// Creo los registros: ranges.dat y cards.dat
 	genCardsRegs();

	// Aquí comenzaría la apliación

	inputAmount=RequestPurchaseAmount();
	inputCardNumber=RequestCardNumber();
	if(_SUCCESS_ == verifyCardNumber(inputCardNumber))
	{
		inputCardSecurityCode=RequestCardSecurutyCode();
		if(NULL==inputCardSecurityCode){
			printf("> Error. No pudo completarse la operación.\n");
		}
		else{ //Si entro aqui es que tengo el código de la tarjeta
			RequestMessage= SetRequestMessage(	TYPE_MSG,
												strlen(inputCardNumber),
												inputCardNumber,
												inputAmount,
												inputCardSecurityCode);
			printf("RequestMessage: %s\n",RequestMessage);

			free(RequestMessage);
		}
	}


	free(inputCardSecurityCode);
	free(inputAmount);
	free(inputCardNumber);
	//RequestMessage= SetRequestMessage("0200",13,"1111111112345","000000001253","179");
	//printf("RequestMessage: %s\n",RequestMessage);
	
	return 0;
}
