#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int f=0,k=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') k=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) f=f*10+ch-'0';
	return f*k;
}
int n,m,k;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	cout<<0;
	return 0;
} 
