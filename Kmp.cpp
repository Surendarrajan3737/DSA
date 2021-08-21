#include <bits/stdc++.h>

using namespace std;

void pattern(int lps[],string pat,int N){
    int j=0,i=1;
    lps[0] = 0;     // It is always 0;
    while(i<N){
        if(pat[i] == pat[j]){
            j++;
            lps[i] = j;
            i++;
        }
        else{
            if(j!=0){
                j = lps[j-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void search(string txt,string pat){
    int M = txt.size();
    int N = pat.size();

    int i=0,j=0;

    int lps[N] = {0};

    pattern(lps,pat,N);

    while(i<M){
        if(txt[i] == pat[j]){
            i++;
            j++;
        }

        if(j==N){
            cout << "The pattern is found at the index : " << i-j << '\n';
            j = lps[j-1];
        }

        else if(i<M && txt[i] != pat[j]){
            if(j!=0){
                j = lps[j-1];
            }
            else
                i++;
        }
    }
}
int main(){
    string txt = "ABABDABACDABABCABAB";
    string pat = "BAC";

    search(txt,pat);
    return 0;
}
