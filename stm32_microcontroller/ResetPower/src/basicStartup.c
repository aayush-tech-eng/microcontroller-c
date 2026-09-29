int main(void)
{
	System_Init();
	GPIO_Init();
	Clock_Init();
	UART_Init();
	
	while(1)
	{
		Application_Run();
	}
}