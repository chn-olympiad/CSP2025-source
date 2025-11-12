#include<bits/stdc++.h>
using namespace std;
int n,ans=0,k;
long long a[500005][22];
int twot(int o){
	int p=1;
	while(o=0){
		if(n%2==1){
			a[o][p]++;
			n-=1;
		}else{
			a[o][p]=0;
		}
		if(n/2>0){
			n/=2;
			p++;
		}
	}
}
int huoy(int l,int r){
	int b[20],m=0;
	for (int i=l;i<=r;i++){
		for (int j=1;j<=20;j++){
			b[j]+=a[i][j];
		}
	}
	for (int i=1;i<=20;i++){
		if(b[i]%2==1){
			b[i]=0;
			int e=1;
			for (int j=1;j<=i;j++){
				e*=2;
			}
			m+=e;
		}else{
			b[i]=0;
		}
	}
	return m;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i][0];
	}
	for (int i=1;i<=n;i++){
	    twot(a[i][0]);
	}
	for (int l=1;l<=n;l++){
		for(int r=n;r>=1;r--){
			int g=huoy(l,r);
			if(g==k){
				cout<<r-l;
				return 0;
			}
		}
	}
	cout<<0;
	return 0;
}
