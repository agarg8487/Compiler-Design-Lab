#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool letter(string tok)
{
    for(int i = 0; i < tok.length() ; i++){

    }
}

int main(){
    string line;
    getline( cin, line);
    // Vector of string to save tokens 
    vector <string> inputtokens; 
      
    // stringstream class check1 
    stringstream check1(line); 
      
    string intermediate; 
      
    // Tokenizing w.r.t. space ' ' 
    while(getline(check1, intermediate, ' ')) 
    { 
        inputtokens.push_back(intermediate); 
    }
    // for(auto i=inputtokens.begin(); i!=inputtokens.end();i++){
    //     cout<< (*i)<<endl; 
    // }
    cout<<endl;

    int flag=0;    
    vector<pair<string,string>> outtokens;    
    for(auto i = inputtokens.begin(); i != inputtokens.end(); i++){
        pair<string,string> temp;
        regex letter("[a-zA-Z]");
        regex digit("[0-9]");
        regex number("^[0-9]+(\\.[0-9]+)?$");
        regex id("^[a-zA-Z]+([a-zA-Z0-9])+?$");
        smatch m;
        if(*i=="if"){   
            temp.first = "if";
            temp.second = "if";
            outtokens.push_back(temp);
            continue;
        }
        else if(*i =="else"){   
            temp.first = "else";
            temp.second = "else";
            outtokens.push_back(temp);
            continue;
        }
        else if(*i =="then"){   
            temp.first = "then";
            temp.second = "then";
            outtokens.push_back(temp);
            continue;
        }
        else if( *i=="<" || *i==">" || *i=="<=" || *i==">=" || *i=="=" || *i=="<>" ){
            temp.first = "relop";
            temp.second = *i;
            outtokens.push_back(temp);
            continue;
        }
        else if(regex_match(*i, m, letter))
        {
            temp.first = "letter";
            temp.second = *i;
            outtokens.push_back(temp);
            continue;
        }
        else if(regex_match(*i, m, digit))
        {
            temp.first = "digit";
            temp.second = *i;
            outtokens.push_back(temp);
            continue;
        }
        else if(regex_match(*i, m, number))
        {
            temp.first = "number";
            temp.second = *i;
            outtokens.push_back(temp);
            continue;
        }
        else if(regex_match(*i, m, id))
        {
            temp.first = "id";
            temp.second = *i;
            outtokens.push_back(temp);
            continue;
        }
        else
        {
            flag=1;
            temp.first = "INVALID";
            temp.second = *i;
            // cout<< "Attribute- " + (temp).first + "  Value- " + (temp).second<<endl;
            // cout<<"Error! Returning the program."<<endl;
            outtokens.push_back(temp);
            // return 0;
        }
        
    }
    if(flag){
        cout<<"INVALID attributes found."<<endl;
        for(auto i=outtokens.begin(); i!=outtokens.end();i++){
            if((*i).first=="INVALID")
                cout<< "Attribute- " + (*i).first + "  Value- " + (*i).second<<endl; 
        }
        cout<<"Error! Exiting the program."<<endl;
        return 0;
    }
    
    for(auto i=outtokens.begin(); i!=outtokens.end();i++){
        cout<< "Attribute- " + (*i).first + "  Value- " + (*i).second<<endl; 
    }
    return 0;
}