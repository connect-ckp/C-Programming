#include <stdio.h>
#include <stddef.h> //Using NULL

int main(void) {
		int num = 125;	
	
	/*	// Always initialize a pointer while declaring it. 
		// If it points to nothing at first, then initialize to NULL.
		// DO NOT DEREFERENCE AN UNINITIALIZED POINTER.
		
		int *pNum;
		*pNum = 5; //THIS IS A TERRIBLE ERROR - In this case, the program's behavior will be undefined.
		
		int * pNum = NULL; // Equivalent to 0. So, can also be written as below.
		int *pNum = 0;
		
		// It's always recommended to check for NULL before you dereference a pointer.
	*/
	
	//int *pNum = &num; //Declaration and Initialization
		int * pNum = NULL; //Space between * and pointer variable name is optional.	
		pNum = &num;
		printf("Pointer Value: pnum = %p\n", pNum);
		printf("Pointer Stores: *pnum = %d\n", *pNum);
		printf("Number's Address: &num = %p\n", &num);
		printf("Pointer's Address: &pNum = %p\n", &pNum); //Possibility of compiler specific warning. 
		printf("Pointer's Address: (void*)&pNum = %p\n", (void*)&pNum); //Recommended
	//The cast to (void*) is to prevent a possible compiler warning, since %p expects the value to be of pionter type, 
	//but &pNum is "pointer to pointer to int".
	
		printf("Pointer's size: (int)sizeof(pNum) = %d Bytes\n", (int)sizeof(pNum));	
		
		printf("Value of num is %d.\nEnter the new value of num: ", num);
	//Receiving user input through pointer.
		scanf("%d", pNum);
		printf("\nValue of num is %d.\n", num);
	
	//POINTER_TO_A_CONSTANT - DISABLES *ptr = NEW_VALUE
		long lNum = 9999L, lNum2 = 1110L;
		const long *plNum = &lNum; 
		//Defines a POINTER_TO_A_CONSTANT, which DISABLES ASSIGNMENT THROUGH POINTER DEREFERENCE i.e. this will restrict to 
		//change the value of lNum through pointer dereference. However, the pointer's own value and the variable itself may change.
		
		*plNum = 8888L; //ERROR - Attempt to change const location through dereference.
		lNum = 8888L; //NOT ERROR - We can still change the actual value of the variable that it points to.

		plNum = &lNum2; //NOT ERROR
		*plNum = 5555L; //ERROR
	
	//CONSTANT_POINTER	- DISABLES ptr = &NEW_VAR
		int num2 = 45;
		int *const pNum2 = &num2; // Defines a CONSTANT_POINTER
		//This ensures that the pointer always points to the same address.
		pNum2 = &num; //ERROR - Attempt to change a constant pointer.
		*pNum2 = num; //NOT ERROR - Value in the address can be changed.
		
		// const int *pVar = &var; --Value of var can't be changed through dereference of pVar
		// int *const pVar = &var; --Value of pVar can't be changed i.e. it will always point to same memory location.
	
	//CONSTANT_POINTER_TO_A_CONSTANT - DISABLES both *ptr = NEW_VALUE and ptr = &NEW_VAR
		int num3 = 30;
		const int *const pNum3 = &num3;
		
		*pNum3 = num2; //ERROR
		pNum3 = &num; //ERROR
		
	//VOID POINTERS
		//A pointer of type void* can point to variable of any datatype. The void pointer does not know what type of object
		//it is pointing to, hence it can't be dereferenced without casting.
		int iNum = 50;
		float fVar = 2.34;
		char chVar = 'C';
		void *vPtr;
		
		vPtr = &num2;
		printf("Value of iNum = %d\n", *(int *)vPtr);
		
		vPtr = &fVar;
		printf("Value of fVar = %.2f\n", *(float *)vPtr);
		
		vPtr = &chVar;
		printf("Value of chVar = %c\n", *(char *)vPtr);
		
	//Arrays & Pointers
		int arrValues[100];
		int *pValues = NULL;
		
		pValues = arrValues; //The & operator is not used. The C Compiler treats the appearance of an array name without  a
							 //subscript as a pointer to the array, pointing to the first element of the array. Hence this is
							 //same as below.		
		pValues = &arrValues[0];
		
		//The two expressions arr_ptr[i] and *[arr_ptr + i] are equivalent and refer to the value at ith index of the array.
		//Both work if arr_ptr is the name of an array and both work even if arr_ptr is a pointer variable.
		//But, expression arr_ptr++ is valid for pointer only, bot array.
		
		printf("3rd element of arrValues is: %d\n", *(pValues + 2) );
		//Assigning Values to ith index of the array
		*(pValues + i) = 60;
		
		//If pValues points to arrValues[0], it can be set to point to arrValues[1] as below.
		pValues += 1; // equivalent to: pValues = &arrValues[1];
		
		//e.g. Array as Function Argument
		int arraySum (int array[], const int n) 
		{ 
			int sum = o, *ptr; 
			int * const arrayEnd = array + n; 
			for ( ptr = array; ptr < arrayEnd; ++ptr ) 
				sum += *ptr; 
			return sum; 
		} 
		int main (void) 
		{ 
			int arraySum (int array[], const int n); 
			int values[m] = { 3, 7, -9, 3, 6, -1, 7, 9, 1, -5 }; 
			printf ("The sum is %i\n", arraySum (values, 10)); 
			return 0;
		} 
		
		//Pointer as Function Argument - GENERALLY MORE EFFICIENT
		int arraySum (int *array, const int n)
		{ 
			int sum = o;
			int * const arrayEnd = array + n; 
			
			for ( ; array < arrayEnd; ++array )
				sum += *array; 
			
			return sum; 
		} 
		int main (void)
		{ 
			int arraySum (int *array, const int n);
			int values[m] = { 3, 7, -9, 3, 6, -1, 7, 9, 1, -5 }; 
			printf ("The sum is %i\n", arraySum (values, 10)); 
			return 0;
		} 

		
		/* Some Valid/ Invalid Usages
		int urn[3]; 
		int *ptr1, *ptr2; 
		
		ptr1++; 			//VALID
		ptr2 = ptr1 + 2;	//VALID
		ptr2 = urn + 1;		//VALID
		
		urn++;				//INVALID
		ptr2 = ptr2 + ptr1;	//INVALID		
		ptr2 = urn * ptr1; 	//INVALID
			
		*/
		/*===================================================================*/
		//EXAMPLE - This program demonstrates the effect of adding an integer value to a pointer. 
		#include <stdio.h> 
		#include <string.h>
		
		int main(void)
		{ 
			char multiple[] = "a string";
			char *p = multiple; 
			
			for(int i = 0 ; i < strlen(multiple) ; ++i)
				printf("multiple[%d] = %c *(p+%d) = %c &multiple[%d] = %p p+%d = %p\n", i, multiple[i], i, *(p+i), i, &multiple[i], i, p+i);
			return 0;
		}
		/* 	OUTPUT: The Array indexes are separated by 1
			multiple[0] = a *(p+0) = a &multiple[0] = 0x7ffeccbee95f p+0 = 0x7ffeccbee95f
			multiple[1] =   *(p+1) =   &multiple[1] = 0x7ffeccbee960 p+1 = 0x7ffeccbee960
			multiple[2] = s *(p+2) = s &multiple[2] = 0x7ffeccbee961 p+2 = 0x7ffeccbee961
			multiple[3] = t *(p+3) = t &multiple[3] = 0x7ffeccbee962 p+3 = 0x7ffeccbee962
			multiple[4] = r *(p+4) = r &multiple[4] = 0x7ffeccbee963 p+4 = 0x7ffeccbee963
			multiple[5] = i *(p+5) = i &multiple[5] = 0x7ffeccbee964 p+5 = 0x7ffeccbee964
			multiple[6] = n *(p+6) = n &multiple[6] = 0x7ffeccbee965 p+6 = 0x7ffeccbee965
			multiple[7] = g *(p+7) = g &multiple[7] = 0x7ffeccbee966 p+7 = 0x7ffeccbee966
		*/
		
		//EXAMPLE - Same with Long Type
		#include <stdio.h> 
		int main(void)
		{ 
			long multiple[] = {15L, 25L, 35L, 45L}; 
			long *p = multiple;
			
			for(int i = 0 ; i < sizeof(multiple)/sizeof(multiple[0]) ; ++i) 
				printf("address p+%d (&multiple[%d]): %llu *(p+%d) value: %d\n", i, i, (unsigned long long)(p+i), i, *(p+i)); 
			
			printf("\n Type long occupies: %d bytes\n", (int)sizeof(long));
			return 0;
		} 

		/* 	OUTPUT: The Array indexes are separated by 8, which is compiler specific. (32 Bit or 64 Bit)
			address p+0 (&multiple[0]): 140721944031664 *(p+0) value: 15
			address p+1 (&multiple[1]): 140721944031672 *(p+1) value: 25
			address p+2 (&multiple[2]): 140721944031680 *(p+2) value: 35
			address p+3 (&multiple[3]): 140721944031688 *(p+3) value: 45
			
			Type long occupies: 8 bytes
		*/
		/*===================================================================*/
		/*===================================================================*/
		//Example - Copy String to another
		//Array Parameter vs char * Pointer parameter
		//Array Parameter
		void copyString (char to[], char from[])
		{ 
			int i; 
			for ( i = 0; from[i] != '\0'; ++i )
				to[i] = from[i]; 
			
			to[i] = '\0'; 
		}
		
		//char * Pointer parameter
		
		void copyString (char *to, char *from)
		{ 
			for ( ; *from != '\0'; ++from, ++to )
				*to = *from; 
			
			*to = '\0'; 
		}
		
		//Further Optimized
		void copyString (char *to, char *from) 
		{ 
			while ( *from ) // The null character is equal to the value 0
				*to++ = *from++; 
				
			*to = '\0'; 
		}
		
		int main (void)
		{ 
			char string10 = "A string to be copied."; 
			char string2[50];
			
			copyString (string2, string1); 
			printf ("%s\n", string2); 
		}
		/*===================================================================*/
		//PASS BY REFERENCE
		/*===================================================================*/	


		/*===================================================================*/
		//CONST POINTER PARAMETERS 
		/*===================================================================*/
		/*
		• You can qualify a function parameter using the const keyword 
		• Indicates that the function will treat the argument that is passed for this parameter as a constant
		• Only useful when the parameter is a pointer 
		• You apply the const keyword to a parameter that is a pointer to specify that a function will not change 
		the value to which the argument points 
		
			bool SendMessage(const char* pmessage) { 
				// Code to send the message
				return true, 
			} 
		
		• The type of the parameter, pmessage, is a pointer to a const char. 
		• It is the char value that's const, not its address. 
		• You could specify the pointer itself as const too, but this makes little sense because the address is passed by value
		• You cannot change the original pointer in the calling function
		• The compiler knows that an argument that is a pointer to constant data will be safe
		• If you pass a pointer to constant data as the argument for a parameter then the parameter must be a use the above
		*/		
		/*===================================================================*/
		//RETURNING POINTERS FROM A FUNCTION
		/*===================================================================*/
		/*
		• Returning a pointer from a function is a particularly powerful capability
		• It provides a way for you to return not just a single value, but a whole set of values. e.g. Structures
		• You would have to declare a function returning a pointer 
		
			int * myFunction() 
			{
			......		
			}
	
		• Be careful though, there are specific hazards related to returning a pointer 
		• Use local variables to avoid interfering with the variable that the argument points to.
		*/		
		/*===================================================================*/






























		
		return 0;
}