#include<bits/stdc++.h>
using namespace std;
int a=1;
string s,n;
int main(){
	freopen("in","r",stdin);
	freopen("out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.size();i++){
        for(int j=0;j<=s.size();j++){
            if(s[i]>s[j]){
                swap(s[i],s[j]);
            }
        }
    }
    cout<<s;
	return 0;
}

