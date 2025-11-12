#include<bits/stdc++.h>
using namespace std;
const int N=10e2+5;
int a[N][N],t[N],kk[N];
int n,k,maxn=0,tans=0,Max=0;
void back(int l,int r){
	int s=0;
	while(r<n){
		bool t=true;
		for(int j=1;j<=maxn;j++){
			if((a[r][j]-a[l-1][j])%2!=kk[j]) t=false;
		}
		if(t){
			s++;
			l=r-1;
		}
		tans=max(tans,s);
		r++;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>t[i];
	for(int i=1;i<=n;i++){
		int m=0;
		while(t[i]){
			m++;
			a[i][m]=t[i]%2;
			t[i]/=2;
		}
		maxn=max(maxn,m);
	}
	int m=0;
	while(k){
		m++;
		kk[m]=k%2;
		k/=2;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=maxn;j++){
			a[i][j]=a[i][j]+a[i-1][j];
		}
	}
	for(int i=0;i<n-1;i++){
		back(i,i+1);
	}
	cout<<tans;
	return 0;
}