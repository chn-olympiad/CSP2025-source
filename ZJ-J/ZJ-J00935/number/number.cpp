#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    long long ts;
    cin>>s;
    long long l[10]={};
    for (long long i=0;i<s.length();i++){
        if ((s[i]>='0') && (s[i]<='9'))
        {
        	//cout<<s[i]-48;
        	l[s[i]-48]+=1;
		}
    }
    for (long long i=9;i>=0;i--){
    	for (long long j=0;j<l[i];j++){
    		cout<<i;
		}
	}
    return 0;
}
