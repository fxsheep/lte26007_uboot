
.global _start_second
_start_second:
	LDR r2, =0xE100B000
	MOV	r3, #0x56
	STR	r3, [r2]			/*COM_UART output 0x56*/


	ldr  r0 ,=0xE0040400     /*r0,DDR uboot  address,copy src*/
	ldr  r1 ,=0xE0040000      /*r1,DDR uboot  text base ,copy dst */

	ldr r2 , =0x0003FC00     /*copy size=256K-1k=255k*/
	add r2, r2,r0                 /*copy end addr copy_src+copy_size */

copy_uboot_forword:
	ldmia  r0!,{r7-r10}
	stmia  r1!, {r7-r10}
	cmp   r0, r2
	bne	copy_uboot_forword

jump_to_ddr:
	ldr lr ,=0xe0040000
	mov pc,lr
