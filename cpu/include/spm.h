/*
 -- ============================================================================
 -- FILE NAME	: spm.h
 -- DESCRIPTION : スクラッチパッドメモリヘッダ
 -- ----------------------------------------------------------------------------
 -- Revision  Date		  Coding_by	 Comment
 -- 1.0.0	  2011/06/27  suito		 新規作成
 -- ============================================================================
*/

`ifndef __SPM_HEADER__
	`define __SPM_HEADER__			  // インクルードガード

/*
 * 【SPMのサイズについて】
 * ・SPMのサイズを変更するには、
 *	 SPM_SIZE、SPM_DEPTH、SPM_ADDR_W、SpmAddrBus、SpmAddrLocを変更して下さい。
 * ・SPM_SIZEはSPMのサイズを定義しています。
 * ・SPM_DEPTHはSPMの深さを定義しています。
 *	 SPMの幅は基本的に32bit（4Byte）固定なので、
 *	 SPM_DEPTHはSPM_SIZEを4で割った値になります。
 * ・SPM_ADDR_WはSPMのアドレス幅を定義しており、
 *	 SPM_DEPTHをlog2した値になります。
 * ・SpmAddrBusとSpmAddrLocはSPM_ADDR_Wのバスです。
 *	 SPM_ADDR_W-1:0として下さい。
 *
 * 【SPMのサイズの例】
 * ・SPMのサイズが16384Byte（16KB）の場合、
 *	 SPM_DEPTHは16384÷4で4096
 *	 SPM_ADDR_Wはlog2(4096)で12となります。
 */
/*
 *  （由 @Switefaster 翻译）
 * 【关于 SPM 的大小】
 * ・要变更 SPM 的大小时、
 *	 请变更SPM_SIZE、SPM_DEPTH、SPM_ADDR_W、SpmAddrBus、SpmAddrLoc。
 * ・SPM_SIZE定义了SPM的大小。
 * ・SPM_DEPTH定义了SPM的深度。
 *   由于 SPM 的宽度基本固定在 32bit(4Byte)
 *	 SPM_DEPTH会是SPM_SIZE除以四的结果。
 * ・SPM_ADDR_W定义了SPM的地址宽度
 *	  值是 SPM_DEPTH 求 log2 的结果
 * ・SpmAddrBus和SpmAddrLoc是SPM_ADDR_W的BUS。
 *	 请使 SPM_ADDR_W-1:0。
 *
 * 【SPM大小的例子】
 * ・当SPM大小是16384Byte（16KB）的场合、
 *	 SPM_DEPTH是16384÷4得4096
 *	 SPM_ADDR_W是log2(4096)得12。
 */

	`define SPM_SIZE   16384 // SPMのサイズ
	`define SPM_DEPTH  4096	 // SPMの深さ
	`define SPM_ADDR_W 12	 // アドレス幅
	`define SpmAddrBus 11:0	 // アドレスバス
	`define SpmAddrLoc 11:0	 // アドレスの位置

`endif
