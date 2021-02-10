//  Matthew McCormack
//  Lab2 CS3080
//  2/11/2021

#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char * argv[])
{
    int pipe1[2];
    pid_t childPid;
    int buff;
    int min = 999;
    int max = 999;
    float avg = 0;
    int sum = 0;
    int numItems = atoi(argv[1]);
    int range = atoi(argv[2]);
    int seed = atoi(argv[3]);
    pipe(pipe1); 
    childPid = fork(); 
    if (childPid == 0) 
    {
        close(pipe1[1]); 

        while (read(pipe1[0], &buff, sizeof(buff)) > 0) 
        {  
            if (buff < min)
            min = buff;

            if (buff > max)
            max = buff;
            sum += buff;

        }
        avg = sum/numItems;
        close(pipe1[0]);
        cout << " Child ID:" << getpid() << " number of items received: " << numItems << " min: " << min << " max: " << max << " avg: " <<avg << endl;
    }
    else
    {
        close(pipe1[0]);
        srand(seed);

        for (int i=0; i< numItems ; i++)
        {
            int random = rand() % range;
            write(pipe1[1], &random ,sizeof(random)); 

        }
        close(pipe1[1]);
        cout << " Parent ID: " << getpid() << " number of items written into the pipes are: " << numItems << endl;
        wait(NULL);
    }
    return 0;
}