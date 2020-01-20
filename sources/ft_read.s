# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    ft_read.s                                        .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2020/01/20 13:41:18 by frfrey       #+#   ##    ##    #+#        #
#    Updated: 2020/01/20 18:43:05 by frfrey      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

section	.text
		global _ft_read

_error:
		mov rax, -1				; put -1 on rax
		ret						; return rax(-1)

_ft_read:						; fd = rdi, buffer = rsi, bytes = rdx
		mov rax, 0x2000003		; read() syscall
		syscall					; make the call
		cmp rdx, 0				; check if bytes == 0
		jne _error				; if byte != 0 jump _error
		ret

end:
		ret						; return rax
