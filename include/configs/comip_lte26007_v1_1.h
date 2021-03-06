/*
 * (C) Copyright 2003-2004
 *
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_ENV_OVERWRITE
/*
 * High Level Configuration Options
 * (easy to change)
 */
#define CONFIG_ARMCORTEXA7              /* This is an ARM V7 CPU core */
#define CONFIG_ARMCORTEXM0	1       /* This is an ARM M0 CPU core */
#define CONFIG_CPU_LC1860	1
#define CONFIG_BOARD_EARLY_INIT_F 1

#define CONFIG_COMIP			1
#define CONFIG_COMIP_LTE26007_V1_1 	1

#define CONFIG_CURR_PRODUCT_NAME	"wt26047"

/*
 * Memory controller default configuration.
 */
#define CONFIG_MEMCTL0_CS0_SIZE	(0x20000000UL)		// max 1G (0x40000000UL)
#define CONFIG_MEMCTL0_CS1_SIZE	(0x20000000UL)		// max 1G (0x40000000UL)
#define CONFIG_MEMCTL1_CS0_SIZE	(0UL)			// max 1G (0x40000000UL)
#define CONFIG_MEMCTL1_CS1_SIZE	(0UL)			// max 1G (0x40000000UL)

/*
 * Framebuffer memory configuration.
 */
#define CONFIG_FB_MEMORY_FIX		1
#define CONFIG_FB_MEMORY_SIZE		(0x00400000UL)
#define CONFIG_FB_MEMORY_NUM		(3)

/*
 * On2 memory configuration.
 */
//#define CONFIG_ON2_MEMORY_FIX		1
//#define CONFIG_ON2_MEMORY_SIZE		(50 * 1024 * 1024)

/*
 * Modem memory configuration.
 */
#define CONFIG_MODEM_MEMORY_SIZE	(100 * 1024 * 1024UL)
#define CONFIG_MODEM_MEMORY_BASE	(0)

#define PHYS_SDRAM_1			0
#define CONFIG_NR_DRAM_BANKS_MAX	2

/*
 * Must check CONFIG_DDR_2CS_SIGNAL for every ddr config
 * if CONFIG_MULTI_DDR_SUPPORT is enabled.
 */
#define CONFIG_MULTI_DDR_SUPPORT	1
#if defined(CONFIG_MULTI_DDR_SUPPORT)
#define CONFIG_GATE_TRAINING_SUPPORT	1
#define CONFIG_HYNIX_H9TQ65A8GTMCUR	1 //8Gb-1cs

// 2GB
#define CONFIG_SAMSUNG_KMR310001M	1 //2GB-2cs
#define CONFIG_MICRON_MT29TZZZ5D6YKFAH	1 //2GB-2cs // same as hynix H9TQ17ABJTMCUR

#define CONFIG_SAMSUNG_KMQ310013M	1 //2GB

#endif


//#define CONFIG_DEBUG_TIMER_ID		1 /* Never set to 0. */
#define CONFIG_SAVE_DDR_ON_FLASH	1

#if defined(CONFIG_SAVE_DDR_ON_FLASH)||defined(CONFIG_MULTI_DDR_SUPPORT)
#define CONFIG_COMIP_EMMC_ENHANCE	1
#endif

#if defined(CONFIG_COMIP_EMMC_ENHANCE)
#define CONFIG_MMC_STRUCT_IN_GD		512
#endif


#define CONFIG_DDR_BUS_CLK		533000000    /* Configure DDR bus clock. */
#define CONFIG_A7_CLK			1495000000   /* Configure A7 clock. */

#define CONFIG_DDR_BYPASS_ENABLE		1


#define CONFIG_WATCHDOG_ENABLE		0
#define CONFIG_WATCHDOG_DEBUG		0

#define CONFIG_HA_START_ADDR    (0xE0040000)
#define CONFIG_SA_START_ADDR    (0xE0040000)

#define CONFIG_TOP_RAM1_ADDR    (0xE0040000)
#define CONFIG_TOP_RAM1_SIZE    (256 * 1024)
/*
 *Base.
 */
#define CONFIG_COMIP_I2C		1
#define CONFIG_COMIP_TIMER		1
#define CONFIG_COMIP_MFP2		1
#define CONFIG_COMIP_GPIO		1

/*
 * NAND.
 */
//#define CONFIG_COMIP_NAND		1
#ifdef CONFIG_COMIP_NAND
#define CONFIG_COMIP_NAND_DMA		1
//#define CONFIG_COMIP_NAND_NODMA		1
#endif

/*
 * eMMC/SD.
 */
#define CONFIG_COMIP_MMC		1
#ifdef CONFIG_COMIP_MMC
#define CONFIG_GENERIC_MMC
#define CONFIG_COMIP_MMC_DMA		1
//#define CONFIG_COMIP_MMC_NODMA		1
#define CONFIG_COMIP_MMC_PULLUP		1
#endif

/*
 * Keypad.
 */
#define CONFIG_COMIP_KEYPAD		1
#define CONFIG_KEYPAD_GPIO_KEY
#define CONFIG_KEYPAD_GPIO_PULLUP
#define VOL_UP_KEYCODE		KEYPAD_GPIO_KEYCODE(72, 0)
#define VOL_DOWN_KEYCODE	KEYPAD_GPIO_KEYCODE(73, 0)

#define KEY_CODE_RECOVERY	(KEYPAD_VOL_UP | KEYPAD_VOL_DOWN)
#define KEY_CODE_AMT3		(KEYPAD_VOL_UP)

/*
 * comip_lp_regs_init.
 */
#define COMIP_LOW_POWER_MODE_ENABLE 1
#define CONFIG_BUS_LP_ENABLE		1
#define CONFIG_DEBUG_CLOCK_DISABLED	1

/*
 * PMIC Setting.
 */
#define CONFIG_COMIP_PMIC			1
#define CONFIG_PMIC_LC1160			1
#define CONFIG_PMIC_VIBRATOR			1
#define CONFIG_CHARGER_BQ24158			1

#define CONFIG_LOW_VOLTAGE_CHARGING		1
#define CONFIG_CHARGER_POWER_OFF_LEVEL		(3400) /* mv */
#define CONFIG_NO_CHARGER_POWER_OFF_LEVEL	(3500) /* mv */

//#define CONFIG_NCP6335				1
#ifdef CONFIG_NCP6335
#define CONFIG_USE_EXT_BUCK2			0
#endif

#define CONFIG_LEDS_AW2013			1

/*
    BUCK2 voltage select(DVFS).
    1: Only use DVFS0 pin.
    2: Only use DVFS1 pin.
    3: Use DVFS0&DVFS1 pins.
*/
#if (CONFIG_USE_EXT_BUCK2 == 0)
#define BUCK2_VOUT_SEL				(3)
#else
#define BUCK2_VOUT_SEL				(1)
#endif

/* Buck1 voltage(DVFS). */
#define BUCK1_VOUT_LEVEL_0			(7250)  /* 0.1mv */
#define BUCK1_VOUT_LEVEL_1			(9125) /* 0.1mv */

/* BUCK2 voltage(DVFS). */
#define BUCK2_VOUT_LEVEL_0			(7250)  /* 0.1mv */
#define BUCK2_VOUT_LEVEL_1			(9000) /* 0.1mv */
#define BUCK2_VOUT_LEVEL_2			(9000) /* 0.1mv */

/* BUCK3 voltage(DVFS). */
#define BUCK3_VOUT_LEVEL_0			(7250)  /* 0.1mv */
#define BUCK3_VOUT_LEVEL_1			(8500) /* 0.1mv */
#define BUCK3_VOUT_LEVEL_2			(9000) /* 0.1mv */
#define BUCK3_VOUT_LEVEL_3			(10000) /* 0.1mv */

/* BUCK4 voltage(DVFS). */
#define BUCK4_VOUT_LEVEL_0			(11500) /* 0.1mv */

/* BUCK5 voltage(DVFS). */
#define BUCK5_VOUT_LEVEL_0			(1150) /* mv */
#define BUCK5_VOUT_LEVEL_1			(1200) /* mv */

/* BUCK6 voltage(DVFS). */
#define BUCK6_VOUT_LEVEL_0			(1750) /* mv */
#define BUCK6_VOUT_LEVEL_1			(1800) /* mv */

/*
 * NS16550 Configuration
 */
#define CONFIG_SYS_NS16550		1
#define CONFIG_SYS_NS16550_SERIAL	1
#define CONFIG_SYS_NS16550_REG_SIZE	(-4)
#define CONFIG_SYS_NS16550_CLK		(921600)	   /* can be 12M/32Khz or 48Mhz */
#define CONFIG_SYS_NS16550_COM1	   	(0xE100B000)

/*
 * Select serial console configuration
 */
#define CONFIG_CONS_INDEX		1
#define CONFIG_BAUDRATE			115200
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600,  115200 }

#define CONFIG_CMDLINE_TAG	   	1
#define CONFIG_SETUP_MEMORY_TAGS   	1

#ifndef CONFIG_SYS_TEXT_BASE
#define CONFIG_SYS_TEXT_BASE    0xE0040000
#endif

#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + 128 * 1024)

#define CONFIG_BOOTARGS_ENABLE		1
#define CONFIG_BOOTDELAY		10
#define CONFIG_BOOTARGS			"console=ttyS3,115200 vmalloc=412M " CONFIG_BOOTARGS_RAMDISK CONFIG_BOOTARGS_MEM "android "
#define CONFIG_RECOVERY_BOOTARGS		"console=ttyS3,115200 vmalloc=412M " CONFIG_BOOTARGS_RECOVERY_RAMDISK CONFIG_BOOTARGS_MEM "android "
#define CONFIG_BOOTARGS_CHARGE_ONLY		"loglevel=0 console=ttyS3,115200 vmalloc=412M " CONFIG_BOOTARGS_RAMDISK CONFIG_BOOTARGS_MEM "android "

/*
 * Miscellaneous configurable options
 */

#define CONFIG_SYS_PROMPT		"leadcore comip # "	/* Monitor Command Prompt   */
#define CONFIG_SYS_CBSIZE		256	/* Console I/O Buffer Size  */

/* Print Buffer Size */
#define CONFIG_SYS_PBSIZE		(CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_MAXARGS		16	/* max number of command args   */
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE	/* Boot Argument Buffer Size    */

#define CONFIG_SYS_LOAD_ADDR		(CONFIG_SYS_SDRAM_BASE)	/* default load address */
#define CONFIG_SYS_SDRAM_BASE		0x00000000
#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_TOP_RAM1_ADDR + CONFIG_TOP_RAM1_SIZE - GENERATED_GBL_DATA_SIZE)

/*-----------------------------------------------------------------------
 * Stack sizes
 *
 * The stack sizes are set up in start.S using the settings below
 */

#define CONFIG_STACKSIZE		(16 * 1024)	/* regular stack */
#define CONFIG_STACKSIZE_IRQ		(5 * 1024)
#define CONFIG_STACKSIZE_FIQ		(5 * 1024)


#define CONFIG_BOOTARGS_MEM			""

#define CONFIG_BOOTARGS_RAMDISK			"initrd=0x07400000,1M "
#define CONFIG_BOOTARGS_RECOVERY_RAMDISK	"initrd=0x07400000,3M "
#define CONFIG_RAMDISK_LOADADDR			(0x07400000)

#define CONFIG_KERNEL_MEMORY_BASE	(CONFIG_MODEM_MEMORY_SIZE)
#define CONFIG_KERNEL_LOADADDR		(CONFIG_KERNEL_MEMORY_BASE + 0x8000)
#define CONFIG_BOOT_PARAMS_LOADADDR	(CONFIG_KERNEL_MEMORY_BASE + 0x100)

/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */
#define CONFIG_SYS_NO_FLASH

#define CONFIG_ENV_SIZE			(20 * 1024)	/* Total Size of Environment Sector */

#define CONFIG_ENV_IS_NOWHERE

/*-----------------------------------------------------------------------
 * FLASH partition
 */
#define CONFIG_USE_KERNEL_RECOVERY		1
#define CONFIG_USE_RAMDISK_AMT3			1

#define PART_NAME(X)    	CONFIG_PARTITION_##X
#define PART_START(X)  	CONFIG_PART_##X##_START
#define PART_LEN(X)	CONFIG_PART_##X##_LEN

#define CONFIG_EMMC_SIZE		(7.28*1024*1024*2)

#define CONFIG_PARTITION_UBOOT		"uboot"
#define CONFIG_PARTITION_LCBOOT		"lcboot"
#define CONFIG_PARTITION_FASTBOOT_LOGO	"fastboot_logo"
#define CONFIG_PARTITION_LOGO		"logo"
#define CONFIG_PARTITION_FOTA			"fota"
#define CONFIG_PARTITION_AMT			"amt"
#define CONFIG_PARTITION_PANIC		"panic"
#define CONFIG_PARTITION_TOS			"tos"
#define CONFIG_PARTITION_MODEM_ARM		"modemarm"
#define CONFIG_PARTITION_MODEM_DSP		"modemdsp"
#define CONFIG_PARTITION_KERNEL		"kernel"
#define CONFIG_PARTITION_RAMDISK		"ramdisk"
#define CONFIG_PARTITION_RAMDISK_AMT1	"ramdisk_amt1"
#define CONFIG_PARTITION_RAMDISK_AMT3	"ramdisk_amt3"
#define CONFIG_PARTITION_RAMDISK_RECOVERY	"ramdisk_recovery"
#define CONFIG_PARTITION_KERNEL_RECOVERY	"kernel_recovery"
#define CONFIG_PARTITION_DDR			"ddronflash"
#define CONFIG_PARTITION_MISC			"misc"
#define CONFIG_PARTITION_CACHE		"cache"
#define CONFIG_PARTITION_SYSTEM		"system"
#define CONFIG_PARTITION_UDISK                    	"udisk"
#define CONFIG_PARTITION_USERDATA		"userdata"

#define CONFIG_PART_UBOOT_LEN		0x00000200//256K
#define CONFIG_PART_GAP1_LEN			0x00000200//256K
#define CONFIG_PART_LCBOOT_LEN		0x00000400//512K
#define CONFIG_PART_FASTBOOT_LOGO_LEN	0x00002000//4M
#define CONFIG_PART_LOGO_LEN			0x00002000//4M
#define CONFIG_PART_FOTA_LEN			0x00000800//1M
#define CONFIG_PART_GAP2_LEN			0x00000800//1M
#define CONFIG_PART_AMT_LEN			0x00001000//2M
#define CONFIG_PART_PANIC_LEN			0x00001000//2M
#define CONFIG_PART_TOS_LEN			0x00005000//10M
#define CONFIG_PART_MODEM_ARM_LEN		0x0000B000//22M
#define CONFIG_PART_MODEM_DSP_LEN		0x0000B000//22M
#define CONFIG_PART_KERNEL_LEN		0x00003000//6M
#define CONFIG_PART_GAP3_LEN			0x00001000//2M
#define CONFIG_PART_RAMDISK_LEN		0x00000800//1M
#define CONFIG_PART_RAMDISK_AMT1_LEN	0x00000800//1M
#define CONFIG_PART_RAMDISK_AMT3_LEN	0x00000800//1M
#define CONFIG_PART_RAMDISK_RECOVERY_LEN	0x00001800//3M
#define CONFIG_PART_KERNEL_RECOVERY_LEN	0x00003000//6M
#define CONFIG_PART_DDR_LEN			0x00000400//512K
#define CONFIG_PART_GAP4_LEN			0x00001400//2.5M
#define CONFIG_PART_MISC_LEN			0x00001000//2M
#define CONFIG_PART_CACHE_LEN		0x00040000//128M
#define CONFIG_PART_SYSTEM_LEN		0x002c0000//1408M
#define CONFIG_PART_USERDATA_LEN		(CONFIG_EMMC_SIZE-CONFIG_PART_USERDATA_START)

#define CONFIG_PART_UBOOT_START 	0x00000000
#define CONFIG_PART_LCBOOT_START        (CONFIG_PART_UBOOT_START + CONFIG_PART_UBOOT_LEN + CONFIG_PART_GAP1_LEN)
#define CONFIG_PART_FASTBOOT_LOGO_START 	(CONFIG_PART_LCBOOT_START + CONFIG_PART_LCBOOT_LEN)
#define CONFIG_PART_LOGO_START        	(CONFIG_PART_FASTBOOT_LOGO_START + CONFIG_PART_FASTBOOT_LOGO_LEN)
#define CONFIG_PART_FOTA_START        	(CONFIG_PART_LOGO_START + CONFIG_PART_LOGO_LEN)
#define CONFIG_PART_AMT_START        	(CONFIG_PART_FOTA_START + CONFIG_PART_FOTA_LEN + CONFIG_PART_GAP2_LEN)
#define CONFIG_PART_PANIC_START        	(CONFIG_PART_AMT_START + CONFIG_PART_AMT_LEN)
#define CONFIG_PART_TOS_START        	(CONFIG_PART_PANIC_START + CONFIG_PART_PANIC_LEN)
#define CONFIG_PART_MODEM_ARM_START    		(CONFIG_PART_TOS_START + CONFIG_PART_TOS_LEN)
#define CONFIG_PART_MODEM_DSP_START   		(CONFIG_PART_MODEM_ARM_START + CONFIG_PART_MODEM_ARM_LEN)
#define CONFIG_PART_KERNEL_START        			(CONFIG_PART_MODEM_DSP_START + CONFIG_PART_MODEM_DSP_LEN)
#define CONFIG_PART_RAMDISK_START			(CONFIG_PART_KERNEL_START + CONFIG_PART_KERNEL_LEN + CONFIG_PART_GAP3_LEN)
#define CONFIG_PART_RAMDISK_AMT1_START        		(CONFIG_PART_RAMDISK_START + CONFIG_PART_RAMDISK_LEN)
#define CONFIG_PART_RAMDISK_AMT3_START       		(CONFIG_PART_RAMDISK_AMT1_START + CONFIG_PART_RAMDISK_AMT1_LEN)
#define CONFIG_PART_RAMDISK_RECOVERY_START	(CONFIG_PART_RAMDISK_AMT3_START + CONFIG_PART_RAMDISK_AMT3_LEN)
#define CONFIG_PART_KERNEL_RECOVERY_START    	(CONFIG_PART_RAMDISK_RECOVERY_START + CONFIG_PART_RAMDISK_RECOVERY_LEN)
#define CONFIG_PART_DDR_START     	(CONFIG_PART_KERNEL_RECOVERY_START + CONFIG_PART_KERNEL_RECOVERY_LEN)
#define CONFIG_PART_MISC_START        	(CONFIG_PART_DDR_START + CONFIG_PART_DDR_LEN + CONFIG_PART_GAP4_LEN)
#define CONFIG_PART_CACHE_START       	(CONFIG_PART_MISC_START + CONFIG_PART_MISC_LEN)
#define CONFIG_PART_SYSTEM_START     	(CONFIG_PART_CACHE_START + CONFIG_PART_CACHE_LEN)
#define CONFIG_PART_USERDATA_START   (CONFIG_PART_SYSTEM_START + CONFIG_PART_SYSTEM_LEN)

#define CONFIG_COMIP_PARTITIONS		\
	{0x200, PART_START(UBOOT), 	 PART_LEN(UBOOT), 	PART_NAME(UBOOT)},  	\
	{0x200, PART_START(LCBOOT), 	 PART_LEN(LCBOOT), 	PART_NAME(LCBOOT)}, 	\
	{0x200, PART_START(FASTBOOT_LOGO), 	 PART_LEN(FASTBOOT_LOGO), 	PART_NAME(FASTBOOT_LOGO)},    	\
	{0x200, PART_START(LOGO), 	 PART_LEN(LOGO), 	PART_NAME(LOGO)},    	\
	{0x200, PART_START(FOTA), 	 PART_LEN(FOTA), 	PART_NAME(FOTA)},    	\
	{0x200, PART_START(AMT), 	 PART_LEN(AMT), 	PART_NAME(AMT)}, 	\
	{0x200, PART_START(PANIC), 	 PART_LEN(PANIC), 	PART_NAME(PANIC)},	\
	{0x200, PART_START(TOS), 	 PART_LEN(TOS), 	PART_NAME(TOS)}, 	\
	{0x200, PART_START(MODEM_ARM), PART_LEN(MODEM_ARM),  PART_NAME(MODEM_ARM)}, \
	{0x200, PART_START(MODEM_DSP),	 PART_LEN(MODEM_DSP), 	PART_NAME(MODEM_DSP)}, \
	{0x200, PART_START(KERNEL), 	 PART_LEN(KERNEL), 	PART_NAME(KERNEL)}, \
	{0x200, PART_START(RAMDISK), 	 PART_LEN(RAMDISK), 	PART_NAME(RAMDISK)}, \
	{0x200, PART_START(RAMDISK_AMT1), PART_LEN(RAMDISK_AMT1), PART_NAME(RAMDISK_AMT1)}, \
	{0x200, PART_START(RAMDISK_AMT3), PART_LEN(RAMDISK_AMT3), PART_NAME(RAMDISK_AMT3)}, \
	{0x200, PART_START(RAMDISK_RECOVERY), 	PART_LEN(RAMDISK_RECOVERY), PART_NAME(RAMDISK_RECOVERY)}, \
	{0x200, PART_START(KERNEL_RECOVERY), 	PART_LEN(KERNEL_RECOVERY),    PART_NAME(KERNEL_RECOVERY)}, \
	{0x200, PART_START(DDR), 	 PART_LEN(DDR), 	PART_NAME(DDR)}, \
	{0x200, PART_START(MISC), 	 PART_LEN(MISC), 	PART_NAME(MISC)}, \
	{0x200, PART_START(CACHE), 	 PART_LEN(CACHE), 	PART_NAME(CACHE)}, \
	{0x200, PART_START(SYSTEM), 	 PART_LEN(SYSTEM), 	PART_NAME(SYSTEM)}, \
	{0x200, PART_START(USERDATA), 	 PART_LEN(USERDATA), 	PART_NAME(USERDATA)},
/*-----------------------------------------------------------------------
 * External functions
 */
//#define CONFIG_DDR_MEMTEST		1

#define CONFIG_COMIP_FASTBOOT		1

#if defined(CONFIG_SAVE_DDR_ON_FLASH) || defined(CONFIG_COMIP_FASTBOOT)
#define CONFIG_FALSH_WRITE		1
#endif

#ifdef CONFIG_COMIP_FASTBOOT

#define CONFIG_USB_GADGET
#define CONFIG_USB_GADGET_DUALSPEED
#define CONFIG_USB_GADGET_FASTBOOT

#define CONFIG_KEY_CODE_FASTBOOT	(KEYPAD_VOL_DOWN)
#define CONFIG_USE_IRQ			1


#define USB_DDR_MEMORY_SIZE		(1024 * 1024)
#define CONFIG_FASTBOOT_BUFFER_SIZE	(800 * 1024 * 1024)

#define CONFIG_USB_HIGH			1
#define CONFIG_USB_DEBUG		1
#define CONFIG_SERIAL_DEBUG		1

/*
 * LCD.
 */
#define CONFIG_LCD_SUPPORT		1

#if defined (CONFIG_LCD_SUPPORT)
#define CONFIG_FB_COMIP2		1
#define CONFIG_FB_COMIP_LCDC2		1
#define CONFIG_FB_COMIP_MIPI		1
#define CONFIG_LCD_SHARP_R69431		1
#define CONFIG_LCD_AUO_OTM1285A_OTP	1
#define CONFIG_LCD_AUO_R61308OTP	1
#define CONFIG_LCD_AUO_NT35521		1

#define LCD_RESET_PIN		(154)
#define LCD_BACKLIGHT_PIN	(153)
#endif

#endif

//#define CONFIG_EFI_PARTITION		1
#ifdef CONFIG_EFI_PARTITION
#define CONFIG_PARTITIONS		1
#define HAVE_BLOCK_DEVICE		1
#define CONFIG_PARTITION_UUIDS		1
#endif

#endif /* ! __CONFIG_H */
