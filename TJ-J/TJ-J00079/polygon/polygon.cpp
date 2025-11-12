#include<bits/stdc++.h>
using namespace std;
const int MX=6029;
long long a[MX],b[MX];
const int modr=998244353;
int z;
int t;
deque<int>d;
void dfs(int r,int k,int x,int b){
	int dd=x;
	if(x>=k){
		if(t>b){
			z++;
		}
		return ;
	}
	for(int i=x;i<=r-k+x+1;i++){
		if(i==0)continue; 
		if(x>0&&a[i]<=d.back())continue;
		t+=a[i];
		d.push_back(a[i]);
		dfs(r,k,x+1,b);
		t-=a[i];
		d.pop_back();
	}
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=n;i>=3;i--){
		for(long long j=i-1;j>=2;j--){
		 	dfs(i-1,j,0,a[i]);
		}
	}
	cout<<z;
	return 0;
} 
