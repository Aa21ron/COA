#include <stdio.h>
#include <conio.h>
#include <math.h>

int dectobinary(int num, int array[]){
    int i = 0;

    // Handle the special case for 0 explicitly
    if (num == 0) {
        printf("0");
        return 1;
    }

    while (num > 0) {
        array[i] = num % 2;
        num = num / 2;
        i++;
    }   
    return i;
}

//convert array to integer
int arrtoint(int n,int array[])
{
	int i,num=0;
	for(i=n-1; i>=0; i--)
	{
		num=num*10+array[i];
	}
	
	printf("%d \n",num);
	return num;

}


// Function to perform binary addition
int binaryAddition(int a, int b) {
    int carry = 0, result = 0, bit = 1;
    while (a != 0 || b != 0) {
        int bit_a = a % 10;
        int bit_b = b % 10;

        // Add the bits along with the carry
        int sum = bit_a + bit_b + carry;

        // Update the result
        result += (sum % 2) * bit;

        // Calculate the carry for the next bit
        carry = sum / 2;

        // Move to the next bit
        a /= 10;
        b /= 10;
        bit *= 10;
    }

    // Add the carry if exists
    result += carry * bit;
    return result;
}

// Function to perform logical shift left
int logicalShiftLeft(int num) {
    return num * 10; // Equivalent to shifting left by 1 position
}

// Function to perform logical shift right
int logicalShiftRight(int num) {
    return num / 10; // Equivalent to shifting right by 1 position
}

// Function to perform Booth's multiplication algorithm
int boothMultiply(int multiplicand, int multiplier) {
    int accumulator = 0;
    int bitMask = 1;

    // Iterate over each bit of the multiplier
    while (multiplier != 0) {
        // Step 2: Test Y0; if it is 1, add content of X to the accumulator A
        if (multiplier % 10 == 1) {
            accumulator = binaryAddition(accumulator, multiplicand);
        }

        // Step 3: Logical Shift the content of X left one position and content of Y right one position
        multiplicand = logicalShiftLeft(multiplicand);
        multiplier = logicalShiftRight(multiplier);

        // Move the bit mask to the next bit
        bitMask *= 10;
    }

    return accumulator;
}

// Function to convert binary number to decimal
int binaryToDecimal(int binary) {
    int decimal = 0, base = 1;
    while (binary != 0) {
        int lastDigit = binary % 10;
        decimal += lastDigit * base;
        binary /= 10;
        base *= 2;
    }
    return decimal;
}


int main() {
    int num1,num2,multiplicand, multiplier,array1[10],array2[10],nbit1,nbit2;
    
    printf("Bhuwan Basnet - 078BEI016 \n");
    printf("Enter the multiplicand: ");
    scanf("%d", &num1);
    printf("Enter the multiplier: ");
    scanf("%d", &num2);
    
    //decimal to binary conversion
    nbit1 = dectobinary(abs(num1),array1);
    nbit2 = dectobinary(abs(num2),array2);
    
    printf("\nfor bits \n");
    printf("bits of multiplicand=%d \n bits of multiplier=%d",nbit1,nbit2);
    
    //array to integer
    printf("\nBinary equivalent of number: \n");
    multiplicand = arrtoint(nbit1,array1);
    multiplier = arrtoint(nbit2,array2);
    
    	
    // Step 1: Clear the accumulator (sum)
    int product = boothMultiply(multiplicand, multiplier);

    printf("\nProduct of the two binary numbers: %d (binary)\n", product);
    printf("Product in decimal: %d\n", binaryToDecimal(product));

    getch();
    return 0;
}