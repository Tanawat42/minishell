# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjukmong <tjukmong@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/27 21:14:32 by tjukmong          #+#    #+#              #
#    Updated: 2023/05/21 12:30:57 by tjukmong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Static Libaray name.
NAME		= libft.a

# Header file include dirrectory.
HEAD		= .

# To test the libaray, create a file with the same name as TESTFILE and play
# arround with it :D (output executable will be named after this option with
# .out extension, with .log file created, for log file obviously).
TESTFILE	= main.c
LOGFILE		= ${TESTFILE:.c=.log}

# Source dirrectory.
DIRSRC		= ./

# Source files.
SRC			= ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c\
			ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
			ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c\
			ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c\
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c\
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
			ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c\
			ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c\
			ft_strnstr_notqoute.c ft_split_notqoute.c

BONUS	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

# Object files (similar to DLLs)
# Path to object files
SRCS			= ${addprefix ${DIRSRC}, ${SRC}}
BONUSES			= ${addprefix ${DIRSRC}, ${BONUS}}
# Source objects (replaces .c with .o).
SRCOBJ			= ${SRCS:.c=.o}
# Bonus objects (same thing as SRCOBJ, but for BONUS)
BONUSOBJ		= ${BONUSES:.c=.o}

# C Compiler.
CC				= gcc
# CC Flags
CFLAGS			= -Wall -Wextra -Werror

# Remove files.
RM				= rm -f

# Link sources, if not specified (default).
all:			${NAME}

bonus:			all
				${CC} ${CFLAGS} -c ${BONUSES}
				ar rc ${NAME} ${BONUSOBJ}

# Link mandatory.
${NAME}:		$(SRCOBJ)
				ar rc ${NAME} ${SRCOBJ}

# Tester file
test:			all
	${CC} ${CFLAGS} ${TESTFILE} ${NAME} -o ${TESTFILE:.c=.out}
	@ echo -e "\033[1;36m========-[ Execution output ]-========\033[0;37m"	  > ${LOGFILE}
	@ exec ${DIRSRC}${TESTFILE:.c=.out} | cat -e							 >> ${LOGFILE}
	@ echo -e "\n\033[1;35m============-[ Valgrind ]-============\033[0;37m" >> ${LOGFILE}
	@ valgrind ${DIRSRC}${TESTFILE:.c=.out} -qs --leak-check=full			 >> ${LOGFILE} 2>&1
	@ echo -e "\033[1;32m===========-[ Norm errors ]-==========\033[0;37m"	 >> ${LOGFILE}
	@ norminette ${DIRSRC} | grep "Error" | cat								 >> ${LOGFILE}
	@ echo -e "\033[1;32m======================================\033[0;37m"	 >> ${LOGFILE}
	@ less -R ${LOGFILE}

readlog:
	less -R ${LOGFILE}

# Annnddd Lastly...
clean:
				${RM} ${SRCOBJ} ${BONUSOBJ}

fclean:			clean
				${RM} ${NAME} ${TESTFILE:.c=.out} ${LOGFILE}

re:				fclean all

.PHONY:			all test clean fclean re
