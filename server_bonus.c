#include "minitalk.h"

void	receive_message(int signal, siginfo_t *info, void *context)
{
	static int	i; 
	static int	letter;

	(void)context;
	if (signal == SIGUSR1)
		letter |= (0x01 << i); 
	i++;
	if (i == 8) 
	{
		ft_printf("%c", letter); 
		i = 0; 
		letter = 0;
		kill(info->si_pid, SIGUSR1);
	}
}

void	set_sigaction(void)
{
	struct sigaction	sig;

	sig.sa_sigaction = &receive_message;
	sig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sig, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &sig, NULL) == -1)
		exit(1);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error: No Arguments Allowed\n");
		return (1);
	}
	set_sigaction();
	ft_printf("Welcome to the server\n");
	ft_printf("PID: %d\n", getpid());
	ft_printf("Waiting for a message...\n");
	while (1)
		pause(); 
	return (0);
}
