#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch))f=ch=='-'?-f:f,ch=getchar();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
const int N=1105;
int n,m,a[N],s,c;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++)a[i]=read();
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)if(s==a[i])s=i;
	for(int i=1;i<=n;i++){
		int tot;
		if(i&1)tot=m*(i-1)+1;
		else tot=m*i;
		if(i&1)
			for(int j=1;j<=m;j++){
				if(tot==s){
					cout<<i<<' '<<j<<endl;
					return 0;
				}
				tot++;
			}
		else
			for(int j=1;j<=m;j++){
				if(tot==s){
					cout<<i<<' '<<j<<endl;
					return 0;
				}tot--;
			}
	}
	return 0;
}
//I_Love_Furina
//1113349
//275713829
//Genshin Impact
//Furina!!!