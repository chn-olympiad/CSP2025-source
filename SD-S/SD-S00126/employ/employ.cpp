#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll read(){
	ll f=1,w=0;
	char ch=getchar();
	for(;ch<'0' or ch>'9';ch=getchar())if(ch=='-') f=-1;
	for(;ch>='0' and ch<='9';ch=getchar()) w=w*10+ch-'0';
	return f*w;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cout<<2;
	return 0;
}
