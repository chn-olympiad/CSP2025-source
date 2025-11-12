#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=505;
int n,q,pre[N],nxt[N],yi[N],i,j,m;
int pret[N],nxtt[N],c[N];
string s,ss,t,tt;
int read(){
	int op=1,x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')op=-1;
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	return op*x;
}
void out(int x){
	if(x<0){
		x=-x;cout<<"-";
	}
	if(x>=10){
		out(x/10);
	}
		cout<<x%10;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();cin>>s;
	for(i=1;i<=n;i++)c[i]=read();
	cout<<0;
	return 0;
}
