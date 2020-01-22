# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    ft_strdup.s                                      .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2020/01/22 10:57:37 by frfrey       #+#   ##    ##    #+#        #
#    Updated: 2020/01/22 15:34:25 by frfrey      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

section .text
		global	_ft_strdup
		extern	_malloc									; sys function malloc is include
		extern	_ft_strcpy								; include function strcpy
		extern	_ft_strlen								; include function strlen

_ft_strdup:												; rdi = str
						xor		rcx, rcx				; i = 0
						cmp 	rdi, 0					; str != NULL
						jz		_error					; str = 0 (NULL) jump _Error

_ft_strdup_len:
						call	_ft_strlen				; Call function strlen
						mov		rcx, rax				; mov value return in rcx

_ft_strdup_malloc:
						inc 	rcx						; i++
						push	rdi						; save rdi
						mov		rdi, rcx				; rdi == i
						call	_malloc					; rdi = malloc(rcx)
						pop		rdi						; restor rdi
						cmp		rax, 0					; rax != NULL
						jz		_error					; rax == NULL jump _error

_ft_strdup_copy:
						mov		rsi, rdi				; rsi (src) == rdi (str)
						mov		rdi, rax				; rdi (dest) == malloc string
						call	_ft_strcpy				; send all to function strcpy
						cmp		rax, 0					; chaine malloc != of NULL
						jnz		end						; if != null jump to end

_error:
						xor		rax, rax				; value of return == 0

end:
						ret								; return rax
