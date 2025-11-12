#include<bits/stdc++.h> 
using namespace std;
int arr[5050];
long long MOD=998244353;
long long ans=0;
long long n;
void dfs(long long a,long long sum,long long mx,long long ge){
	if(a==n+1){
		if(ge>=3&&sum>(mx*2)){
			ans++;
			ans%=MOD;
			return;
		}else{
			return;
		}
	}
	dfs(a+1,sum,mx,ge);
	if(arr[a]>mx){
		dfs(a+1,sum+arr[a],arr[a],ge+1);
	}else{
		dfs(a+1,sum+arr[a],mx,ge+1);
	}
}
long long zuhe(int a,int b){
	long long sum=1;
	if(b==a||b==0){
		return 1;
	}
	if(b>(a+1)/2){
		b-=((a+1)/2);
	}
	for(int i=1;i<=b;i++){
		sum=sum*a/i;
		sum%=MOD;
		a--;
	}
	return (sum%MOD);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		mx=max(mx,arr[i]);
	}
	if(mx==1){
		for(int i=3;i<=n;i++){
			ans+=zuhe(n,(n-i));
			ans%=MOD;
		}
		cout<<(ans%MOD);
		return 0;
	}
	dfs(1,0,0,0);
	cout<<(ans%MOD);
	return 0;
}

