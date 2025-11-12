#include<bits/stdc++.h>
using namespace std;
int cnt = 0,a1[1001] = { },a2[1001] = { };
int n;
int a[1001];
bool check(int n){
	int ans = 0,maxn = 0;
	for(int i = 1;i<=n;i++){
		ans+=a1[i];
		maxn = max(a1[i],maxn);
	}
	if(ans>2*maxn){
		return true;
	}
	else{
		return false;
	}
}
int dfs(int d,int n1,int a1[1001],int a2[1001]){
	if(d == n1+1&&check(n1)){
		cnt++;
		return 0;
	}
	for(int i = 1;i<=n;i++){
		if(a2[i] ==0){
			a2[i] = 1;
			a1[d] = a[i];
			d+=1;
			dfs(d,n1,a1,a2);
			a2[i] = 0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i= 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i= 3;i<=n;i++){
		dfs(1,i,a1,a2);
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
