#include "minitalk.h"

void	send_message(pid_t pid, char *str)
{
	int				i;
	unsigned char	letter;

	while (*str)
	{
		i = 0;
		letter = *str;
		while (i < 8)
		{
			if ((letter & (0x01 << i)) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(200);
			i++;
		}
		str++;
	}
}

void	sent(int sig, siginfo_t *info, void *cont)
{
	(void) info;
	(void) cont;
	if (sig == SIGUSR1)
		ft_printf("Received\n");
}

void	validate_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("ERROR: Invalid number of arguments!\n");
		ft_printf("Try: ./client [server PID] [message]\n");
		exit(1);
	}
	while (argv[1][i])
	{
		if (!ft_isdigit(argv[1][i++]))
		{
			ft_printf("Invalid PID\n");
			exit(1);
		}
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid; 
	char				*str;
	struct sigaction	sig;

	sig.sa_sigaction = &sent;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	validate_args(argc, argv);
	pid = (pid_t)ft_atoi(argv[1]); 
	str = argv[2];
	send_message(pid, str);
	send_message(pid, "\n");
	while (1) 
		pause ();
	return (0); 
}
