#include<bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 200001
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0'; ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
struct node{
	int x,tag;
}A[maxn];
bool cmp(node a,node b){
	return a.x>b.x;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	n=read(); m=read();
	for(int i=1;i<=n*m;i++){
		A[i].tag=i; A[i].x=read();
	}
	sort(A+1,A+1+n*m,cmp);
	int place;
	for(int i=1;i<=n*m;i++)if(A[i].tag==1)place=i;
	int ansl=(place+n-1)/n,ansr;
	int rest=(place-1)%n+1;
	if(ansl%2==0){
		ansr=n-rest+1;
	}
	else ansr=rest;
	write(ansl); cout<<" "; write(ansr); cout<<endl;
	return 0;
}
