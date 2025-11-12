#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+(ch^48),ch=getchar();
	return x;
}const int N=1e5+5;
int a[N][3];
struct node{
	int t[N],cnt=0;
	void pop(){
		int p=1;swap(t[p],t[cnt--]);
		while(p*2+1<=cnt){
			if(t[p*2]<t[p*2+1]&&t[p]>t[p*2])swap(t[p],t[p*2]),p*=2;
			else if(t[p]>t[p*2+1])swap(t[p],t[p*2+1]),p=p*2+1;
			else break;
		}if(p*2<=cnt&&t[p]>t[p*2])swap(t[p],t[p*2]);
	}void push(int x){
		int p;t[p=++cnt]=x;
		while(t[p]<t[p/2])swap(t[p],t[p/2]),p/=2;
	}void clear(){
		memset(t,0,4*(cnt+1));cnt=0;
	}
}c[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		int n=read(),ans=0;
		for(int i=1,ma,ma1;i<=n;i++){
			ma=0;ma1=-1;a[i][0]=read();
			for(int j=1;j<3;j++){
				a[i][j]=read();
				if(a[i][j]>=a[i][ma])ma1=ma,ma=j;
				else if(ma1==-1||a[i][j]>=a[i][ma1])ma1=j;
			}c[ma].push(a[i][ma]-a[i][ma1]);ans+=a[i][ma];
		}for(int j=0;j<3;j++){
			if(c[j].cnt>n/2){
				while(c[j].cnt>n/2)ans-=c[j].t[1],c[j].pop();
			}c[j].clear();
		}cout<<ans<<'\n';
	}
	return 0;
}
