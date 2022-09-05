	.file	"gddr6.s"
	.text
	.section	.rodata
.LC0:
	.string	"/dev/mem"
.LC1:
	.string	"\rGDDR6 VRAM Temp: %d\302\260c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movl	%edi, -68(%rbp)
	movq	%rsi, -80(%rbp)
	movl	$4096, -56(%rbp)
	movl	$-83886080, -52(%rbp)
	movl	-52(%rbp), %eax
	addl	$58024, %eax
	movl	%eax, -48(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, -24(%rbp)
.L5:
	movq	-24(%rbp), %rax
	movl	$1052674, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	open@PLT
	movl	%eax, -44(%rbp)
	cmpl	$-1, -44(%rbp)
	jne	.L2
	movl	$-1, %edi
	call	exit@PLT
.L2:
	movl	$30, %edi
	call	sysconf@PLT
	subl	$1, %eax
	notl	%eax
	movl	%eax, %edx
	movl	-48(%rbp), %eax
	andl	%edx, %eax
	movl	%eax, -40(%rbp)
	movl	-40(%rbp), %ecx
	movl	-56(%rbp), %eax
	cltq
	movl	-44(%rbp), %edx
	movq	%rcx, %r9
	movl	%edx, %r8d
	movl	$1, %ecx
	movl	$3, %edx
	movq	%rax, %rsi
	movl	$0, %edi
	call	mmap@PLT
	movq	%rax, -16(%rbp)
	cmpq	$0, -16(%rbp)
	jne	.L3
	movl	$-1, %edi
	call	exit@PLT
.L3:
	movl	-48(%rbp), %edx
	movl	-40(%rbp), %eax
	subq	%rax, %rdx
	movq	-16(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -36(%rbp)
	movl	-36(%rbp), %eax
	andl	$4095, %eax
	movl	%eax, -32(%rbp)
	movl	-32(%rbp), %eax
	shrl	$5, %eax
	movl	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	stdout(%rip), %rax
	movq	%rax, %rdi
	call	fflush@PLT
	movl	-56(%rbp), %eax
	movslq	%eax, %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	munmap@PLT
	cmpl	$-1, %eax
	jne	.L4
	movl	$-1, %edi
	call	exit@PLT
.L4:
	movl	-44(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
	movl	$1, %edi
	call	sleep@PLT
	jmp	.L5
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
