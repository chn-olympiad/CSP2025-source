#include<bits/stdc++.h>
using namespace std;
string s;
int pos[12];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')pos[(int)s[i]-48]++;
    }
    for(int i=9;i>=0;i--){
        if(pos[i]){
            for(int j=1;j<=pos[i];j++)cout<<i;
        }
    }
    return 0;
}
