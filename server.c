#include "minitalk.h"

void	receive_letter(int signal)
{
	static int	i;
	static int	letter;

	if (signal == SIGUSR1)
		letter |= (0x01 << i);
	i++;
	if (i == 8)
	{
		ft_printf("%c", letter);
		i = 0;
		letter = 0;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error: No Arguments Allowed\n");
		return (1);
	}
	ft_printf("Welcome to the server\n");
	ft_printf("PID: %d\n", getpid());
	ft_printf("Waiting for a message...\n");
	while (1)
	{
		signal(SIGUSR1, &receive_letter);
		signal(SIGUSR2, &receive_letter); 
		pause();
	}
	return (0);
}
