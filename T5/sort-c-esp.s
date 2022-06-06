	.file	"sort-c-esp.c"
	.option nopic
	.attribute arch, "rv32i2p0_m2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	2
	.globl	sort
	.type	sort, @function
sort:
	slli	a7,a1,2
	addi	a7,a7,-4
	add	a7,a0,a7
	bgeu	a0,a7,.L1
	mv	a6,a0
	li	a1,32
	j	.L11
.L14:
	li	a4,0
	j	.L6
.L18:
	ret
.L3:
	lbu	a5,0(a3)
	li	a2,0
	bne	a5,zero,.L12
.L13:
	addi	a6,a6,4
	bleu	a7,a6,.L18
.L11:
	lw	a4,0(a0)
	lw	a3,4(a0)
	lbu	a5,0(a4)
	beq	a5,zero,.L3
	li	a2,0
.L5:
	sub	a5,a5,a1
	seqz	a5,a5
	add	a2,a2,a5
	addi	a4,a4,1
	lbu	a5,0(a4)
	bne	a5,zero,.L5
	lbu	a5,0(a3)
	beq	a5,zero,.L14
.L12:
	li	a4,0
.L8:
	sub	a5,a5,a1
	seqz	a5,a5
	add	a4,a4,a5
	addi	a3,a3,1
	lbu	a5,0(a3)
	bne	a5,zero,.L8
.L6:
	ble	a2,a4,.L13
	lw	a5,0(a6)
	lw	a4,4(a6)
	sw	a4,0(a6)
	sw	a5,4(a6)
	mv	a6,a0
	j	.L11
.L1:
	ret
	.size	sort, .-sort
	.ident	"GCC: (GNU) 11.1.0"
