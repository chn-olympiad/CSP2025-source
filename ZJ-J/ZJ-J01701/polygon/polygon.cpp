#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int Mod=998244353;
int a[N];
bool cmp(int a,int b){
	return a<b;
}
int sum[N];
bool vis[N];
long long cnt;
int n;
void f(int sum,int x,int la,int k){
	if(cnt>=1042392){
		return ;
	}
	
	if(x<2){
		return;	
	}
	cnt=(cnt+1)%Mod;
	for(int i=la;i<=n;i++){
		if(sum-a[i]<=k){
			break;
		}
		if(vis[i])continue;
		vis[i]=true;
		f(sum-a[i],x-1,i+1,k);
		vis[i]=false;
	} 
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=n;i>=1;i--){
		int num=sum[i-1];
		if(num<=a[i])continue;
		vis[i]=true;
		f(num,i-1,1,a[i]);
		vis[i]=false;
	}
	cout<<cnt;
	return 0;
}
