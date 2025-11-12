#include<bits/stdc++.h>
using namespace std;
int n,a[5005],vel[5005];
long long ans;
void dfs(int k,int sum,int maxn,int m){
	if(sum>maxn*2&&m>=3)ans++;
	for(int i=k;i<=n;i++){
		if(vel[i]==0){
			vel[i]=1;
			dfs(i,sum+a[i],max(maxn,a[i]),m+1);
			vel[i]=0;
		}
	}
}
long long C(int a,int b){
	int x=1,y=1,z=1;
	for(int i=1;i<=a;i++){
		x*=i;
	}
	for(int i=1;i<=b;i++){
		y*=i;
	}
	for(int i=1;i<=a-b;i++){
		z*=i;
	}
	return x/(y*z);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>=500){
		for(int i=3;i<n;i++){
			ans+=C(n,i);
		}
		cout<<ans+1;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=1;i<=n;i++){
		vel[i]=1;
		dfs(i,a[i],a[i],1);
		vel[i]=0;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
