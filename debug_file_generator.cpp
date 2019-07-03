#include <bits/stdc++.h>
std::ofstream fout("questions.txt");
std::ofstream afout("answers.txt");
using namespace std;
int main() {
for(int i=0; i<500; i++) {
//Q stands for question, the output will be on first line 'Q'NO
    fout<<'Q'<<i+1<<endl;
    afout<<'a'<<endl;
/*You can also do this as answer
    afout<<'A'<<i+1<<endl; */
}
}
