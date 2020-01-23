# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    ft_list_size.s                                   .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2020/01/23 17:28:39 by frfrey       #+#   ##    ##    #+#        #
#    Updated: 2020/01/23 17:39:12 by frfrey      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

section .text
		global _ft_list_size

_ft_list_size:													; rdi = *begin_list
						xor		rax, rax						; value ret = 0
_ft_list_count:
						cmp		rdi, 0							; begin == NULL ?
						jz		end								; begin = NULL jump end
						mov		rdi, [rdi + 8]					; begin = begin.next
_inc:
						inc		rax								; total = 0
						jmp		_ft_list_count					; loop _ft_list_count
end:
						ret										; return len

