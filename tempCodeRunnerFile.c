#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char h[7];  // Buffer for hex conversion

void int_to_hex(int num, char hex[]);

int main() {
    FILE *objectprogram, *intermediate_file, *symbtab, *optab;
    objectprogram = fopen("objectprogram.txt", "w");
    optab = fopen("optab.txt", "r");
    symbtab = fopen("symbtab.txt", "r");
    intermediate_file = fopen("intermediatefile.txt", "r");

    if (!objectprogram || !intermediate_file || !optab || !symbtab) {
        printf("Error opening files\n");
        exit(1);
    }

    char str1[100], str2[100], str3[100], str4[100], start[100];
    char str[100] = "";
    int need = 0, size;

    // Construct H record
    strcat(str, "H^");
    fscanf(intermediate_file, "%s %s %s", str1, str2, str3);
    strcat(str, str1);  // Program name
    strcat(str, "^");

    strcpy(start, str3);

    // Pad start address to 6 characters
    if (strlen(start) < 6) {
        need = 6 - strlen(start);
        for (int i = 0; i < need; i++) {
            strcat(str, "0");
        }
        strcat(str, start);
    } else {
        strcat(str, start);
    }
    strcat(str, "^");

    // Assuming size is determined somehow (this example uses a static length)
    size = 20; // Adjust this based on the object code generated
    int_to_hex(size, h);

    // Pad program size to 6 characters
    if (strlen(h) < 6) {
        need = 6 - strlen(h);
        for (int i = 0; i < need; i++) {
            strcat(str, "0");
        }
        strcat(str, h);
    } else {
        strcat(str, h);
    }

    // Write the H record to the object program
    fprintf(objectprogram, "%s\n", str);
    
    strcpy(str, "");
    
    // Process instructions from intermediate file to create T records
    int address;
    fscanf(intermediate_file, "%x %s %s %s", &address, str2, str3, str4);

    while (strcmp(str2, "END") != 0) {
        strcpy(str, "T^");
        sprintf(h, "%06X", address);
        strcat(str, h);
        strcat(str, "^");

        // Initialize length of object code in bytes
        int length = 0;
        char temp[100] = ""; // To hold object code for this record

        // Process instructions until the end of the block
        while (strcmp(str2, "ND") != 0 && strcmp(str2, "END") != 0) {
            // Lookup opcode
            fseek(optab, 0, SEEK_SET); // Reset file pointer for optab
            char opcode[10], opcode_value[10];
            int opcode_found = 0;

            while (fscanf(optab, "%s %s", opcode, opcode_value) != EOF) {
                if (strcmp(str3, opcode) == 0) {
                    strcat(temp, opcode_value); // Append the opcode
                    length += 3; // Each opcode contributes 3 bytes
                    opcode_found = 1;
                    break;
                }
            }

            // Handle operands (look them up in symbtab)
            if (strcmp(str3, "BYTE") == 0 || strcmp(str3, "WORD") == 0) {
                fseek(symbtab, 0, SEEK_SET); // Reset file pointer for symbtab
                char sym[10];
                int symAddr;
                while (fscanf(symbtab, "%s %X", sym, &symAddr) != EOF) {
                    if (strcmp(str4, sym) == 0) {
                        sprintf(h, "%06X", symAddr); // Convert address to hex
                        strcat(temp, h);
                        length += (strcmp(str3, "BYTE") == 0) ? 1 : 3; // BYTE: 1 byte, WORD: 3 bytes
                        break;
                    }
                }
            }

            // Read next instruction
            fscanf(intermediate_file, "%x %s %s %s", &address, str2, str3, str4);
        }

        // Append the object code to the T record
        char hex_length[7];
        int_to_hex(length,hex_length);
         // Get length in hex
        strcat(str, hex_length);
        strcat(str, "^");
        strcat(str, temp); // Append all object codes

        // Write the T record to the object program
        fprintf(objectprogram, "%s\n", str);
        strcpy(str, "");
    }

    // Write the final E record
    strcpy(str, "E^");
    strcat(str, start);
    fprintf(objectprogram, "%s\n", str);

    // Close the files
    fclose(objectprogram);
    fclose(optab);
    fclose(symbtab);
    fclose(intermediate_file);

    printf("Pass 2 completed!\n");
    return 0;
}

void int_to_hex(int num, char hex[]) {
    for (int j = 0; j < 6; j++) {  // Ensure we have enough room for 6 hex digits
        hex[j] = '0';
    }
    hex[6] = '\0';
    int i = 5;
    while (num != 0) {
        int remainder = num % 16;
        if (remainder < 10) {
            hex[i] = remainder + 48;
        } else {
            hex[i] = (remainder - 10) + 65;
        }
        num /= 16;
        i--;
    }
}
