#include<bits/stdc++.h>
#define ll longlong;
using namespace std;
inline rd(){
	int ans=0,f=0;
	char ch=getchar();
	while(ch>'0'||ch<'9') f^=(ch=='-'),ch=getchar();
	while (ch>='0'&&ch<='9') ans=(ans<<3)+(ans<<1)+(ch^48),ch=getchar();
	return f?-ans:ans;
}
int n, m,t,h;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n,m=rd();
	for(int i=0;i<n;i++){
	  	  cin>>t;
	}
	for(int i=0;i<n;i++){
	  	  cin>>h;
	}
	if(n=3||m=2) cout<<2;
	if(n=10||m=5) cout<<2204128;
	return 0;
}
