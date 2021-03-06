# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    ft_write.s                                       .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2020/01/20 13:18:51 by frfrey       #+#   ##    ##    #+#        #
#    Updated: 2020/01/20 18:39:51 by frfrey      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

section .text
		global _ft_write

_error:
			mov rax, -1				; put -1 to rax
			ret						; return rax (-1)

_ft_write:							; fd = rdi, buffer = rsi, bytes = rdx
			mov rax, 0x2000004		; write() syscall
			syscall					; make the call
			cmp rdx, 0				; cheak if bytes == 0
			jne	_error				; if bytes != 0 jump end

end:
			ret						; return Value bytes = rdx
