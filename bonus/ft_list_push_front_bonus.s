# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    ft_list_push_front.s                             .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2020/01/23 17:06:19 by frfrey       #+#   ##    ##    #+#        #
#    Updated: 2020/01/23 17:43:10 by frfrey      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

section .text
		global _ft_list_push_front
		extern	_malloc												; sys function malloc is include

_ft_list_push_front:												; rdi = **begin_list, rsi = *data
						push	rsp									; align stack
						push	rdi									; save **begin_list
						push	rsi									; save data
						mov		rdi, 16								; rdi = 16
						xor		rax, rax							; ret = 0
						call	_malloc								; malloc(sizeof(t_list)) (16)
						pop		rsi									; restore data
						pop		rdi									; restor *data
						cmp		rax, 0								; rax = NULL ?
						jz		end									; rax = NULL Malloc failled
						mov		[rax], rsi							; new.data = data
						mov		rcx, [rdi]							; rcx = *begin
						mov		[rax + 8], rcx						; new.next = *begin
						mov		[rdi], rax							; *begin = new
end:
						pop		rsp									; restor stack
						ret											; return new elem
