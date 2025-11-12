#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n;
int a[5010];
long long jc[5010];
int maxn=-1;
long long bookans;
void sjc(){
	jc[0]=1;
	for(int i=1;i<=n;i++){
		jc[i]=(jc[i-1]*i)%mod;
	}
}
void dfs(int x,int book,int nmax,int q){
	if(x>n){
		if(q>=3){
			if(book>2*nmax) bookans++;
		}else return;
	}else{
		dfs(x+1,book+a[x],max(nmax,a[x]),q+1);
		dfs(x+1,book,nmax,q);
	}
}
void todo1(){
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	if(sum>2*maxn) cout<<1;
	else cout<<0;
}

void todo2(){
	dfs(1,0,-1,0);
	cout<<bookans;
}
void todo3(){
	sjc();
	for(int i=3;i<=n;i++){
		long long k=(jc[i]*jc[n-i])%mod;
		bookans+=(jc[n]/k);
		bookans%=mod;
	}
	cout<<bookans;
}
void in(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
}
void pf(){
	if(n==3){
		 todo1();
	}else{
		if(maxn==1) todo3();
		else todo2();
	}		
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	in();
	pf();
	return 0;
}
