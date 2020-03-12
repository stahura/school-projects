//
//  main.cpp
//  Project 2 alternate
//
//  Created by Riley Stahura on 9/13/18.
//  Copyright © 2018 Riley Stahura. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

void GetGrade(int total) {
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

void GetMedian(vector<int>& list, int& score1, int& score2, int& score3, int& total) {
 
    int halfSize;
    int halfSizeMinus1;

    int median = 0;
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

int GetExamScore(int score) {
    int exitCode = 0;
    string ordNumber;
    
    if (score == 1) {
        ordNumber = "First";
    } else if (score ==2) {
        ordNumber = "Second";
    } else {
        ordNumber = "Final";
    }
    
    while (exitCode == 0) {
        
        cout << "Please enter in the score for the " << ordNumber << " exam: " ;
        cin >> score;
        cout << endl << endl;
        
        while (cin.fail()) {
            cout << "Sorry, your input must be an integer. Please try again." << endl;
            cout << "Please enter in the score for the first exam: "  << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            cin >> score;
        }
        
        if ((score >= 0) && (score <= 100)) {
            exitCode = 1;
        } else {
            cout << "Sorry, your input must be between 0 and 100. Please try again." << endl;
        }
    }
    
    return score;
}

int main() {
    
    int i;
    int total = 0;
    int score1 = 1;
    int score2 = 2;
    int score3 = 3;
    int hwScore;
    int exitCode = 0;
    
    vector<int> scoresList;
    
    cout << "Dr. DoLittle's Grading Program ....." << endl << endl;
    
    score1 = GetExamScore(score1);
    score2 = GetExamScore(score2);
    score3 = GetExamScore(score3);
    
    exitCode = 0;
    while (exitCode == 0) {
        cout << "Enter the score for a homework assignment: ";
        cin >> hwScore;
        cout << endl << endl;
        
        while (cin.fail()) {
            cout << "Sorry, your input must be an integer. Please try again." << endl; ;
            cout << "Enter the score for a homework assignment: ";
            cout << endl;
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
    
    GetMedian(scoresList, score1, score2, score3, total);
    
    
}

