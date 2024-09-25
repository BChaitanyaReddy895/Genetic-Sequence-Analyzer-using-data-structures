#include <stdio.h>
#include <stdlib.h>
// Function to count nucleotides in a genetic sequence
void countNucleotides(char *sequence, int *counts) 
{
	int i;
 	for (i = 0; sequence[i] != '\0'; i++) 
	{
 		switch (sequence[i]) 
		{
 			case 'A':
 				counts[0]++;
 				break;
 			case 'C':
 				counts[1]++;
 				break;
 			case 'G':
 				counts[2]++;
 				break;
 			case 'T':
 				counts[3]++;
 				break;
 		}
 	}
}
// Function to calculate GC content of a genetic sequence
double calculateGCContent(char *sequence) 
{
	int totalNucleotides = 0;
	int gcCount = 0;
	int i;
	for (i = 0; sequence[i] != '\0'; i++) 
	{
		if (sequence[i] == 'G' || sequence[i] == 'C') 
		{
 			gcCount++;
 		}
 		totalNucleotides++;
 	}
	return ((double)gcCount / totalNucleotides) * 100.0;
}
// Main function
int main() 
{
	int numSequences;
	printf("Genetic Sequence Analyzer\n\n");
	printf("Enter the number of genetic sequences: ");
	scanf("%d", &numSequences);
	char **sequences = (char **)malloc(numSequences * sizeof(char *));
	int **nucleotideCounts = (int **)malloc(numSequences * sizeof(int *));
	double *gcContent = (double *)malloc(numSequences * sizeof(double));
	int i;
	for (i = 0; i < numSequences; i++) 
	{
		sequences[i] = (char *)malloc(100 * sizeof(char)); // Assuming max sequence length of 100 characters
		nucleotideCounts[i] = (int *)calloc(4, sizeof(int)); // Initialize counts to zero
		gcContent[i] = 0.0;
		printf("Enter genetic sequence %d: ", i + 1);
		scanf("%s", sequences[i]);
		countNucleotides(sequences[i], nucleotideCounts[i]);
		gcContent[i] = calculateGCContent(sequences[i]);
 	}
	printf("\nAnalysis Results:\n");
	for (i = 0; i < numSequences; i++) 
	{
		printf("Sequence %d:\n", i + 1);
		printf("A: %d\n", nucleotideCounts[i][0]);
		printf("C: %d\n", nucleotideCounts[i][1]);
		printf("G: %d\n", nucleotideCounts[i][2]);
		printf("T: %d\n", nucleotideCounts[i][3]);
		printf("GC Content: %.2f%%\n", gcContent[i]);
		printf("\n");
 	}
 // Free allocated memory
 	for (i = 0; i < numSequences; i++) 
	{
 		free(sequences[i]);
 		free(nucleotideCounts[i]);
 	}
 	free(sequences);
 	free(nucleotideCounts);
 	free(gcContent);
 	return 0;
} 

