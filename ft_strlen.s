global ft_strlen

section .text
ft_strlen:
	push rbp
	mov rbp, rsp
	mov rcx, 0
	mov r10, rdi
	jmp _loop

_loop:
	cmp byte [r10], 0
	je _end
	inc r10
	inc rcx
	jmp _loop

_end:
	mov rax, rcx
	jmp _ret

_ret:
	leave
	ret
