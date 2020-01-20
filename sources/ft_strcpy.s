# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    ft_strcpy.s                                      .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2020/01/20 17:56:39 by frfrey       #+#   ##    ##    #+#        #
#    Updated: 2020/01/20 18:29:26 by frfrey      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

section .text
		global _ft_strcpy

_ft_strcpy:									; rsi = src, rdi = dest
				xor	rax, rax				; rax = 0
				xor	rcx, rcx				; i = 0

_ft_strcpy_loop:
				mov	al, [rsi + rcx]			; char c = rsi[i]
				mov	[rdi + rcx], al			; dest[i] = c
				inc	rcx						; i++
				cmp	al, 0					; c == '\0' ?
				je	end						; c == '\0' jump to end
				jmp	_ft_strcpy_loop			; loop to _ft_strcpy_loop

end:
				mov	rax, rdi				; mov dest in rax
				ret							; return dest
