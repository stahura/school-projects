#include <iostream>
using namespace std;

// Enter your 4 functions here
void hilo(int n);
void GuessNumber(int low, int high);
void rsort(int nums [], int nelems);
void sorthelp(int a[], int start, int n);


int main() {
    hilo(100);
    
    int a[] = {5,4,3,2,1};
    const int n = 5;
  
    rsort(a,n);
    
    cout << "Sorted result:\n";
    for (int n:a)
        cout << n << endl;
    cout << endl;
}

void hilo(int n) {
    cout << "Think of a number between 1 and 100";
    cout << endl;
    cout << "I will try and guess it with your help." << endl << endl;
    
    GuessNumber(1, n);
}

void GuessNumber(int low, int high) {
    int mid;
    char answer;
    
    mid = (high + low) / 2;
    
    cout << "Is it " << mid << " (l,y,h)? " << endl;
    cin >> answer;
    
    if ((answer != 'l') && (answer != 'h')){ // Base Case

        cout << "Your number is " << mid << endl << endl; // Found Number

    }
    else { //Recursive case: Guess in lower or upper half of range
        if(mid == low) {
            if ( answer == 'h') {
                cout << "You cheated!" << endl << endl;
            } else {
            cout << "Your number is " << high << endl << endl;
            }
        }
        else if (answer == 'l') {
            GuessNumber(mid + 1, high);
        } else {
            GuessNumber(low, mid - 1);
        }
    }
    return;
}

void rsort(int nums [], int nelems) {
    
    sorthelp(nums, nums[0], nelems);
}

void sorthelp(int a[], int start, int n) {
    
    int i;
    int tempVal;
    
    
    if (n == 0) {
        
    }
    else {
        for (i = 0; i < n; i = i + 1) {
            
            if (a[i] > a[i+1]) {
                tempVal = a[i];
                a[i] = a[i+1];
                a[i+1] = tempVal;
                
                sorthelp(a, start, n-1);
                
            }
            
        }
    }

}
