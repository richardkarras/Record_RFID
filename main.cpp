//Program to play audio files from a "record player" using RFID tags captured on an Arduino, processed through a BeagleBoneBlack

#include <stdio.h>
#include <string>
#include <sstream>
#include "console.h"
#include "simpio.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

//defining reusable modules
string record_init(string record_get[]);
void audio_out(int case_number);

int main()
{
    //Define variables
    string record_get[11];
    // need 4 row, 11 column array, for record info
    string record_storage[4][11];

    //Init loop, build for 4 records
    for (int init_loop = 0; init_loop< 4; init_loop++)
        {
        audio_out(init_loop); // call for audio routine
        record_init(record_storage[init_loop]);

        }
    
    while (1)
        {

        //get rfid input from record player contact
         getline(cin,record_get);
    
        //switch/case build to evaulate incoming rf tag against desired audio out
    
        if(record_get==record_storage[0])
            audio_out(1);
        
        else if (record_get==record_storage[1])
            audio_out(2);
        
        else if (record_get==record_storage[2])
            audio_out(3);
        
        else if (record_get==record_storage[3])
            audio_out(4);
        
        else audio_out(5);
        }
    return 0;
}

string record_init(string record_get[11])

{

    getline(cin, record_get);

    return record_get;
}

void audio_out(int case_number)
{
    switch (case_number)
    {
        case '1':
            system("audio_script_1.sh");
            break;

        case '2':
            system("audio_script_2.sh");
            break;

        case '3':
            system("audio_script_3.sh");
            break;

        case '4':
            system("audio_script_4.sh");
            break;

        default: system("audio_script_error.sh");

    }//output audio queues based on incoming call number
    return;
}