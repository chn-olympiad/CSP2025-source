#include<bits/stdc++.h>
using namespace std;
int n;
int len[5005];
int mod=998244353;
int vis[5005];
int num[5005];
int cnt=0;
bool judge1(){
	for(int i=2;i<=n;i++)if(len[i]!=len[i-1])return false;
	return true;
}
bool judge2(){
	int sum=0;
	for(int i=1;i<=n-1;i++)sum+=len[i];
	if(sum<len[n])return true;
	return false;
}
long long mi(int x,int y){
	int res=1;
	for(int i=1;i<=y;i++)res=res*x%mod;
	return res;
} 
void dfs(int deep,int Max){
	if(deep==n+1)return;
	int sum=0;
	for(int i=1;i<deep;i++){
		sum+=num[i];
	}
	if(sum>2*Max)cnt++;
	cnt%=mod;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			num[deep]=len[i];
			vis[i]=1;
			dfs(deep+1,max(Max,len[i]));
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);/**/
	cin>>n;
	for(int i=1;i<=n;i++)cin>>len[i];
	if(n==1||n==2){
		cout<<0;
		return 0;
	}
	if(judge1()){
		cout<<mi(2,n)<<endl;
		cout<<((mi(2,n))-(n+(n)*(n-1)/2)%mod-1)%mod;
		return 0;
	}
	sort(len+1,len+1+n);
	if(n==3){
		if(len[3]<len[1]+len[2])cout<<1;
		else cout<<0;
		return 0;
	}
	if(n<=10){
		dfs(1,0);
		cout<<cnt;
		return 0;
	}
	if(judge2()){
		cout<<0;
		return 0;
	}
	for(int m=3;m<=n;m++){
		
	}
	return 0;
}
