global ft_write

section .text
ft_write:
	push rbp
	mov rbp, rsp
	mov rax, 1
	syscall
	cmp rsi, 0
	je _error
	mov rax, rdx
	jmp _ret

_error:
	mov rax, -1
	jmp _ret

_ret:
	leave
	ret
