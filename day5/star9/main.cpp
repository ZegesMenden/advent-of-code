#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char strbuf[512] = {0};
char crates[9][256] = {0};

bool isnum(char c) {
    return ( (int)c > 47 && (int)c < 58 );
}

void reverse_array(char array[], int start, int end) {
    while ( start < end ) {
        char tmp = array[start];
        array[start] = array[end];
        array[end] = tmp;
        start++;
        end--;
    }
}

bool printed = false;

int main() {
    FILE * fptr = fopen("input.txt", "r");
    if ( fptr == NULL ) { return -1; }

    bool parsingcrates = true;
    int line = 0;
    while(!feof(fptr)) {
        fgets(strbuf, sizeof(strbuf), fptr);

        if ( strbuf[0] == ' ' && strbuf[1] == '1' && parsingcrates ) {  
            parsingcrates = false;
            continue;
        }

        if ( parsingcrates ) {
            int iterator = 0;
            for ( int i = 1; i < strlen(strbuf); i+= 4 ) {   
                if ( strbuf[i] != ' ' ) {   
                    crates[iterator][++crates[iterator][0]] = strbuf[i];
                }
                iterator++;
            }
        }
        

        if ( !parsingcrates && !printed ) { 

            printed = true;

            printf("initial letter positions\n");

            int maxposition = 0;
            for ( int row = 0; row < 9; row ++ ) { 
                maxposition = crates[row][0] > maxposition ? crates[row][0] : maxposition; 
                reverse_array(crates[row], 1, crates[row][0]);
            }

            for ( int i = maxposition; i > 0; i-- ) {
                for ( int row = 0; row < 9; row ++ ) {
                    if ( crates[row][i] == '\0' ) { printf("    "); }
                    else { printf("[%c] ", crates[row][i]); }
                }
                printf("\n");
            }          
            
        }

        if ( !parsingcrates && strbuf[0] == 'm' ) {
            int i = 5;
            int previous_num_idx = 5;
            int command_idx = 0;
            int commands[3] = {0};
            
            // printf("%s", strbuf);
            while ( strbuf[i] != '\0' ) {
                if ( strbuf[i] == ' ' || strbuf[i] == '\n') { 
                    if ( isnum(strbuf[i-1]) ) {
                        strbuf[i] = '\0';
                        commands[command_idx++] = atoi(&strbuf[previous_num_idx]); 
                    }
                    if( isnum(strbuf[i+1]) ) { previous_num_idx = i+1; }   
                }
                i++;
            }
            // printf("move %i from %i to %i\n\n", commands[0], commands[1], commands[2]);
            
            commands[1]--;
            commands[2]--;

            // move commands[0] objects
            for ( int i = 0; i < commands[0]; i++ ) {
                if ( crates[commands[1]][0] == 0 ) { break; }
                crates[commands[2]][++crates[commands[2]][0]] = crates[commands[1]][crates[commands[1]][0]];
                crates[commands[1]][crates[commands[1]][0]--] = 0;
            }
            
            // printf("\nletter positions at line %i\n", line);
            // int maxposition = 0;
            // for ( int row = 0; row < 3; row ++ ) { 
            //     maxposition = crates[row][0] > maxposition ? crates[row][0] : maxposition; 
            //     // reverse_array(crates[row], 1, crates[row][0]);
            // }

            // for ( int i = maxposition; i > 0; i-- ) {
            //     for ( int row = 0; row < 3; row ++ ) {
            //         if ( crates[row][i] == '\0' ) { printf("    "); }
            //         else { printf("[%c] ", crates[row][i]); }
            //     }
            //     printf("\n");
            // }    

        }
        line++;
    }
    printf("\nfinal letter positions\n");
    int maxposition = 0;
    for ( int row = 0; row < 9; row ++ ) { 
        maxposition = crates[row][0] > maxposition ? crates[row][0] : maxposition; 
        // reverse_array(crates[row], 1, crates[row][0]);
    }

    for ( int i = maxposition; i > 0; i-- ) {
        for ( int row = 0; row < 9; row ++ ) {
            if ( crates[row][i] == '\0' ) { printf("    "); }
            else { printf("[%c] ", crates[row][i]); }
        }
        printf("\n");
    }    

    fclose(fptr);
    return 0;
}

