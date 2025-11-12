#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int r=0,x=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')x=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*x;
} 
const int N=1e5+10; 
int t;
int n;
int a[N][5];
int maxx;
int lim;
void dfs(int now,int val,int num1,int num2,int num3){
	if(now>n){
		maxx=max(maxx,val);
		return ;
	}
	if(num1<lim)dfs(now+1,val+a[now][1],num1+1,num2,num3);
	if(num2<lim)dfs(now+1,val+a[now][2],num1,num2+1,num3);
	if(num3<lim)dfs(now+1,val+a[now][3],num1,num2,num3+1);
}
bool jd(int x){
	for(int i=1;i<=n;i++){
		if(a[i][x]>0)return 0;
	}
	return 1;
}
void solve1(){
	int a2[N];
	for(int i=1;i<=n;i++)a2[i]=a[i][1];
	sort(a2+1,a2+1+n);
	for(int i=1;i<=lim;i++){
		maxx+=a2[n-i+1];
	}
}
bool cmp(int x,int y){
	return x>y;
}
void solve2(){
	int a2[N];
	for(int i=1;i<=n;i++)maxx+=a[i][1],a2[i]=a[i][2]-a[i][1];
	sort(a2+1,a2+1+n,cmp);
	for(int i=1;i<=lim;i++)maxx+=a2[i];
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		maxx=0;
		n=read();
		lim=n/2;
		for(int i=1;i<=n;i++){
			a[i][1]=read();
			a[i][2]=read();
			a[i][3]=read();
		}
		bool f2=jd(2), f3=jd(3);
		if(f2&&f3)solve1();
		else if(f3)solve2();
		else dfs(1,0,0,0,0);
		printf("%d\n",maxx);
	} 
	fclose(stdin);
	fclose(stdout);
return 0;
}

