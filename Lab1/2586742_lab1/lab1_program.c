/*
Name: Jiahui Wang
Course: EECS 268 
assignment: Lab1
Description:we will develop a simple html cleaner and we will obtain (via argv[ ]) the names of (i) a source html file, (ii) a simple text file of keywords, and (iii) optionally the name of an output html file.we will read the html file, one symbol at a time.And write each symbol I read to the output html file, we need to write additional characters.*/
 

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]){

string arr1[500];// read the given txt file
std::ifstream file1("Lab01SampleKeywords.txt");
string kw;

int a = 0;// assign the keywords I read to the arr1.
while (file1>>kw){
arr1[a] = kw;
a++;}

file1.close();//clos the file1.

std:: ifstream file2("Lab01Sample.html");// read the seccond given file.
string arr2[50000];
string word;

int b=0;// assign the words to the arr2.
while (file2>>word)
{
arr2[b]=word;
b++;}

file2.close();//close file2.

for(int i =0; i<b; i++){
for (int j =0; j<a; j++){//find the keyword and italicize the keywords.
if (arr2[i]==arr1[j] || arr2[i]==arr1[j] +"," || arr2[i] == arr1[j] + "."){
arr2[i] = "<i>" + arr2[i] + "</i>";
}
}

if (arr2[i] =="<p>"||arr2[i] =="</body>"){// find the symbol <p> and put the </p> behind <p>.
arr2[i] = "</p>" + arr2[i];}}

ofstream outputfile("output.html");//write each symbol I read to the output.html file.
for ( int r = 0; r< b; r++){
outputfile<<arr2[r]<<" ";
cout<<arr2[r]<<" ";}
return 0;
}



