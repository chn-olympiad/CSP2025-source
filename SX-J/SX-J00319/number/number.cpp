#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string s,ss="";
	long long t=0;
	cin>>s;
 	long long len=s.size();
	for(long long i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9') ss[++t]=s[i];
	}
	for(long long i=t-1;i>=1;i--){
		for(long long j=i;j<=t;j++){
			if(ss[i]<ss[j]) swap(ss[i],ss[j]);
		}
	}
	for(long long i=1;i<=t;i++){
		cout<<ss[i];
	}
	return 0;
}