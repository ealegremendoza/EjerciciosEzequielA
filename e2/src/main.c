#include "app.h"

int main(void)
{
	char *RequestMessage;
	char *inputAmount;
	char *inputCardNumber;
	char *inputCardSecurityCode;

	int sockfd;
	int connectionStatus=_SOCKET_SUCCESS_;
	char ResponseMessage[RESPONSE_MENSSAGE_LEN+1];

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
		else{ //Si entro aqui es que tengo el código de la tarjeta
			RequestMessage= SetRequestMessage(	TYPE_MSG,
												strlen(inputCardNumber),
												inputCardNumber,
												inputAmount,
												inputCardSecurityCode);
			if(NULL==RequestMessage){
				printf("> Error. No pudo completarse la operación.\n");

			}
			else{//Si entro aqui es que tengo RequestMessage
			
				printf("RequestMessage: %s\n",RequestMessage);

				/*ACA LLAMAR A SOCKETT*/

				sockfd=socketCreate();
				if(_SOCKET_SUCCESS_ ==sockfd){

					if(_SOCKET_SUCCESS_==socketConnect(sockfd,SOCKET_IP_LOCAL_HOST,SOCKET_PORT))
					{
						if(_SOCKET_ERROR_ != socketWrite(sockfd,RequestMessage)){
							if(_SOCKET_ERROR_ !=socketRead(sockfd, ResponseMessage, TIMEOUT_READ_MSG )) {
								if(VALID_CODE==GetCodeFromResponseMessage(ResponseMessage)){
									printf("APROBADA\n");
								}
								else
									printf("RECHADAZA\n");

							}
							else
								connectionStatus=_SOCKET_ERROR_;
						}
						else
							connectionStatus=_SOCKET_ERROR_;

					}
					else
						connectionStatus=_SOCKET_ERROR_;

				}
				else
					connectionStatus=_SOCKET_ERROR_;

				if(_SOCKET_ERROR_==connectionStatus)
					printf("ERROR EN LA COMUNICACION\n");

				free(RequestMessage);
			}
			free(inputCardSecurityCode);
		}
	}
	
	free(inputCardNumber);
	free(inputAmount); 
	
	return 0;
}
