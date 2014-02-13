typedef void (*isr_handler)(void);

extern int _stack_top;
#define STACK_TOP (unsigned int)(&_stack_top)

extern void reset_handler(void);
extern void nmi_handler(void);
extern void hard_fault_handler(void);
extern void mem_manager_handler(void);
extern void bus_fault_handler(void);
extern void usage_fault_handler(void);
extern void sv_call_handler(void);
extern void debug_mon_handler(void);
extern void pend_sv_handler(void);
extern void sys_tick_handler(void);
extern void wakeup_irq_handler(void);
extern void i2c_irq_handler(void);
extern void timer16_0_irq_handler(void);
extern void timer16_1_irq_handler(void);
extern void timer32_0_irq_handler(void);
extern void timer32_1_irq_handler(void);
extern void ssp_irq_handler(void);
extern void uart_irq_handler(void);
extern void usb_irq_handler(void);
extern void usb_fiq_handler(void);
extern void adc_irq_handler(void);
extern void wdt_irq_handler(void);
extern void bod_irq_handler(void);
extern void fmc_irq_handler(void);
extern void pio_int3_irq_handler(void);
extern void pio_int2_irq_handler(void);
extern void pio_int1_irq_handler(void);
extern void pio_int0_irq_handler(void);


#define NO_CRP_MAGIC 0xFFFFFFFF
#define CRP_WORD NO_CRP_MAGIC


__attribute__ ((section(".vector_table")))
const isr_handler vectors[256]=
{
	(isr_handler)(STACK_TOP),                 // #0   (0x000) Initial stack pointer


	(isr_handler)(reset_handler),             // #1   (0x004) Reset handler
	(isr_handler)(nmi_handler),               // #2   (0x008) NMI handler
	(isr_handler)(hard_fault_handler),        // #3   (0x00C) Hard Fault handler
	(isr_handler)(mem_manager_handler),       // #4   (0x010) Memory Manager handler
	(isr_handler)(bus_fault_handler),         // #5   (0x014) Bus fault handler
	(isr_handler)(usage_fault_handler),       // #6   (0x018) Usage fault handler

	(isr_handler)(0xFFFFFFFF),                // #7   (0x01C) Checksum (make by external tools)

	(isr_handler)(0x00000000),                // #8   (0x020) Reserved
	(isr_handler)(0x00000000),                // #9   (0x024) Reserved
	(isr_handler)(0x00000000),                // #10  (0x028) Reserved
	(isr_handler)(sv_call_handler),           // #11  (0x02C) SVCall handler
	(isr_handler)(debug_mon_handler),         // #12  (0x030) Debug Monitor handler
	(isr_handler)(0x00000000),                // #13  (0x034) Reserved
	(isr_handler)(pend_sv_handler),           // #14  (0x038) PendSV handler
	(isr_handler)(sys_tick_handler),          // #15  (0x03C) SysTick handler


	(isr_handler)(wakeup_irq_handler),        // #16  (0x040) Wakeup PIO0_0 handler
	(isr_handler)(wakeup_irq_handler),        // #17  (0x044) Wakeup PIO0_1 handler
	(isr_handler)(wakeup_irq_handler),        // #18  (0x048) Wakeup PIO0_2 handler
	(isr_handler)(wakeup_irq_handler),        // #19  (0x04C) Wakeup PIO0_3 handler
	(isr_handler)(wakeup_irq_handler),        // #20  (0x050) Wakeup PIO0_4 handler
	(isr_handler)(wakeup_irq_handler),        // #21  (0x054) Wakeup PIO0_5 handler
	(isr_handler)(wakeup_irq_handler),        // #22  (0x058) Wakeup PIO0_6 handler
	(isr_handler)(wakeup_irq_handler),        // #23  (0x05C) Wakeup PIO0_7 handler
	(isr_handler)(wakeup_irq_handler),        // #24  (0x060) Wakeup PIO0_8 handler
	(isr_handler)(wakeup_irq_handler),        // #25  (0x064) Wakeup PIO0_9 handler
	(isr_handler)(wakeup_irq_handler),        // #26  (0x068) Wakeup PIO0_10 handler
	(isr_handler)(wakeup_irq_handler),        // #27  (0x06C) Wakeup PIO0_11 handler
	(isr_handler)(wakeup_irq_handler),        // #28  (0x070) Wakeup PIO1_0 handler
	(isr_handler)(wakeup_irq_handler),        // #29  (0x074) Wakeup PIO1_1 handler
	(isr_handler)(wakeup_irq_handler),        // #30  (0x078) Wakeup PIO1_2 handler
	(isr_handler)(wakeup_irq_handler),        // #31  (0x07C) Wakeup PIO1_3 handler
	(isr_handler)(wakeup_irq_handler),        // #32  (0x080) Wakeup PIO1_4 handler
	(isr_handler)(wakeup_irq_handler),        // #33  (0x084) Wakeup PIO1_5 handler
	(isr_handler)(wakeup_irq_handler),        // #34  (0x088) Wakeup PIO1_6 handler
	(isr_handler)(wakeup_irq_handler),        // #35  (0x08C) Wakeup PIO1_7 handler
	(isr_handler)(wakeup_irq_handler),        // #36  (0x090) Wakeup PIO1_8 handler
	(isr_handler)(wakeup_irq_handler),        // #37  (0x094) Wakeup PIO1_9 handler
	(isr_handler)(wakeup_irq_handler),        // #38  (0x098) Wakeup PIO1_10 handler
	(isr_handler)(wakeup_irq_handler),        // #39  (0x09C) Wakeup PIO1_11 handler
	(isr_handler)(wakeup_irq_handler),        // #40  (0x0A0) Wakeup PIO2_0 handler
	(isr_handler)(wakeup_irq_handler),        // #41  (0x0A4) Wakeup PIO2_1 handler
	(isr_handler)(wakeup_irq_handler),        // #42  (0x0A8) Wakeup PIO2_2 handler
	(isr_handler)(wakeup_irq_handler),        // #43  (0x0AC) Wakeup PIO2_3 handler
	(isr_handler)(wakeup_irq_handler),        // #44  (0x0B0) Wakeup PIO2_4 handler
	(isr_handler)(wakeup_irq_handler),        // #45  (0x0B4) Wakeup PIO2_5 handler
	(isr_handler)(wakeup_irq_handler),        // #46  (0x0B8) Wakeup PIO2_6 handler
	(isr_handler)(wakeup_irq_handler),        // #47  (0x0BC) Wakeup PIO2_7 handler
	(isr_handler)(wakeup_irq_handler),        // #48  (0x0C0) Wakeup PIO2_8 handler
	(isr_handler)(wakeup_irq_handler),        // #49  (0x0C4) Wakeup PIO2_9 handler
	(isr_handler)(wakeup_irq_handler),        // #50  (0x0C8) Wakeup PIO2_10 handler
	(isr_handler)(wakeup_irq_handler),        // #51  (0x0CC) Wakeup PIO2_11 handler
	(isr_handler)(wakeup_irq_handler),        // #52  (0x0D0) Wakeup PIO3_0 handler
	(isr_handler)(wakeup_irq_handler),        // #53  (0x0D4) Wakeup PIO3_1 handler
	(isr_handler)(wakeup_irq_handler),        // #54  (0x0D8) Wakeup PIO3_2 handler
	(isr_handler)(wakeup_irq_handler),        // #55  (0x0DC) Wakeup PIO3_3 handler
	(isr_handler)(i2c_irq_handler),           // #56  (0x0E0) I2C handler
	(isr_handler)(timer16_0_irq_handler),     // #57  (0x0E4) CT16B0 (16-bit Timer 0) handler
	(isr_handler)(timer16_1_irq_handler),     // #58  (0x0E8) CT16B1 (16-bit Timer 1) handler
	(isr_handler)(timer32_0_irq_handler),     // #59  (0x0EC) CT32B0 (32-bit Timer 0) handler
	(isr_handler)(timer32_1_irq_handler),     // #60  (0x0F0) CT32B1 (32-bit Timer 1) handler
	(isr_handler)(ssp_irq_handler),           // #61  (0x0F4) SSP handler
	(isr_handler)(uart_irq_handler),          // #62  (0x0F8) UART handler
	(isr_handler)(usb_irq_handler),           // #63  (0x0FC) USB IRQ handler
	(isr_handler)(usb_fiq_handler),           // #64  (0x100) USB FIQ handler
	(isr_handler)(adc_irq_handler),           // #65  (0x104) ADC (A/D Converter) handler
	(isr_handler)(wdt_irq_handler),           // #66  (0x108) WDT (Watchdog Timer) handler
	(isr_handler)(bod_irq_handler),           // #67  (0x10C) BOD (Brownout detect) handler
	(isr_handler)(fmc_irq_handler),           // #68  (0x110) FMC (IP2111 Flash Memory Controller) handler
	(isr_handler)(pio_int3_irq_handler),      // #69  (0x114) PIO INT3 handler
	(isr_handler)(pio_int2_irq_handler),      // #70  (0x118) PIO INT2 handler
	(isr_handler)(pio_int1_irq_handler),      // #71  (0x11C) PIO INT1 handler
	(isr_handler)(pio_int0_irq_handler),      // #72  (0x120) PIO INT0 handler


	(isr_handler)(0x00000000),                // #73  (0x124) Reserved
	(isr_handler)(0x00000000),                // #74  (0x128) Reserved
	(isr_handler)(0x00000000),                // #75  (0x12C) Reserved
	(isr_handler)(0x00000000),                // #76  (0x130) Reserved
	(isr_handler)(0x00000000),                // #77  (0x134) Reserved
	(isr_handler)(0x00000000),                // #78  (0x138) Reserved
	(isr_handler)(0x00000000),                // #79  (0x13C) Reserved
	(isr_handler)(0x00000000),                // #80  (0x140) Reserved
	(isr_handler)(0x00000000),                // #81  (0x144) Reserved
	(isr_handler)(0x00000000),                // #82  (0x148) Reserved
	(isr_handler)(0x00000000),                // #83  (0x14C) Reserved
	(isr_handler)(0x00000000),                // #84  (0x150) Reserved
	(isr_handler)(0x00000000),                // #85  (0x154) Reserved
	(isr_handler)(0x00000000),                // #86  (0x158) Reserved
	(isr_handler)(0x00000000),                // #87  (0x15C) Reserved
	(isr_handler)(0x00000000),                // #88  (0x160) Reserved
	(isr_handler)(0x00000000),                // #89  (0x164) Reserved
	(isr_handler)(0x00000000),                // #90  (0x168) Reserved
	(isr_handler)(0x00000000),                // #91  (0x16C) Reserved
	(isr_handler)(0x00000000),                // #92  (0x170) Reserved
	(isr_handler)(0x00000000),                // #93  (0x174) Reserved
	(isr_handler)(0x00000000),                // #94  (0x178) Reserved
	(isr_handler)(0x00000000),                // #95  (0x17C) Reserved
	(isr_handler)(0x00000000),                // #96  (0x180) Reserved
	(isr_handler)(0x00000000),                // #97  (0x184) Reserved
	(isr_handler)(0x00000000),                // #98  (0x188) Reserved
	(isr_handler)(0x00000000),                // #99  (0x18C) Reserved
	(isr_handler)(0x00000000),                // #100 (0x190) Reserved
	(isr_handler)(0x00000000),                // #101 (0x194) Reserved
	(isr_handler)(0x00000000),                // #102 (0x198) Reserved
	(isr_handler)(0x00000000),                // #103 (0x19C) Reserved
	(isr_handler)(0x00000000),                // #104 (0x1A0) Reserved
	(isr_handler)(0x00000000),                // #105 (0x1A4) Reserved
	(isr_handler)(0x00000000),                // #106 (0x1A8) Reserved
	(isr_handler)(0x00000000),                // #107 (0x1AC) Reserved
	(isr_handler)(0x00000000),                // #108 (0x1B0) Reserved
	(isr_handler)(0x00000000),                // #109 (0x1B4) Reserved
	(isr_handler)(0x00000000),                // #110 (0x1B8) Reserved
	(isr_handler)(0x00000000),                // #111 (0x1BC) Reserved
	(isr_handler)(0x00000000),                // #112 (0x1C0) Reserved
	(isr_handler)(0x00000000),                // #113 (0x1C4) Reserved
	(isr_handler)(0x00000000),                // #114 (0x1C8) Reserved
	(isr_handler)(0x00000000),                // #115 (0x1CC) Reserved
	(isr_handler)(0x00000000),                // #116 (0x1D0) Reserved
	(isr_handler)(0x00000000),                // #117 (0x1D4) Reserved
	(isr_handler)(0x00000000),                // #118 (0x1D8) Reserved
	(isr_handler)(0x00000000),                // #119 (0x1DC) Reserved
	(isr_handler)(0x00000000),                // #120 (0x1E0) Reserved
	(isr_handler)(0x00000000),                // #121 (0x1E4) Reserved
	(isr_handler)(0x00000000),                // #122 (0x1E8) Reserved
	(isr_handler)(0x00000000),                // #123 (0x1EC) Reserved
	(isr_handler)(0x00000000),                // #124 (0x1F0) Reserved
	(isr_handler)(0x00000000),                // #125 (0x1F4) Reserved
	(isr_handler)(0x00000000),                // #126 (0x1F8) Reserved
	(isr_handler)(0x00000000),                // #127 (0x1FC) Reserved
	(isr_handler)(0x00000000),                // #128 (0x200) Reserved
	(isr_handler)(0x00000000),                // #129 (0x204) Reserved
	(isr_handler)(0x00000000),                // #130 (0x208) Reserved
	(isr_handler)(0x00000000),                // #131 (0x20C) Reserved
	(isr_handler)(0x00000000),                // #132 (0x210) Reserved
	(isr_handler)(0x00000000),                // #133 (0x214) Reserved
	(isr_handler)(0x00000000),                // #134 (0x218) Reserved
	(isr_handler)(0x00000000),                // #135 (0x21C) Reserved
	(isr_handler)(0x00000000),                // #136 (0x220) Reserved
	(isr_handler)(0x00000000),                // #137 (0x224) Reserved
	(isr_handler)(0x00000000),                // #138 (0x228) Reserved
	(isr_handler)(0x00000000),                // #139 (0x22C) Reserved
	(isr_handler)(0x00000000),                // #140 (0x230) Reserved
	(isr_handler)(0x00000000),                // #141 (0x234) Reserved
	(isr_handler)(0x00000000),                // #142 (0x238) Reserved
	(isr_handler)(0x00000000),                // #143 (0x23C) Reserved
	(isr_handler)(0x00000000),                // #144 (0x240) Reserved
	(isr_handler)(0x00000000),                // #145 (0x244) Reserved
	(isr_handler)(0x00000000),                // #146 (0x248) Reserved
	(isr_handler)(0x00000000),                // #147 (0x24C) Reserved
	(isr_handler)(0x00000000),                // #148 (0x250) Reserved
	(isr_handler)(0x00000000),                // #149 (0x254) Reserved
	(isr_handler)(0x00000000),                // #150 (0x258) Reserved
	(isr_handler)(0x00000000),                // #151 (0x25C) Reserved
	(isr_handler)(0x00000000),                // #152 (0x260) Reserved
	(isr_handler)(0x00000000),                // #153 (0x264) Reserved
	(isr_handler)(0x00000000),                // #154 (0x268) Reserved
	(isr_handler)(0x00000000),                // #155 (0x26C) Reserved
	(isr_handler)(0x00000000),                // #156 (0x270) Reserved
	(isr_handler)(0x00000000),                // #157 (0x274) Reserved
	(isr_handler)(0x00000000),                // #158 (0x278) Reserved
	(isr_handler)(0x00000000),                // #159 (0x27C) Reserved
	(isr_handler)(0x00000000),                // #160 (0x280) Reserved
	(isr_handler)(0x00000000),                // #161 (0x284) Reserved
	(isr_handler)(0x00000000),                // #162 (0x288) Reserved
	(isr_handler)(0x00000000),                // #163 (0x28C) Reserved
	(isr_handler)(0x00000000),                // #164 (0x290) Reserved
	(isr_handler)(0x00000000),                // #165 (0x294) Reserved
	(isr_handler)(0x00000000),                // #166 (0x298) Reserved
	(isr_handler)(0x00000000),                // #167 (0x29C) Reserved
	(isr_handler)(0x00000000),                // #168 (0x2A0) Reserved
	(isr_handler)(0x00000000),                // #169 (0x2A4) Reserved
	(isr_handler)(0x00000000),                // #170 (0x2A8) Reserved
	(isr_handler)(0x00000000),                // #171 (0x2AC) Reserved
	(isr_handler)(0x00000000),                // #172 (0x2B0) Reserved
	(isr_handler)(0x00000000),                // #173 (0x2B4) Reserved
	(isr_handler)(0x00000000),                // #174 (0x2B8) Reserved
	(isr_handler)(0x00000000),                // #175 (0x2BC) Reserved
	(isr_handler)(0x00000000),                // #176 (0x2C0) Reserved
	(isr_handler)(0x00000000),                // #177 (0x2C4) Reserved
	(isr_handler)(0x00000000),                // #178 (0x2C8) Reserved
	(isr_handler)(0x00000000),                // #179 (0x2CC) Reserved
	(isr_handler)(0x00000000),                // #180 (0x2D0) Reserved
	(isr_handler)(0x00000000),                // #181 (0x2D4) Reserved
	(isr_handler)(0x00000000),                // #182 (0x2D8) Reserved
	(isr_handler)(0x00000000),                // #183 (0x2DC) Reserved
	(isr_handler)(0x00000000),                // #184 (0x2E0) Reserved
	(isr_handler)(0x00000000),                // #185 (0x2E4) Reserved
	(isr_handler)(0x00000000),                // #186 (0x2E8) Reserved
	(isr_handler)(0x00000000),                // #187 (0x2EC) Reserved
	(isr_handler)(0x00000000),                // #188 (0x2F0) Reserved
	(isr_handler)(0x00000000),                // #189 (0x2F4) Reserved
	(isr_handler)(0x00000000),                // #190 (0x2F8) Reserved

	(isr_handler)(CRP_WORD),                  // #191 (0x2FC) Code Read Protection Word

	(isr_handler)(0x00000000),                // #192 (0x300) Reserved
	(isr_handler)(0x00000000),                // #193 (0x304) Reserved
	(isr_handler)(0x00000000),                // #194 (0x308) Reserved
	(isr_handler)(0x00000000),                // #195 (0x30C) Reserved
	(isr_handler)(0x00000000),                // #196 (0x310) Reserved
	(isr_handler)(0x00000000),                // #197 (0x314) Reserved
	(isr_handler)(0x00000000),                // #198 (0x318) Reserved
	(isr_handler)(0x00000000),                // #199 (0x31C) Reserved
	(isr_handler)(0x00000000),                // #200 (0x320) Reserved
	(isr_handler)(0x00000000),                // #201 (0x324) Reserved
	(isr_handler)(0x00000000),                // #202 (0x328) Reserved
	(isr_handler)(0x00000000),                // #203 (0x32C) Reserved
	(isr_handler)(0x00000000),                // #204 (0x330) Reserved
	(isr_handler)(0x00000000),                // #205 (0x334) Reserved
	(isr_handler)(0x00000000),                // #206 (0x338) Reserved
	(isr_handler)(0x00000000),                // #207 (0x33C) Reserved
	(isr_handler)(0x00000000),                // #208 (0x340) Reserved
	(isr_handler)(0x00000000),                // #209 (0x344) Reserved
	(isr_handler)(0x00000000),                // #210 (0x348) Reserved
	(isr_handler)(0x00000000),                // #211 (0x34C) Reserved
	(isr_handler)(0x00000000),                // #212 (0x350) Reserved
	(isr_handler)(0x00000000),                // #213 (0x354) Reserved
	(isr_handler)(0x00000000),                // #214 (0x358) Reserved
	(isr_handler)(0x00000000),                // #215 (0x35C) Reserved
	(isr_handler)(0x00000000),                // #216 (0x360) Reserved
	(isr_handler)(0x00000000),                // #217 (0x364) Reserved
	(isr_handler)(0x00000000),                // #218 (0x368) Reserved
	(isr_handler)(0x00000000),                // #219 (0x36C) Reserved
	(isr_handler)(0x00000000),                // #220 (0x370) Reserved
	(isr_handler)(0x00000000),                // #221 (0x374) Reserved
	(isr_handler)(0x00000000),                // #222 (0x378) Reserved
	(isr_handler)(0x00000000),                // #223 (0x37C) Reserved
	(isr_handler)(0x00000000),                // #224 (0x380) Reserved
	(isr_handler)(0x00000000),                // #225 (0x384) Reserved
	(isr_handler)(0x00000000),                // #226 (0x388) Reserved
	(isr_handler)(0x00000000),                // #227 (0x38C) Reserved
	(isr_handler)(0x00000000),                // #228 (0x390) Reserved
	(isr_handler)(0x00000000),                // #229 (0x394) Reserved
	(isr_handler)(0x00000000),                // #230 (0x398) Reserved
	(isr_handler)(0x00000000),                // #231 (0x39C) Reserved
	(isr_handler)(0x00000000),                // #232 (0x3A0) Reserved
	(isr_handler)(0x00000000),                // #233 (0x3A4) Reserved
	(isr_handler)(0x00000000),                // #234 (0x3A8) Reserved
	(isr_handler)(0x00000000),                // #235 (0x3AC) Reserved
	(isr_handler)(0x00000000),                // #236 (0x3B0) Reserved
	(isr_handler)(0x00000000),                // #237 (0x3B4) Reserved
	(isr_handler)(0x00000000),                // #238 (0x3B8) Reserved
	(isr_handler)(0x00000000),                // #239 (0x3BC) Reserved
	(isr_handler)(0x00000000),                // #240 (0x3C0) Reserved
	(isr_handler)(0x00000000),                // #241 (0x3C4) Reserved
	(isr_handler)(0x00000000),                // #242 (0x3C8) Reserved
	(isr_handler)(0x00000000),                // #243 (0x3CC) Reserved
	(isr_handler)(0x00000000),                // #244 (0x3D0) Reserved
	(isr_handler)(0x00000000),                // #245 (0x3D4) Reserved
	(isr_handler)(0x00000000),                // #246 (0x3D8) Reserved
	(isr_handler)(0x00000000),                // #247 (0x3DC) Reserved
	(isr_handler)(0x00000000),                // #248 (0x3E0) Reserved
	(isr_handler)(0x00000000),                // #249 (0x3E4) Reserved
	(isr_handler)(0x00000000),                // #250 (0x3E8) Reserved
	(isr_handler)(0x00000000),                // #251 (0x3EC) Reserved
	(isr_handler)(0x00000000),                // #252 (0x3F0) Reserved
	(isr_handler)(0x00000000),                // #253 (0x3F4) Reserved
	(isr_handler)(0x00000000),                // #254 (0x3F8) Reserved
	(isr_handler)(0x00000000)                 // #255 (0x3FC) Reserved
};

