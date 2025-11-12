#include<bits/stdc++.h>
using namespace std;

string s;

int x[1000001];

bool cmp(int a,int b){

    return a>b;

}

int main(){

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin >> s;
    int l=0;
    for(int i=0;i<s.size();i++){

        if(s[i]>='0' && s[i]<='9'){
            x[l]=s[i]-'0';
            l++;
        }

    }
    sort(x,x+l,cmp);
    for(int i=0;i<l;i++){
        cout <<x[i];
    }
    return 0;

}
