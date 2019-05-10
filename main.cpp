//
//  main.cpp
//  catchmatch
//
//  Created by Mohit Gadi on 4/6/19.
//  Copyright © 2019 Mohit Gadi. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

#define ch 256

bool setprime(int rem)
{
    
    bool set=true;
    
    int x = 0;
    
    for(x = 2; x <= rem / 2; x++)
    {
        
        if(rem % x == 0)
        {
            set = false;
            
            break;
        }
    }
    return set;
}

void rabinkarpsearch(string pattern){
    //string text = "This is Design algorithm";
    //string pattern = "esi";
    string text;
    ofstream rabinkarpoutputfile ("rabinkarp.txt");
    ifstream stringfile ("stringfile.txt");
    int timeCount = 0;
    while(getline(stringfile, text)){
    int s=0;
    int prime=0;
    cout<<"\n\n------------RABIN KARP RESULTS FOR PATTERN "<<pattern<<"----------\n\n"<<endl;
    
    while(true){
        
        s =  rand() % 100 + 1985;
        if(setprime(s))
        {
            prime= s;
            break;
        }
    }
    
    int pLength = pattern.length();
    
    //int patlen = 0;
    
    int tLength = text.length();
    
    int j=0;
    
    int pHash = 0; // hash value for pattern
    int tHash = 0; // hash value for txt
    
    //int freq=0;
    
    
    
    int z = 1;
    
    for (int i = 1; i <= pLength - 1; i++)
    {
        z = (ch * z) % prime;
        timeCount++;
    }
    
    for (int j = 0; j < pLength; j++)
    {
        pHash = (ch * pHash + pattern[j]) % prime;
        timeCount++;
    }
    // patHash=p;
    
    for (int j = 0; j < pLength; j++) {
        tHash = (ch * tHash + text[j]) % prime;
        timeCount++;
    }
    //txtHash=t;
    //cout<<t<<endl;
    //cout<<p<<endl;
    //search(pat, text, q, patHash,txtHash,patlen);
    
        int offset = tLength - pLength;
    
        int l=0;
    
        while (l<=offset){
        // for (i = 0; i <= tLength - pLength; i++)
        
        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters on by one
        
            if ( pHash == tHash )
        
            {
            /* Check for characters one by one */
            for ( j = 0; j < pLength; j++)
            {
                timeCount++;
                if (text[l+j] != pattern[j])
                    break;
            }
            
            // if p == t and pattern[0...pLength-1] = text[i, i+1, ...i+pLength-1]
            if (j == pLength)
                cout<<"Pattern found at index "<< l+pLength<<" and pattern matched is '"<<pattern<<"'\n"<<endl;
            
                rabinkarpoutputfile<<"Pattern found at index "<< l+pLength<<" and pattern matched is '"<<pattern<<"'\n"<<endl;
                }
                
                // Calculate hash value for next window of text: Remove
                // leading digit, add trailing digit
                if ( l < tLength-pLength )
            {
                
                tHash = (ch*(tHash - text[l]*z) + text[l+pLength])%prime;
                // We might get negative value of t, converting it
                // to positive
                
                if (tHash < 0)
                    tHash = (tHash + prime);
            }
            l++;
        }
    }
    //cout<<timeCount<<endl;
}

void lcsssearch(string line2){ //By Himanshu Ahuja
    cout<<"\n\n-----------------LCSS RESULTS FOR PATTERN - "<<line2<<"----------------\n\n"<<endl;
    
    string line1;
    
    string A;
    
    string B;
    
    int lcsssearchtime = 0;
    
    int lcsslinecount = 0;
    
    int position=0;
    
    ofstream lcsoutputfile ("lcs.txt");
    
    ifstream myinputfile ("stringfile.txt");
    
    while(getline( myinputfile , line1 )){
    
        
        lcsslinecount++;
        
        A = line1;
        
        B = line2;
        
        int m = A.length();//size of string1
        
        
        int n = B.length();//size of string2
        
        int similarity = 0;
        
        int c[m+1][n+1];//for matrix
        
        char b[m+1][n+1];//for directions(U,D,L)
        
        c[0][0] = 0;
        
        for(int i = 1; i <= m; i++)
        
            c[i][0] = 0;
        for(int j = 1; j <= n; j++)
            c[0][j] = 0;
        
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1;j <= n; j++)
            {
                lcsssearchtime++;
                if(A[i-1] == B[j-1])
                {
                    c[i][j] = c[i-1][j-1] + 1;
                    b[i][j] = 'D';
                    position = i;
                }
                else
                {
                    if(c[i-1][j] >= c[i][j-1])
                    {
                        c[i][j] = c[i-1][j];
                        b[i][j] = 'U';
                    }
                    else
                    {
                        c[i][j] = c[i][j-1];
                        b[i][j] = 'L';
                    }
                }
            }
        }
        
        //printing longest common subsequence
        
        similarity =(c[m][n]*100)/n;
        
        if(similarity>30){
            lcsoutputfile<<"\nLength of longest common subsequence is "<<c[m][n];
            cout<<"\nLength of longest common subsequence is "<<c[m][n];
            lcsoutputfile<<"\nPercentage of pattern matched is "<<similarity<<"%";
            cout<<"\nPercentage of pattern matched is "<<similarity<<"%";
        }
        
        
        int index = c[m][n];
        
        char ans[index];//creating char array for storing string
        
        int i = m,j=n;
        
        while(i > 0 && j > 0)
        
        {
            if(b[i][j] == 'L')
                j--;
            else if(b[i][j] == 'D')//for every diagonal there is value of LCS
            {
                ans[index-1] = A[i-1];
                index--;
                i--;
                j--;
            }
            else
                i--;
        }
        
        if(similarity>30){
            lcsoutputfile<<"\nLongest common subsequence is "<<ans<<" at line "<<lcsslinecount<<endl;
            cout<<"\nLongest common subsequence is "<<ans<<" at line "<<lcsslinecount<<endl;
        }
    }
    
    cout<<"\nTime taken for search: "<<lcsssearchtime<<"\n"<<endl;
    lcsoutputfile<<"\nTime taken for search: "<<lcsssearchtime<<"\n"<<endl;
}

void kmpsearch(string patternline){ //By MohitGadi
    cout<<"\n\n-----------------KMP RESULTS FOR PATTERN - "<<patternline<<"----------------\n\n"<<endl;
    ofstream kmpoutputfile ("kmp.txt");
    
    ifstream stringfile ("stringfile.txt");
    
    int searchtime = 0;
    
    int stringlinecount = 0;
    
    string stringline;
    
    string line;
    
    int preprocessingtime = 0;
    
    unsigned long patternlinelength = 0;
    
    unsigned long stringlinelength = 0;
    
    patternlinelength = patternline.length();
    
    char patternlinec[patternlinelength+1];
    
    strcpy(patternlinec, patternline.c_str());
    
    int length = 0;
    
    int lps[patternlinelength+1];
    
    lps[0]=0;
    int i = 1;
    
    while(i <= patternlinelength){
        preprocessingtime++;
        
        if(patternlinec[i] != patternlinec[length]){
            
            if (length==0) {
                lps[i] = 0;
                
                i++;
                
                
            }
            
            else if(length!=0){
                length = lps[length-1];
            }
            
        }
        
        else if(patternlinec[i] == patternlinec[length]){
            length++;
            
            lps[i] = length;
            
            i++;
        }
    }
    
    while (getline(stringfile,stringline))
    {
        stringlinecount++;
        stringlinelength = stringline.length();
        
        char stringlinec[stringlinelength+1];
        
        strcpy(stringlinec, stringline.c_str());
        
        int stringindex = 0; // string index
        
        int patternindex = 0; // pattern index
        
        double percentage = 0;
        
        while(stringindex < stringlinelength){
            
            searchtime++;
            
            if(patternlinec[patternindex] == stringlinec[stringindex]){
                stringindex++;
                patternindex++;
            }
            
            if(patternindex == patternlinelength){
                cout<<"\nPattern fully matched at line number: "<<stringlinecount<<" at index: "<<searchtime<<endl;
                
                cout<<"Pattern matched: "<<patternline<<endl;
                
                kmpoutputfile << "Pattern fully matched at line number: "<<stringlinecount<<endl;
                
                kmpoutputfile << "Pattern matched: "<<"'"<<patternline<<"'"<<'\n'<<endl;
                
                patternindex = lps[patternindex - 1];
            }
            
            else if (patternlinec[patternindex] != stringlinec[stringindex]) {
                
                percentage = (100*patternindex)/patternlinelength;
                if(stringindex < stringlinelength){
                    
                    if(patternindex == 0){
                        stringindex++;
                        
                    }
                    else if(patternindex!=0){
                        
                        patternindex = lps[patternindex - 1];
                    }
                    
                }
                else if(stringindex == stringlinelength && percentage>=30){
                    cout<<"\nPattern partly matched\nCharacters matched of pattern '"<<patternline<<"' at line: "<<stringlinecount<<" at index: "<<searchtime<<"\nPercentage of pattern matched: "<< percentage <<"%"<<endl;
                    
                    kmpoutputfile<<"Pattern partly matched\nCharacters matched of pattern '"<<patternline<<"' at line: "<<stringlinecount<<" at index: "<<searchtime<<"\nPercentage of pattern matched: "<< percentage <<"%\n"<<endl;
                    
                }
            }
            
            
            
        }
    }
    cout<<"\nTime taken for LPS table: "<<preprocessingtime<<" for pattern '"<<patternline<<"'"<<endl;
    
    kmpoutputfile<<"\nTime taken for LPS table: "<<preprocessingtime<<" for pattern '"<<patternline<<"'"<<endl;
    
    cout<<"Time taken for search: "<<searchtime<<" for pattern '"<<patternline<<"'"<<"\n"<<endl;
    
    kmpoutputfile<<"Time taken for search: "<<searchtime<<" for pattern '"<<patternline<<"'"<<"\n"<<endl;
}

int main (){
    char space = ' ';
    
    string patternline;
    ifstream patternfile ("patternfile.txt");
    while(getline(patternfile,patternline, space)){
        kmpsearch(patternline);
        
        lcsssearch(patternline);
        
        rabinkarpsearch(patternline);
    }
    patternfile.close();
}
