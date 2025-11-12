#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],b[25][N],c[25][N],dp[N],m,ans,ma;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,K;
	cin>>n>>K;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x=0;
		for(int j=i;j>=1;j--){
			x^=a[j];
			if(x==K){
				dp[i]=j;
				break;
			}
		}
	}
	int l=0;
	for(int i=1;i<=n;i++){
		if(dp[i]!=0 && dp[i]>l){
			ans++;
			l=i;
		}
	}
	cout<<ans;
	
}
/*
4 0
2 1 0 3
4 2
2 1 0 3
4 3
2 1 0 3


*/
