#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 20

int main()
{
	printf("Enter the DNA sequence : ");
	char dna[SIZE], dna1[SIZE];
	char encode[SIZE];
	int energy=0, energy1=0;
	fgets(dna, SIZE, stdin);      // Gets the DNA sequence of one strand of a DNA molecule.
	int i, j, no_GC1=0, no_GC2=0;
	
	//Encodes the given DNA sequence to binary format and also calculates the total bonding energy.
	for (i=0, j=0; i<strlen(dna)-1; i++, j++)
	{
		if (dna[i]=='A' || dna[i]=='T')
		{
			energy+=2;
			encode[j]='0';
		}
		else if (dna[i]=='G' || dna[i]=='C')
		{
			energy+=3;
			encode[j]='1';
			no_GC1++;
		}
		else
		{
			printf("Invalid DNA Sequence\n");
			exit(0);
		}
	}
	encode[j]='\0';
	printf("Binary Coded DNA Sequence : %s\n", encode);
	printf("Estimated Total Bonding Energy of the DNA moelcule : %dεKBT\n\n", energy);
	
	printf("Enter another DNA sequence to compare : ");
	fgets(dna1, SIZE, stdin);                  // Gets the DNA sequence of one strand of another DNA molecule.
	for (i=0; i<strlen(dna1)-1; i++)
	{
		if (dna1[i]=='A' || dna1[i]=='T')
		{
			energy1+=2;
		}
		else if (dna1[i]=='G' || dna1[i]=='C')
		{
			energy1+=3;
			no_GC2++;
		}
		else
		{
			printf("Invalid DNA Sequence\n");
			exit(0);
		}
	}
	printf("Estimated Total Bonding Energy of the second DNA moelcule : %dεKBT\n\n", energy1);
	
	//Prints the DNA molecule that will melt at higher temperature by comparing the no. of G-C base pairs in each DNA molecule.
	printf("DNA molecule to melt at higher temperature : ");
	if (no_GC1>no_GC2)
		printf("%s\n", dna);
	else if (no_GC1==no_GC2)
		printf("Both will melt at same temperature.\n");
	else
		printf("%s\n", dna1);	
	return 0;
}
