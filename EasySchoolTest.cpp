#include <cstring>
#include <ctype.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>

std::ifstream fin("questions.txt");
std::ifstream afin("answers.txt");
//We input the questions with fin and answers with afin
using namespace std;

char student_answer[10],correct_answer[10];
int nr_of_lines=0,nr_of_answers=0,questions_array[10];
//We will lower both the correct and the student answer so we can compare them and not be case-sensitive
    void LOWER() {
    for(int i = 0; student_answer[i]; i++)
        student_answer[i] = tolower(student_answer[i]);
    for(int i = 0; correct_answer[i]; i++)
        correct_answer[i] = tolower(correct_answer[i]);

}

    int check_if_every_value_is_different() {
    int original_val;
    for (unsigned i = 0; i < 9; i++) {
        original_val = questions_array[i];
        for (unsigned k = i + 1; k < 9; k++)
            if (questions_array[i] == questions_array[k]){
                return 0;
        } }
    return 1;
}

    int main() {
//If the student answers wrong all questions he will get an 1 (out of 10)
    int grade=1;
    string line;
    int current_random;
/*We are checking how many questions are there, so we dont have
to store more than 1 question at a time*/
    while (getline(fin,line)) //while there are more questions we increment the variable
    {
        nr_of_lines++;
    }
    while (getline(afin,line)) //while there are more questions we increment the variable
    {
        nr_of_answers++;
    }
    if (nr_of_lines<9 || nr_of_answers!=nr_of_lines) {
        cout<<"The questions file has less than 9 questions or the number of questions and answers is different"<<endl;
        cout<<"Please close the program and put at least 9 questions."<<endl;
        cin>>line; }
    else
    {
    srand(time(NULL)); //makes it more random
    fin.close();
    afin.close();
    std::ifstream fin("questions.txt");
    std::ifstream afin("answers.txt");
//we chose the 9 questions and store them in an array
    for(int i=0; i<9; i++) {
        current_random = rand() % nr_of_lines;// 0 to nr of lines
        questions_array[i]=current_random;
//    cout<<current_random<<endl;
    }
//while a question appears at least 2 times we repick the questions
    while(check_if_every_value_is_different()==0)
        for(int i=0; i<9; i++) {
            current_random = rand() % nr_of_lines;
            questions_array[i]=current_random;
        }
    //Asking the student and verifying the the 9 answers
    for(int i=0; i<9; i++) {
        fin.close();
        std::ifstream fin("questions.txt");
        //storing just one question at a time
        for (int j=0; j<questions_array[i]; j++)
            getline(fin,line);
        cout<<line<<endl;
        for (int j=0; j<questions_array[i]; j++)
            afin>>correct_answer;
//        cout<<correct_answer;
        cin>>student_answer;
        //only if the answers are different we make them both lowercase
        if (strcmp(student_answer,correct_answer))
            LOWER();
            if (strcmp(student_answer,correct_answer)==0)
                grade++;
}
    cout<<"Your grade is "<<grade;
    cin>>line;
    }
}
