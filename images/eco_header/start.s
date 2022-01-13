.global _start
_start:
	LDR r0, =0xE100B00c
	MOV r1, #0x80
	STR r1, [r0]		/*write COM_UART_TCR register 0x80 */

	LDR r0, =0xE100B000
	MOV r1, #0x01
	STR r1, [r0]		/*write COM_UART_DLL register 0x01*/

	LDR r0, =0xE100B004
	MOV r1, #0x0
	STR r1, [r0]		/*write COM_UART_DLH register 0x0*/

	LDR r0, =0xE100B00c
	MOV r1, #0x03
	STR r1, [r0]		/*write COM_UART_TCR register 0x03*/

	LDR r0, =0xE100B008
	MOV r1, #0x37
	STR r1, [r0]		/*write COM_UART_FCR register 0x37*/

	LDR r2, =0xE100B000
	MOV	r3, #0x55
	STR	r3, [r2]	/*COM_UART output 0x55*/


	/*mov r0,  #0xE0040200  */   /*next boot start addr */
	/*mov r1,  #0xA0800000  */    /*sec_ram start_addr  */
	/*mov r2,  #0xE0040400  */    /*next boot end addr   */

	MOV r2, #0x0
	ADR r2, _start		/*_start=text_base=0xE0040000 */

	ADD r0,r2,#0x200	/*r0=0xE0040000+0x200=0xE0040200*/
	ADD r2,r2,#0x400	/*r2=0xE0040000+0x400=0xE0040400*/
	LDR r1, =0xA0800000

copy_next_boot:
	LDMIA  r0!,{r9-r10}
	STMIA  r1!, {r9-r10}
	CMP   r0, r2
	BNE	copy_next_boot

jump_to_sec_ram:
	LDR lr ,=0xA0800000
	MOV pc,lr
