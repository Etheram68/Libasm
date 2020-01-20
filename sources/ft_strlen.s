# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    ft_strlen.s                                      .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2020/01/18 17:09:12 by frfrey       #+#   ##    ##    #+#        #
#    Updated: 2020/01/20 17:02:20 by frfrey      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

section .text
		global _ft_strlen

_ft_strlen:
			xor		rax, rax 			; i = 0

_ft_strlen_loop:
			cmp		BYTE[rdi + rax], 0	; Str[i] == '\0' rdi = "MA CHAINE" + rax = "Mon indice" Byte  = 1 octet
			je		end					; Si BYTE[rdi + rax] = 0 return
			inc		rax					; i++
			jmp		_ft_strlen_loop		; loop to ft_strlen_next

end:
	ret									; return i
