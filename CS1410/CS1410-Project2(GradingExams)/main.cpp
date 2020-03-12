//
//  main.cpp
//  Project 2
//
//  Created by Riley Stahura on 9/11/18.
//  Copyright © 2018 Riley Stahura. All rights reserved.
//
/*
 Your program should work as follows:
 
 All user input should be tested to be sure that it is a valid integer value in the range 0 to 100.
 
 It should ask the user to enter in the score for the first midterm. Then this value is read in and saved.
 
 It should ask the user to enter in the score for the second midterm. Then this value is read in and saved.
 
 It should ask the user to enter in the score for the final exam. Then this value is read in and saved.
 
 The program then asks the user to enter in the scores for the homework assignments. Any number of scores can be entered in. You will test for a -1 entry to stop adding to the vector.
 
 Store the homework scores in a vector.
 
 Once all of the data has been entered, the program calls a function that you have written to find the median homework score.
 
 The program then calls a function that you have written to calculate and return the letter grade. The return grade is based upon the total of the three exams plus the median homework score (total points).
 
 Finally, display the median homework score, the total point count, and the letter grade.
 */



/*
 Professor Dolittle has asked some computer science students to write a program that will help him calculate his final grades. Professor Dolittle gives two midterms and a final exam. Each of these is worth 100 points. In addition, he gives a number of homework assignments during the semester. Each homework assignment is worth 100 points.
 
 At the end of the semester, Professor Dolittle wants to calculate the median score on the homework assignments for the semester. He believes that the median score is a good measure of the student's overall performance on the homework assignments. The median is found by putting the homework scores in order, and then taking the score that is at the midpoint of this list. If there are an odd number of assignments, the median is the score exactly in the middle of the list. If there are an even number of assignments, the median is the average of the two scores closest to the midpoint of the data.
 
 Once the median score is known, professor Dolittle takes the sum of the exam scores and the median homework score and uses this value to compute a letter grade. Letter grades are assigned based on the following table:
 
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int i;
int j;
int median;
int total = 0;
char grade;
int score1 = 0;
int score2 = 0;
int score3 = 0;
int hwScore;
int exitCode = 0;
vector<int> scoresList;

void GetGrade(int total){
    string grade;
    if ((total >= 381) && (total <= 400)) {
        grade = "A";
    }
    if ((total > 361) && (total < 380)) {
        grade = "A-";
    }
    if ((total > 341) && (total <= 360)) {
        grade = "B+";
    }
    if ((total > 321) && (total < 340)) {
        grade = "B";
    }
    if ((total > 301) && (total < 320)) {
        grade = "B-";
    }
    if ((total > 281) && (total < 300)) {
        grade = "C+";
    }
    if ((total > 261) && (total < 280)) {
        grade = "C";
    }
    if ((total > 241) && (total < 260)) {
        grade = "C-";
    }
    if ((total > 221) && (total < 240)) {
        grade = "D+";
    }
    if ((total > 201) && (total < 220)) {
        grade = "D";
    }
    if ((total > 181) && (total < 200)) {
        grade = "D-";
    }
    if (total <= 180) {
        grade = "Fail";
    }
    
    cout << "The letter calculated letter grade is " << grade << endl;
}

void GetMedian(vector<int>& list, int& score1, int& score2, int& score3) {
    int sum = 0;
    int halfSize;
    int halfSizeMinus1;
    int tempVal = 0;
    int oldVal = 0;
    //for (j = 0; j < list.size(); j++) {
    //    }
    sort(list.begin(),list.end());
    
    halfSize = list.size() / 2;
    halfSizeMinus1 = halfSize - 1;
    
    median = (list.at(halfSize) + list.at(halfSizeMinus1)) / 2;
    total = score1 + score2 + score3 + median;
    
    cout << "The median homework score was " << median << endl;
    cout << "The total points earned was " << total << endl;
    GetGrade(total);
    
}


int main() {
    
    cout << "Dr. DoLittle's Grading Program ....." << endl << endl;
    while (exitCode == 0) {
        
        cout << "Please enter in the score for the first exam: " ;
        cin >> score1;
        cout << endl << endl;
        
        while (cin.fail()) {
            cout << "Sorry, your input must be an integer. Please try again." << endl;
            cout << "Please enter in the score for the first exam: "  << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            cin >> score1;
        }
        
        if ((score1 >= 0) && (score1 <= 100)) {
            exitCode = 1;
        } else {
            cout << "Sorry, your input must be between 0 and 100. Please try again." << endl;
        }
        
        
    }
    
    exitCode = 0;
    while (exitCode == 0) {
        
        cout << "Please enter in the score for the second exam: " ;
        cin >> score2;
        cout << endl << endl;
        
        while (cin.fail()) {
            cout << "Sorry, your input must be an integer. Please try again." << endl;
            cout << "Please enter in the score for the second exam: "  << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            cin >> score2;
        }
        
        if ((score2 >= 0) && (score2 <= 100)) {
            exitCode = 1;
        } else {
            cout << "Sorry, your input must be between 0 and 100. Please try again." << endl;
        }
        
    }
    
    exitCode = 0;
    while (exitCode == 0) {
        
        cout << "Please enter in the score for the final exam: " ;
        cin >> score3;
        cout << endl << endl;
        
        while (cin.fail()) {
            cout << "Sorry, your input must be an integer. Please try again." << endl;
            cout << "Please enter in the score for the final exam: "  << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            cin >> score3;
        }
        
        if ((score3 >= 0) && (score3 <= 100)) {
            exitCode = 1;
        } else {
            cout << "Sorry, your input must be between 0 and 100. Please try again." << endl;
        }
        
    }
    
    exitCode = 0;
    while (exitCode == 0) {
        cout << "Enter the score for a homework assignment: ";
        cin >> hwScore;
        cout << endl << endl;
        
        while (cin.fail()) {
            cout << "Sorry, your input must be an integer. Please try again." ;
            cout << "Enter the score for a homework assignment: ";
            cin.clear();
            cin.ignore(1024, '\n');
            cin >> hwScore;
        }
        if (hwScore == -1){
            exitCode = 1;
        } else if((hwScore < -1) || (hwScore > 100)) {
            cout << "Sorry, your input must be between 0 and 100. Please try again." << endl;
        } else {
            scoresList.push_back(hwScore);
        }
    }
    
    for (i = 0; i < scoresList.size(); i++) {
        total = total + scoresList.at(i);
    }
    
    GetMedian(scoresList, score1, score2, score3);
    
    
    
    
    
    
    
    //cout << score1 << endl;
    //cout << score2 << endl;
    //cout << score3 << endl;
    
    
    return 0;
}

