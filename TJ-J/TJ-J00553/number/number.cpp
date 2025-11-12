#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e6+3;
string s;
int numlist[MAXN];
int id=1;

bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i=0;i<=s.length();i++){
        if(s[i] >= '0' && s[i] <= '9'){
            numlist[id] = s[i]-48;
            id++;
        }
    }
    sort(numlist+1,numlist+id+1,cmp);
    for(int i=1;i<id;i++){
        cout << numlist[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
