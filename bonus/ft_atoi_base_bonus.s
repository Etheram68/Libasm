# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    ft_atoi_base.s                                   .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2020/01/22 14:32:56 by frfrey       #+#   ##    ##    #+#        #
#    Updated: 2020/01/23 15:54:15 by frfrey      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

section .text
			global	_ft_atoi_base
			extern	_ft_strlen

_ft_atoi_base:													; rdi = *str, rsi = *base
								xor		rcx, rcx				; i = 0
								mov		r8, 1					; mov 1 on r8
								cmp		rsi, 0					; base != NULL ?
								jz		_error					; base == NULL jump _error
								cmp		rdi, 0					; str != NULL ?
								jz		_error					; str == NULL jump _error
_ft_atoi_base_len:
								push	rdi						; save str
								mov		rdi, rsi				; move *base in registry *str
								call 	_ft_strlen				; send rdi in ft_strlen
								pop		rdi						; restore *str
								cmp		rax, 1					; rax > 1 ?
								jle		_error					; rax <= 1 jump to _error
								mov		r9, rax					; save len on r9

ft_atoi_base_save:
								push	rsi						; save rsi

_ft_atoi_base_init:
								mov		al, [rsi + rcx]			; mov first char on al
								inc		rcx						; increment rcx for read next char
								cmp		al, 32					; c == space ?
								je		_error_pop				; c = space jump _error_pop
								cmp		al, 9					; c < 9 ?
								jl		_ft_atoi_base_verify	; c < 9 jump _ft_atoi_base_verify
								cmp		al, 13					; c < 13 ?
								jle		_error_pop				; c < 13 jump _error_pop
								cmp		al, 43					; c == '+' ?
								je		_error_pop				; c = '+'  jump to _error_pop
								cmp		al, 45					; c == '-' ?
								je		_error_pop				; c = '-' jum to _error_pop

_ft_atoi_base_verify:
								cmp		[rsi + rcx], al			; cmp next char == char (str[i] == c)
								je		_error_pop				; if str[i] = c jump to _error_pop
								inc		rcx						; i++
								cmp		BYTE[rsi + rcx], 0		; str[i] == '\0' ?
								je		_ft_atoi_base_move		; str[i] = '\0' jump _ft_atoi_base_move
								jmp		_ft_atoi_base_verify	; str[i] != '\0' loop on _ft_atoi_base_verify

_ft_atoi_base_move:
								inc		rsi						; *str++;
								xor		rcx, rcx				; i = 0
								cmp		BYTE[rsi], 0			; *str == '\0' ?
								jne		_ft_atoi_base_init		; *str != '\0' jump _ft_atoi_base_init

ft_atoi_base_restor:
								pop		rsi						; restore rsi

ft_atoi_whitspace:
								cmp		BYTE[rdi], 32			; *str == 32 ?
								je		ft_atoi_str_inc			; *str = ' ' jump ft_atoi_str_inc
								cmp		BYTE[rdi], 9			; *str < 9 ?
								jl		_error					; *str < 9 jump _error
								cmp		BYTE[rdi], 13			; *str <= 13 ?
								jle		ft_atoi_str_inc			; *str <= 13 jump ft_atoi_str_inc
								cmp		BYTE[rdi], 43			; *str == '+' ?
								je		ft_atoi_str_inc			; *str = '+' jump ft_atoi_str_inc
								cmp		BYTE[rdi], 45			; *str == '-' ?
								je		ft_atoi_str_inc_neg		; *str = '-' jump ft_atoi_str_inc_neg
								cmp		BYTE[rdi], 13			; *str > 13 ?
								jg		ft_atoi_init_rax		; *str > 13 jump ft_atoi_init_rax
								cmp		BYTE[rdi], 0			; *str == '\0'?
								je		_error					; *str == '\0' jump _error
								jmp		ft_atoi_whitspace		; loop ft_atoi_whitspace


ft_atoi_str_inc:
								inc		rdi						; *str++
								jmp		ft_atoi_whitspace		; jump ft_atoi_whitspace

ft_atoi_str_inc_neg:
								inc		rdi						; inc rdi
								mov		r8, -1					; mov on r8 value -1
								jmp		ft_atoi_whitspace		; jump ft_atoi_whitspace

ft_atoi_init_rax:
								xor		rax, rax				; value return = 0

ft_atoi_conv_init:
								xor		rcx, rcx				; i = 0
								mov		r10b, [rdi]				; move in r10b *str

ft_atoi_conv:
								cmp		r10b, [rsi + rcx]		; r10b == base[i] ?
								je		ft_atoi_calc			; r10b = base[i] jmp ft_atoi_calc
								cmp		BYTE[rsi + rcx], 0		; base[i] == '\0' ?
								je		_ft_init_return			; base[i] = '\0' jmp _ft_init_return
								cmp		BYTE[rdi], 0			; *str == '\0' ?
								je		_ft_init_return			; *str = '\0' jmp _ft_init_return

ft_atoi_conv_inc:
								inc		rcx						; i++
								jmp		ft_atoi_conv			; jump ft_atoi_conv

ft_atoi_calc:
								imul	rax, r9					; ret = ret * base_len
								add		rax, rcx				; ret += i
								cmp		BYTE[rdi], 0			; *str == '\0' ?
								je		_ft_init_return			; *str = '\0' jmp _ft_init_return
								inc		rdi						; *str++
								jmp		ft_atoi_conv_init		; jmp ft_atoi_conv_init

_ft_init_return:
								imul	rax, r8					; ret = ret * is_neg
								jmp		end						; jmp end

_error_pop:
								pop		rsi						; restore rsi

_error:
								xor 	rax, rax				; value of return = 0

end:
								ret								; return value
