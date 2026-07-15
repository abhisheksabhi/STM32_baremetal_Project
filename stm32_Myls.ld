ENTRY(Reset_Handler)

MEMORY
{
	FLASH(rx):ORIGIN =0x08000000, LENGTH =1024K /*r= readable x = executeable*/
	SRAM(rwx):ORIGIN =0x20000000,LENGTH =128K /*r= readable w= writeable x = executeable*/
	/*SRAM1(rwx):ORIGIN =0x20000000,LENGTH =116K
	SRAM2(rwx):ORIGIN =0x20000000+116-4,LENGTH =16K*/
}

SECTIONS
{
	.text :
	{
		*(.isr_vector)	
		*(.text)	/*.text of main.o led.o stm32_startupByMe.o*/
		*(.text.*)	/*after linking stdlib there is more section so need to add in .text section */
		*(.init)
		*(.fini)
		*(.rodata)
		*(.rodata.*)
		. = ALIGN(4);
		_etext = .;
	}> FLASH /*or we can simply right (> FLASH AT> FLASH) */
	_loadaddrss_data = LOADADDR(.data);

	/* top of stack symbol */
	_estack = ORIGIN(SRAM) + LENGTH(SRAM);

	.data :
	{
		_sdata = .;
		*(.data)
		*(.data.*)
		. = ALIGN(4);
		_edata = .;
	}> SRAM AT> FLASH
	.bss :
	{
		_sbss = .;
		__bss_start__ = _sbss;
		*(.bss)
		*(.bss.*)
		. = ALIGN(4);
		*(COMMON)
		. = ALIGN(4);
		_ebss = .;
		__bss_end__ = _ebss;
		. = ALIGN(4);
		end = .;
	}> SRAM
}