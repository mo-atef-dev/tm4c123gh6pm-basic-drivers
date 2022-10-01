.global IntCtrl_EnableSpecialRegisters

.p2align 2
.type IntCtrl_EnableSpecialRegisters, %function
.section .text

IntCtrl_EnableSpecialRegisters:
	.fnstart
	MOV r1, #0xFFFE
	MOVT r1, 0xFFFF
	MRS r2, PRIMASK
	AND r2, r1
	MSR PRIMASK, r2
	
	MOV r1, #0xFFFE
	MOVT r1, 0xFFFF
	MRS r2, PRIMASK
	AND r2, r1
	MSR FAULTMASK, r2
	
	LSL r1, r0, #5
	AND r1, #0x00E0
	MOVT r1, 0x0000
	MRS r2, BASEPRI
	ORR r2, r1
	MSR BASEPRI, r2
	
	bx lr
	.fnend