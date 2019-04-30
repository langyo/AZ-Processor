/*
 -- ============================================================================
 -- FILE NAME	: rom.h
 -- DESCRIPTION : ROM ヘッダ
 -- ----------------------------------------------------------------------------
 -- Revision  Date		  Coding_by	 Comment
 -- 1.0.0	  2011/06/27  suito		 新規作成
 -- ============================================================================
*/

`ifndef __ROM_HEADER__
	`define __ROM_HEADER__			  // インクルードガード

/*
 * 【ROMのサイズについて】
 * ・ROMのサイズを変更するには、
 *	 ROM_SIZE、ROM_DEPTH、ROM_ADDR_W、RomAddrBus、RomAddrLocを変更して下さい。
 * ・ROM_SIZEはROMのサイズを定義しています。
 * ・ROM_DEPTHはROMの深さを定義しています。
 *	 ROMの幅は基本的に32bit（4Byte）固定なので、
 *	 ROM_DEPTHはROM_SIZEを4で割った値になります。
 * ・ROM_ADDR_WはROMのアドレス幅を定義しており、
 *	 ROM_DEPTHをlog2した値になります。
 * ・RomAddrBusとRomAddrLocはROM_ADDR_Wのバスです。
 *	 ROM_ADDR_W-1:0として下さい。
 *
 * 【ROMのサイズの例】
 * ・ROMのサイズが8192Byte（4KB）の場合、
 *	 ROM_DEPTHは8192÷4で2048
 *	 ROM_ADDR_Wはlog2(2048)で11となります。
 */
/*
 *  （由 @Switefaster 翻译）
 * 【关于ROM大小】
 * ・若要更改 ROM 大小
 *	 请更改 ROM_SIZE、ROM_DEPTH、ROM_ADDR_W、RomAddrBus、RomAddrLoc。
 * ・ROM_SIZE定义了ROM的大小。
 * ・ROM_DEPTH定义了ROM的深度。
 *	 因为ROM的宽度基本固定在 32bit(4Byte)、
 *	 ROM_DEPTH将会是ROM_SIZE除以四的值。
 * ・ROM_ADDR_W定义了ROM的地址宽度、
 *	 将会是log2ROM_DEPTH。
 * ・RomAddrBus和RomAddrLoc是ROM_ADDR_W的BUS。
 *	 请将使ROM_ADDR_W-1:0。(?没听懂)
 *
 * 【ROM大小的例子】
 * ・当ROM大小是8192Byte（4KB）的场合、
 *	 ROM_DEPTH是8192/4=2048
 *	 ROM_ADDR_W是log2(2048)。
 */


	`define ROM_SIZE   8192	// ROMのサイズ
	`define ROM_DEPTH  2048	// ROMの深さ
	`define ROM_ADDR_W 11	// アドレス幅
	`define RomAddrBus 10:0 // アドレスバス
	`define RomAddrLoc 10:0 // アドレスの位置

`endif
