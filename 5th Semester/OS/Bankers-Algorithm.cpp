#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

#define RESOURCES 3
#define PROCESSES 4

// The allocation table.
int allocation[][RESOURCES] = {
    { 2, 1, 3 },
    { 1, 2, 3 },
    { 5, 4, 3 },
    { 2, 1, 2 }
};

// The maximum table.
int maximum[][RESOURCES] = {
    { 4, 9, 4 },
    { 5, 3, 3 },
    { 6, 4, 3 },
    { 4, 8, 2 }
};

// Total resources.
int total_resources[] = { 12, 9, 12 };

// The finish table.
bool finish[] = { false, false, false, false };

// The array holding the available resources.
int available[RESOURCES];

// The Work array.
int work[RESOURCES];

// The Need array.
int need[PROCESSES][RESOURCES];

/**
 * Format the output.
 */
template<typename T> void print_cell(T t, const int& width) {
    cout << left << setw(width) << setfill(' ') << t;
}

void process(void) {
    int i = 0;
    int finished_amount = 0;
    int finished_backup = 0;
    bool finished_one = true;
    
    while(true) {
        // Check if the process is not already finished.
        if(!finish[i]) {
            bool good = true;
            
            // Make sure that there are enough resources for this process:
            // Need[i] < Work.
            for(int j = 0; j < RESOURCES; j++) {
                if(need[i][j] > work[j]) {
                    good = false;
                }
            }
            
            // If there are enough resources available to complete this process
            // then add the allocated for this process resources back to the
            // work array.
            if(good) {
                cout << "Able to complete process " << i << " - Work: ";
                
                for(int j = 0; j < RESOURCES; j++) {
                    work[j] += allocation[i][j];
                    print_cell(work[j], 4);
                }
                
                finish[i] = true;
                finished_amount++;
                
                cout << endl;
                finished_one = true;
            }
        }
        
        i = (i + 1) % PROCESSES;
        
        if((i == 0 && finished_amount == finished_backup)) {
            cout << "The system is in an unsafe state" << endl;
            break;
        }
        else if(finished_amount == PROCESSES) {
            cout << "The system is in a safe state" << endl;
            break;
        }
        else if(i == 0) {
            finished_backup = finished_amount;
        }
    }
}

void request_resources(int *request, int len, int j) {
    bool good = false;
    
    for(int i = 0; i < len; i++) {
        if(request[i] > need[j][i]) {
            good = false;
            break;
        }
    }
    
    if(good) {
        for(int i = 0; i < len; i++) {
            if(request[i] > available[i]) {
                good = false;
                break;
            }
        }
        
        if(good) {
            cout << "Allocating the resources for process " << j << endl;
            
            for(int i = 0; i < len; i++) {
                available[i] -= request[i];
                allocation[j][i] += request[i];
                need[j][i] -= request[i];
            }
        }
        else {
            cout << "Process " << j << " must wait. No resources available." << endl;
        }
    }
    else {
        cout << "Process " << j << " can't be given the requested resources ";
        cout << "because the request exceeds the need." << endl;
    }
}

/**
 * Main entry to the program.
 */
int main(void) {
    cout << "Calculating the Available resources" << endl;
    memcpy(available, total_resources, RESOURCES * sizeof(int));
    
    cout << "Calculating the Need array." << endl;
    
    // Fill in the Need array and compute the available resources at the same time.
    for(int i = 0; i < PROCESSES; i++) {
        for(int j = 0; j < RESOURCES; j++) {
            available[j] -= allocation[i][j];
            need[i][j] = maximum[i][j] - allocation[i][j];
            print_cell(need[i][j], 4);
        }
        cout << endl;
    }
    
    // Copy the available array into the work array.
    memcpy(work, available, RESOURCES * sizeof(int));
    
    cout << "Available = Work = ";
    
    // Just print the available array.
    for(int i = 0; i < RESOURCES; i++) {
        print_cell(available[i], 4);
    }
    
    cout << endl;
    
    process();
    
    cout << "Requesting additional resources for Process 1" << endl;
    
    // Reset the work array.
    memcpy(work, available, RESOURCES * sizeof(int));
    
    int new_resources[] = {2, 0, 0};
    request_resources(new_resources, 3, 1);
    
    return 0;
}