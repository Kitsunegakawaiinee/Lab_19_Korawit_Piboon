#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename, vector <string> &names, vector <int> &scores, vector <char> &grades)
{
    //cout << "Enter Import" << endl; //debug
    ifstream FR;
    int s1,s2,s3,sums;
    char inputname[100];
    string name,text;
    char format[] = "%[^:]: %d %d %d";
    FR.open(filename);
    int count = 0; // debug

    while(getline(FR, text))
    {

        cout << count++ << "."<< text << endl; //debug
        name = "";
        sscanf(text.c_str(),format,&inputname,&s1,&s2,&s3);

        sums = (s1+s2+s3);
        scores.push_back(sums);

        name += inputname;
        names.push_back(name);

        grades.push_back(score2grade(sums));
        cout << name << " " << sums << " " << score2grade(sums) << endl << endl; // debug
        
    }
    FR.close();

    // for(int i =0; i<names.size(); i ++) cout << names[i] << endl;
    // cout << endl;

    // for(int i =0; i<names.size(); i ++) cout << scores[i] << endl;
    // cout << endl;

    // for(int i =0; i<names.size(); i ++) cout << grades[i] << endl;
    // cout << endl;

    //debug
}

void getCommand(string &command, string &key)
{
    cout << "Enter command" << endl;
    char text_com[10];
    char text_key[100]; 
    char format[] = "%s %s";
    string get;
    
    cout << "---------------------------------\nPlease input your command:";
    getline(cin, get);
    //cout << get << endl; // de bug
    cout << "---------------------------------\n";

    sscanf(get.c_str(),format,&text_com,&text_key);

    //cout << text_com << " " << text_key << endl; //debug

    command += text_com;
    key += text_key;

}

void searchName(vector <string> names, vector <int> scores, vector <char> grades, string key)
{
    //cout << "Enter SN" << endl; //debug
    int index;
    bool found = false;
    cout << key << endl;

    for(unsigned int i = 0; i<names.size(); i++)
    {
        if (toUpperStr(names[i]) == key) 
        {
            index = i;
            found = true;
        }
    }

    if(found) 
    cout << names[index] << "'s score = " << scores[index] <<endl
    << names[index] << "'s grade = " << grades[index] << endl;
    else cout << "Cannot found." << endl;
}

void searchGrade(vector <string> names, vector <int> scores, vector <char> grades, string key)
{
    cout << "Enter SG" << endl; //debug
    vector <int> index;

    char newkey = key[0];
    cout << newkey << endl; //debug

    for(unsigned int i = 0; i<grades.size(); i++)
    {
        cout << "Enter loop check grade" << endl; //debug
        cout << names[i] << " " << grades[i] << endl;
        if (grades[i] == newkey) 
        {
            index.push_back(i);
            cout << "found" << endl; //debug
        }
        cout << endl; // debug
    }

    for(int i = 0; i<index.size(); i++) cout << index[i] << endl;

    for (unsigned int i = 0; i < index.size(); i++)
    {
        cout << names[index[i]]+" (" << scores[index[i]] <<")" << endl;
    }
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    //cout << "Enter main" << endl; //debug
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
