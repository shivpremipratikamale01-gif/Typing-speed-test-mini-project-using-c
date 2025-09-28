
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SENTENCE_LENGTH 256

const char *sentences[] = {
    "The quick brown fox jumps over the lazy dog.",
    "Typing speed is a useful skill in the digital age.",
    "Practice makes perfect when it comes to typing.",
    "C programming is powerful and efficient.",
    "Always test your code before deployment."
};

void calculateResults(const char *original, const char *typed, double timeTaken) {
    int errors = 0;
    int len = strlen(original);
    for (int i = 0; i < len; i++) {
        if (typed[i] != original[i]) {
            errors++;
        }
    }

    int wordCount = 0;
    for (int i = 0; i < len; i++) {
        if (original[i] == ' ') {
            wordCount++;
        }
    }
    wordCount++; 

    double wpm = (wordCount / timeTaken) * 60;

    printf("\n--- Results ---\n");
    printf("Time Taken: %.2f seconds\n", timeTaken);
    printf("Typing Speed: %.2f WPM\n", wpm);
    printf("Errors: %d\n", errors);
}

int main() {
    srand(time(NULL));
    int index = rand() % (sizeof(sentences) / sizeof(sentences[0]));
    const char *sentence = sentences[index];
    char typedSentence[MAX_SENTENCE_LENGTH];

    printf("Type the following sentence:\n\n%s\n\n", sentence);
    printf("Press Enter when you're ready...\n");
    getchar();
    clock_t start = clock();
    fgets(typedSentence, MAX_SENTENCE_LENGTH, stdin);
    clock_t end = clock();

    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    
    typedSentence[strcspn(typedSentence, "\n")] = '\0';

    calculateResults(sentence, typedSentence, timeTaken);

    return 0;
}