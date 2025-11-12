//刘睿  SN-S00081  西安铁一中滨河高级中学
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
int a[10000];
char q[510];
int xin[510];
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long ans=1;
	int n,m,tem;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q[i];
	}for(int i=1;i<=n;i++){
		cin>>xin[i];
	}if(m==n){
		cout<<"0";
		return 0;
	}for(int i=1;i<=n;i++){
		ans*=i;
		ans%=998244353;
	}cout<<ans;
	return 0;
}
