#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "numbers.txt";

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    int sum = 0;
    
    while (!feof(fp)) {
        int num;
        
        if (fscanf(fp, "%d", &num) == 1) {
            sum += num;
        } 
        else {
            char invalid_input[64];
            
            if (fscanf(fp, "%s", invalid_input) == 1) {
                fprintf(stderr, "invalid input %s\n", invalid_input);
            } else {
                break; 
            }
        }
    }


    printf("sum: %d\n", sum);
    fclose(fp);
    return 0;
}
