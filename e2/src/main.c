#include "app.h"

int main(void)
{
	char *inputAmount;
	char *inputCardNumber;
	char *inputCardSecurityCode;

	// Creo los registros: ranges.dat y cards.dat
	if(_ERROR_==genCardsRegs()){
		printf("> Error. No pudieron crearse los registros.\n");
		return -1;
	}
 	

	// Aquí comenzaría la apliación

	inputAmount=RequestPurchaseAmount();
	if(NULL==inputAmount){
		printf("> Error. No pudo completarse la operación.\n");
		return -1;
	}

	inputCardNumber=RequestCardNumber();
	if(_SUCCESS_ == verifyCardNumber(inputCardNumber))
	{
		inputCardSecurityCode=RequestCardSecurutyCode();
		if(NULL==inputCardSecurityCode){
			printf("> Error. No pudo completarse la operación.\n");
		}
		else{ //Si entro aqui es que tengo el código de la tarjeta **
			ValidateTransaction(	SOCKET_IP_LOCAL_HOST,
										SOCKET_PORT,
										TYPE_MSG,
										strlen(inputCardNumber),
										inputCardNumber,
										inputAmount,
										inputCardSecurityCode,
										TIMEOUT_READ_MSG
										);
			free(inputCardSecurityCode);
		}
		
	}

	free(inputCardNumber);
	free(inputAmount); 
	
	return 0;
}

