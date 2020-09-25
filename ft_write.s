extern __errno_location
global ft_write

section .text
ft_write:
	push rbp
	mov rbp, rsp
	mov rax, 1
	syscall
	cmp rax, 0
	jl _error
	mov rax, rdx
	jmp _ret

_error:
	neg eax
	mov rdx, rax
	call __errno_location
	mov [rax], rdx
	mov rax, -1
	jmp _ret

_ret:
	leave
	ret
