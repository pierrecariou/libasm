global ft_strcmp

section .text
ft_strcmp:
	push rbp
	mov rbp, rsp
	mov rax, 0
	mov r11, 0
	jmp _loop

_loop:
	cmp byte [rdi], 0
	je _end
	cmp byte [rsi], 0
	je _end
	mov al, [rdi]
	mov r11b, [rsi]
	cmp al, r11b
	jne _end
	inc rdi
	inc rsi
	jmp _loop

_end:
	mov al, [rdi]
	mov r11b, [rsi]
	sub rax, r11
	jmp _ret

_ret:
	leave
	ret
