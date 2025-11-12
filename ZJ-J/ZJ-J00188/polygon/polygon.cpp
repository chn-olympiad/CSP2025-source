#include<bits/stdc++.h>
using namespace std;
long long cnt=0;
int a[1000010];
long long n;
bool p[10000010]={};
void dfs(int sum,int k){
	if(sum>2*a[k]){
		cnt++;
	}
	for(int i=k;i<=n;i++){
		if(!p[i]){
			p[i]=1;
			dfs(sum+a[i],i);
			p[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(0,1);
	cout<<cnt;
}
