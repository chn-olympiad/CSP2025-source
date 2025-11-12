#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int vis[5010];
int s[5010][5010];
unsigned long long pluss(int n){
	unsigned long long ans=0;
	for(int i=3;i<=n;i++){
		ans+=s[i][5000];
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int f1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f1=1;
	}
	if(n==3){
		if(a[1]+a[2]<=a[3]||a[1]+a[3]<=a[2]||a[2]+a[3]<=a[1]){
			cout<<0;
		}
	}
	if(!f1){
		s[0][0]=1;
		for(int i=1;i<=5000;i++){
			for(int j=1;j<=5000;j++){
				s[i][j]=s[i][j-1]+s[i-1][j-1];
			}
		}
		cout<<pluss(n)%998244353;
	}
	return 0;
}
 
