/*
 * File:   main.c
 * Author: fog76
 *
 * Created on 21 novembre 2017, 10.38
 */

// PIC18F25J11 Configuration Bit Settings

// 'C' source line config statements

#include <xc.h>

// CONFIG1L
#pragma config WDTEN = OFF      // Watchdog Timer (Disabled - Controlled by SWDTEN bit)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset (Enabled)
#pragma config XINST = OFF       // Extended Instruction Set (Enabled)

// CONFIG1H
#pragma config CP0 = OFF        // Code Protect (Program memory is not code-protected)

// CONFIG2L
#pragma config OSC = HS         // Oscillator (HS)
#pragma config T1DIG = ON       // T1OSCEN Enforcement (Secondary Oscillator clock source may be selected)
#pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator (High-power operation)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor (Enabled)
#pragma config IESO = ON        // Internal External Oscillator Switch Over Mode (Enabled)

// CONFIG2H
#pragma config WDTPS = 32768    // Watchdog Postscaler (1:32768)

// CONFIG3L
#pragma config DSWDTOSC = INTOSCREF// DSWDT Clock Select (DSWDT uses INTRC)
#pragma config RTCOSC = T1OSCREF// RTCC Clock Select (RTCC uses T1OSC/T1CKI)
#pragma config DSBOREN = ON     // Deep Sleep BOR (Enabled)
#pragma config DSWDTEN = ON     // Deep Sleep Watchdog Timer (Enabled)
#pragma config DSWDTPS = G2     // Deep Sleep Watchdog Postscaler (1:2,147,483,648 (25.7 days))

// CONFIG3H
#pragma config IOL1WAY = ON     // IOLOCK One-Way Set Enable bit (The IOLOCK bit (PPSCON<0>) can be set once)
#pragma config MSSP7B_EN = MSK7 // MSSP address masking (7 Bit address masking mode)

// CONFIG4L
#pragma config WPFP = PAGE_31   // Write/Erase Protect Page Start/End Location (Write Protect Program Flash Page 31)
#pragma config WPEND = PAGE_WPFP// Write/Erase Protect Region Select (valid when WPDIS = 0) (Page WPFP<5:0> through Configuration Words erase/write protected)
#pragma config WPCFG = OFF      // Write/Erase Protect Configuration Region (Configuration Words page not erase/write-protected)

// CONFIG4H
#pragma config WPDIS = OFF      // Write Protect Disable bit (WPFP<5:0>/WPEND region ignored)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#define _XTAL_FREQ              20000000

void main(void) {
    unsigned char status = 0;
    
    INTCON 	= 0x0;			// Disable interrupt
    
    //Port A as digital input
    ANCON0bits.PCFG0 = 1;
    ANCON0bits.PCFG1 = 1;
    ANCON0bits.PCFG2 = 1;
    ANCON0bits.PCFG3 = 1;
    ANCON0bits.PCFG4 = 1;
    
    ANCON1bits.VBGEN = 0;
    
    CM1CON = 0x07;
    
    TRISAbits.TRISA0 = 0;
    TRISAbits.TRISA1 = 0;
    TRISAbits.TRISA5 = 1;
    
    LATAbits.LATA0 = 1;
    LATAbits.LATA1 = 0;
    
    while (1)
    {
        if ((PORTAbits.RA5) == 0)
        {
            LATAbits.LATA0 ^= 1;
            LATAbits.LATA1 ^= 1;
            
            __delay_ms(500);
        }
    }
}