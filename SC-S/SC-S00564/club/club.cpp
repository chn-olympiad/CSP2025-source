#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int T,n,m;
int a[N];
struct node{
	int f,s,t;
}p[N];
int f[N];
char s[N];
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void write(int n){
	if(n<0){
		n=-n;
		putchar('-');
	}
	if(n>=10){
		write(n/10);
	}
	putchar(n%10+'0');
}
void init(){
	memset(f,0,sizeof f);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		init();
		n=read();
		for(int i=1;i<=n;i++){
			int x,y,z;
			p[i].f=read();
			p[i].s=read();
			p[i].t=read();
		}
		int ans=0;
		for(int i=1;i<=3;i++){
			for(int j=n/2;j>=1;j--){
				for(int k=1;k<=n;k++){
					int x;
					if(i==1) x=p[k].f;
					if(i==2) x=p[k].s;
					if(i==3) x=p[k].t;
					f[j]=max(f[j],f[j-1]+x);
//					cout<<j<<' '<<k<<' '<<f[i][j]<<'\n';
				}
			}
			ans+=f[n/2];
		}
		
		write(ans);
		putchar('\n');
	}
	return 0;
}
