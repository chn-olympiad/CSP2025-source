#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
struct node{
	int num,id;
	bool operator<(const node a){
		return a.num<num;
	}
}a[maxn];
int n,m,ans;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f*=-1;ch=getchar();}
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n*m;i++) a[i].num=read(),a[i].id=i; 
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++) if(a[i].id==1) ans=i;
//	cin>>ans;
	if(((ans-1)/n+1)&1) printf("%d %d\n",(ans-1)/n+1,(ans-1)%n+1);
	else printf("%d %d\n",(ans-1)/n+1,n-((ans-1)%n));
	return 0;
}
//3 3
//2 94 95 96 97 98 99 100 93 92
//#Shang4Shan3Ruo6Shui4
