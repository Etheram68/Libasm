# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    ft_strcmp.s                                      .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2020/01/20 16:02:21 by frfrey       #+#   ##    ##    #+#        #
#    Updated: 2020/01/20 16:56:48 by frfrey      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

section .text
		global _ft_strcmp

_ft_strcmp:									; *s1 = rdi, *s2 = rsi
		xor rax, rax						; i = 0;

_ft_strcmp_loop:
		mov	al, [rdi]						; char c = *s1
		cmp	[rsi], al						; char c == *s2
		jne	end								; c != *s2 jmp end
		inc	rdi								; *s1++
		inc	rsi								; *s2++
		cmp	BYTE[rdi], 0					; *s1 == '\0' ?
		je	end								; *s1 == '\0' jmp end
		cmp	BYTE[rsi], 0					; *s2 == '\0' ?
		je	end								; *s2 == '\0' jmp end
		jmp	_ft_strcmp_loop					; loop _ft_strcmp_loop

end:
		movzx	rax, BYTE[rdi]				; char i = *s1
		movzx	rdx, BYTE[rsi]				; char y = *s2
		sub		rax, rdx					; i = i - y
		ret									; return i
