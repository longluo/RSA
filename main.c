/********************************************************************************************
*  Copyright(c) tcpipstack
*	File Name				:	RSA.c 
*	Abstract Description	:	RSA加解密算法的简单演示	
*	Create Date				:	2010/08/17
*	Author					:	tcpipstack
*-------------------------Revision History--------------------------------------------------
*	No	Version		Date		Revised By			Item			Description
*	 1		1.0		10/08/17
*
********************************************************************************************/

#include <stdio.h>
#include <math.h>

/* RSA算法中加密方公布的密钥是N和E，解密方使用N和D解密 */
#define P   (5)    /* P和Q必须为素数，在实际运用中通常为很大的数 */
#define Q   (7)

// public key n
#define N   (P*Q)   /* add the (), or will cause the mistake */

// phi(n)
#define PHI ((P - 1)*(Q - 1))

#define E   (5)        /* 加密方选择E，E必须和PHI只有一个公约数 */
#define D   (5)        /* (E * D - 1)必须能够被PHI整除 */

/* 由于long int无法表示过大的数字，所以D取5 */

// Returns gcd of a and b
int gcd(int a, int b) {
    return a == 0 ? b : gcd(b, a % b);
}

int main(void) {
    int i;
    int msg[4] = {12, 15, 22, 5};
    long en[4], de[4];
    int SecCode[4], DeMsg[4];

    printf("下面是一个RSA加解密算法的简单演示:\n");
    printf("\t Copyright(C) Long.Luo.\n\n");
    printf("报文\t加密\t   加密后密文\n");

    for (i = 0; i < 4; i++) {
        /* s = m(E) mod N */
        en[i] = (int) pow(msg[i], E);
        SecCode[i] = en[i] % N;

        printf("%d\t%d\t\t%d\n", msg[i], en[i], SecCode[i]);
    }

    printf("\n原始报文\t密文\t加密\t\t解密报文\n");
    for (i = 0; i < 4; i++) {
        /* d = s(D) mod N */
        de[i] = pow(SecCode[i], D);
        DeMsg[i] = de[i] % N;

        printf("%d\t\t%d\t%d\t\t%d\n", msg[i], SecCode[i], de[i], DeMsg[i]);
    }

    getchar();

    return 0;
}


