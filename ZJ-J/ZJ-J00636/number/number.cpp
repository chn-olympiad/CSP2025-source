#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int ans;
int s[maxn];
string st;
int n;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,st);
    for(int i=0;i<st.size();i++){
        s[i]=(int)st[i]-48;
        if(s[i]>9)
            s[i]=-1;
    }

    for(int i=0;i<st.size();i++)
        for(int j=0;j<st.size();j++)
            if(s[j]<=s[j+1])
                swap(s[j],s[j+1]);
    for(int i=0;i<st.size();i++){
        if(s[i]!=-1)
            cout<<s[i];
    }

    return 0;

}
