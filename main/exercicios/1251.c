#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ascii;
    int count;
} CharFreq;

int compare(const void *a, const void *b) {
    const CharFreq *ca = (const CharFreq *)a;
    const CharFreq *cb = (const CharFreq *)b;

    if (ca->count != cb->count) {
        return ca->count - cb->count;
    } else {
        return cb->ascii - ca->ascii;
    }
}

int main() {
    char line[1002];
    int previous_had_output = 0;

    while (fgets(line, sizeof(line), stdin) != NULL) {
        int freq[128] = {0};
        int len = strlen(line);

        for (int i = 0; i < len; i++) {
            if (line[i] == '\n') continue;
            unsigned char c = line[i];
            freq[c]++;
        }
        CharFreq list[128];
        int count = 0;
        for (int c = 32; c < 128; c++) {
            if (freq[c] > 0) {
                list[count].ascii = c;
                list[count].count = freq[c];
                count++;
            }
        }
        qsort(list, count, sizeof(CharFreq), compare);
        if (count > 0) {
            if (previous_had_output) {
                printf("\n");
            }
            for (int i = 0; i < count; i++) {
                printf("%d %d\n", list[i].ascii, list[i].count);
            }
            previous_had_output = 1;
        } else {
            previous_had_output = 0;
        }
    }

    return 0;
}
