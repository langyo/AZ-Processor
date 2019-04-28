/*
 -- ============================================================================
 -- FILE NAME	: if_reg.v
 -- DESCRIPTION : IFステージパイプラインレジスタ
 -- ----------------------------------------------------------------------------
 -- Revision  Date		  Coding_by	 Comment
 -- 1.0.0	  2011/06/27  suito		 新規作成
 -- ============================================================================
*/

/********** 共通ヘッダファイル **********/
`include "nettype.h"
`include "global_config.h"
`include "stddef.h"

/********** 個別ヘッダファイル **********/
`include "isa.h"
`include "cpu.h"

/********** モジュール **********/
module if_reg (
	/********** クロック & リセット **********/
	input  wire				   clk,		   // クロック
	input  wire				   reset,	   // 非同期リセット
	/********** フェッチデータ **********/
	input  wire [`WordDataBus] insn,	   // フェッチした命令
	/********** パイプライン制御信号 **********/
	input  wire				   stall,	   // ストール
	input  wire				   flush,	   // フラッシュ
	input  wire [`WordAddrBus] new_pc,	   // 新しいプログラムカウンタ
	input  wire				   br_taken,   // 分岐の成立
	input  wire [`WordAddrBus] br_addr,	   // 分岐先アドレス
	/********** IF/IDパイプラインレジスタ **********/
	output reg	[`WordAddrBus] if_pc,	   // プログラムカウンタ
	output reg	[`WordDataBus] if_insn,	   // 命令
	output reg				   if_en	   // パイプラインデータの有効
);

	/********** パイプラインレジスタ **********/
	always @(posedge clk or `RESET_EDGE reset) begin
		if (reset == `RESET_ENABLE) begin 
			/* 非同期リセット */
			if_pc	<= #1 `RESET_VECTOR;
			if_insn <= #1 `ISA_NOP;
			if_en	<= #1 `DISABLE;
		end else begin
			/* パイプラインレジスタの更新 */
			if (stall == `DISABLE) begin 
				if (flush == `ENABLE) begin				// フラッシュ
					if_pc	<= #1 new_pc;
					if_insn <= #1 `ISA_NOP;
					if_en	<= #1 `DISABLE;
				end else if (br_taken == `ENABLE) begin // 分岐の成立
					if_pc	<= #1 br_addr;
					if_insn <= #1 insn;
					if_en	<= #1 `ENABLE;
				end else begin							// 次のアドレス
					if_pc	<= #1 if_pc + 1'd1;
					if_insn <= #1 insn;
					if_en	<= #1 `ENABLE;
				end
			end
		end
	end

endmodule
