#include<bits/stdc++.h>
using namespace std;
string s;
int a[15];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<48||ch>57){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>=48&&ch<=57){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();++i){
		if(s[i]>=48&&s[i]<=57){
			a[s[i]-48]++;
		}
	}
	for(int i=9;i>=0;--i){
		for(int j=1;j<=a[i];++j){
			cout<<i;
		}
	}
	return 0;
}
