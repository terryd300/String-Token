//
//  hw1.c
//  
//
//  Created by Terry Delaney on 2/19/21.
//


#include <stdio.h>
#include <string.h>

int main ()
{

//    Variable Declaration
    
    char preamble[] = "We hold these truths to be self-evident, that all men are created equal, that they are endowed, by their Creator, with certain unalienable Rights, that among these are Life, Liberty, and the pursuit of Happiness. That to secure these rights, Governments are instituted among Men, deriving their just powers from the consent of the governed, That whenever any Form of Government becomes destructive of these ends, it is the Right of the People to alter or abolish it and to institute new Government, laying its foundation on such principles, and organizing its powers in such form, as to them shall seem most likely to effect their Safety and Happiness. Prudence, indeed, will dictate that governments long established should not be changed for list and transient causes; and accordingly all experience hath shews, that manking are more disposed to suffer, while evils are sufferable, than to right themselves by abolishing the forms to which they are accustomed. But when a long train of abuses and usurpations, pursuing invariably the same Object, evinces a design to reduce them under absolute despotism, it is their right, it is their duty, to throw off such Government, and to provide new guards for their future seurity.";
    char * sentence;    // Pointer for first strtok command to determine sentences
    char * sentence2;   // Pointer for second strtok command to determine sentences
    char * word;        // Pointer for strtok command to determine words
    int totalSentences = 0;     // Determine total number of sentences to help with array creation
    int sentenceCount = 0;      // Counter to assist with placing sentences into array
    int wordCount = 0;          // Count of number of words in a sentence
    float averageWords = 0;     // Average number of words per sentence
    int maxLength = 0;          // Determine longest sentenace to help with array creation
    int wordSum = 0;            // Totals number of words in each sentence
    char preamble2 [strlen(preamble)];  // Copy of preamble to use with second strtok command
    
//    Copy preamble text into preamble2
    
    strncpy (preamble2, preamble, strlen(preamble));

//    Detrmine number of sentences and length of longest sentence
    
    sentence = strtok (preamble, ".");
    
    while (sentence != NULL)
    {
        if (strlen (sentence) > maxLength)
            maxLength = strlen (sentence);
        totalSentences++;
        sentence = strtok (NULL, ".");
    }
    
//    Create arrays for the sentences to be saved and the word counts of each sentence
    
    char sentenceArray [totalSentences] [maxLength + 1];
    int words [totalSentences];
    
//    Split preamble2 into individual sentences and store them in sentenceArray
    
    sentence2 = strtok (preamble2, ".");
    
    while (sentenceCount < totalSentences)
    {
        strcpy (sentenceArray [sentenceCount], sentence2);
        sentenceCount++;
        sentence2 = strtok (NULL, ".");
    }
    
//    Iterate through sentenceArray and determine the number of words in each sentence
    
    for (int i = 0; i < totalSentences; i++)
    {
        printf("Sentence #%d:\n\n%s\n\n", i+1, sentenceArray[i]);
        wordCount = 0;
        word = strtok (sentenceArray [i], " .,;-");
        
        while (word != NULL)
        {
            wordCount++;
            word = strtok (NULL, " .,;-");
        }
        
        printf ("Sentence #%d has %d words\n\n", i + 1, wordCount);
        words [i] = wordCount;
        
    }
    
//    Calculate total number of words in each sentence
    
    for (int j = 0; j < totalSentences; j++)
    {
        wordSum += words [j];
    }
    
//    Calculate average number of words per sentence - Cast to floating point to allow for floating point division
    
    averageWords = (float) wordSum / (float) totalSentences;
    
//    Print Results
    
    printf("There are a total of %d sentences.\n", totalSentences);
    printf("There are a total of %d words.\n", wordSum);
    printf("There is an average of %.2f words per sentence.\n\n", averageWords);
    
    
    return 0;

}
