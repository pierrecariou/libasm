global ft_strcpy

section .text
ft_strcpy:
	push rbp
	mov rbp, rsp
	mov r11, rdi
	jmp _loop

_loop:
	cmp byte [rsi], 0
	je _end
	mov al, [rsi]
	mov [rdi], al
	inc rsi
	inc rdi
	jmp _loop

_end:
	mov al, [rsi]
	mov [rdi], al
	mov rax, r11
	jmp _ret

_ret:
	leave
	ret
