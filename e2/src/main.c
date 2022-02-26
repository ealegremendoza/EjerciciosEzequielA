#include "app.h"

int main(void)
{
	char *inputAmount;
	char *inputCardNumber;

	
	inputAmount=RequestPurchaseAmount();
	printf("> MONTO: %s\n",inputAmount);
	inputCardNumber=RequestCardNumber();
	printf("> CARD NUMBER: %s\n",inputCardNumber);

	free(inputAmount);
	free(inputCardNumber);
	return 0;
}
