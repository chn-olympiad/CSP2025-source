#include<bits/stdc++.h>
using namespace std;
long long n,a[10005],ans;

bool ck(long long w,long long z,long long ct){
	if(ct<3) return false;
	if(z>2*a[w-1]) return true;
	return false;
}
int dfs(long long id,long long num,long long ct){
	if(id-1>n) return 0;
	if(ck(id,num,ct)){
		ans=(ans%998244353+1%998244353)%998244353;
//		cout<<"cs"<<endl;
	}
//	cout<<id<<" "<<num<<" "<<ct<<endl;;
	dfs(id+1,num+a[id],ct+1);
	dfs(id+1,num,ct);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	
	dfs(1,0,0);
	
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
