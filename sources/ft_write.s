# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    ft_write.s                                       .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2020/01/20 13:18:51 by frfrey       #+#   ##    ##    #+#        #
#    Updated: 2020/01/20 13:39:53 by frfrey      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

section .text
		global _ft_write

_ft_write:							; fd = rdi, buffer = rsi, bytes = rdx
			mov rax, 0x2000004		; write() syscall
			syscall					; make the call
			ret						; return Value bytes = rdx
