#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long t,n,maxn;
int bj[5];
struct lisd{
	long long a,b,c;
}lis[N];
void init(){
	memset(lis,0,sizeof(lis));
	maxn=-1;
}
bool cmp(lisd aa,lisd bb){
	return aa.a>bb.a;
}
void teshuA(){
	long long q=n/2;
	stable_sort(lis+1,lis+1+n,cmp);
	long long ans=0;
	for(int i=1;i<=q;i++){
		ans+=lis[i].a;
	}
	cout<<ans<<endl;
}
void dfs(long long i,long long ans){
	if(i>n){
		if(ans>maxn) maxn=ans;
		return;
	}
	if(bj[1]<(n/2)){
		bj[1]++;
		dfs(i+1,ans+lis[i].a);
		bj[1]--;
	}
	if(bj[2]<(n/2)){
		bj[2]++;
		dfs(i+1,ans+lis[i].b);
		bj[2]--;
	}
	if(bj[3]<(n/2)){
		bj[3]++;
		dfs(i+1,ans+lis[i].c);
		bj[3]--;
	}
}
void teshuB(long long aa){
	int u[200010];
	long long po=1;
	long long sum=0;
	for(int i=1;i<=a*n;i++){
		sum+=lis[i].a;
		sum+=lis[i].b;
		u[++po]=lis[i].a;
		u[++po]=lis[i].b;
	}
	stable_sort(u+1,u+1+n);
	for(int i=1;i<=n;i++){
		sum-=u[i];
	}
	cout<<sum<<endl;
	return;
}
void Main(){
	init();
	scanf("%lld",&n);
	bool A=0,B=0;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&lis[i].a,&lis[i].b,&lis[i].c);
		if(!(lis[i].a==0 and lis[i].b==0)){
			A=1;
		}
		if(!(lis[i].c==0)){
			B=1;
		}
	}
	if(A==0){
		teshuA();
		return;
	}
	if(n<=10){
		dfs(1,0);
		cout<<maxn<<endl;
		return;
	}
	if(B==0) teshuB(1);
	else teshuB(2)
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		Main();
	}	
	return 0;
}
