// Implementing Robin Karp Algorithm using rolling harsh function;

#include <bits/stdc++.h>

using namespace std;

#define d 256

void search(string txt,string pat,int q){
    int M = txt.length();
    int N = pat.size();
    int h = 1;      // Max hashcode;
    int t = 0;  // hash code for text;
    int p = 0;  // hashcode for pattern;

    // finding maximum hash value for the string;

    for(int i=0;i<N-1;i++){
        h = (h*d)%q;
    }

    for(int i=0;i<N;i++){
        t = (d * t + txt[i])%q;
        p = (d * p + pat[i])%q;
    }

    int i=0;
    while(i<=M-N){
        if(t == p){  
            int j;   // Thst refers that the hashcode is same
            for(j=0;j<N;j++){
                if(txt[i+j] != pat[j])
                    break;
            }
            if(j == N)
                cout << "The pattern is matched at : " << i << '\n';
        }

        // Movement for the next window using rolling hash;
        if(i<M-N){
            t = ((t-txt[i]*h)*d + txt[i+N])%q;

            // some cases t becomes negative; so make positive
            if(t<0)
                t += q;
        }
        i++;
    }

}

int main(){
    string txt = "Geeks for Geeks";
    string pat = "Geeks";

    int q = 101;
    search(txt,pat,q);
    return 0;
}
