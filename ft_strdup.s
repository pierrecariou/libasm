global ft_strdup

extern ft_strlen
extern malloc
extern ft_strcpy

section .text
ft_strdup:
	push rbp
	mov rbp, rsp
	mov r12, rdi
	call ft_strlen
	add rax, 1
	jmp _malloc

_malloc:
	mov rdi, rax
	call malloc
	cmp rax, 0
	je _ret
	jmp _cpy

_cpy:
	mov rdi, rax
	mov rsi, r12
	call ft_strcpy
	jmp _ret

_ret:
	leave
	ret
