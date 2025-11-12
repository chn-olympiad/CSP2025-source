#include <bits/stdc++.h>
using namespace std;
int ejz(int y){
	int s[10000],i=0,x=y;
	while(x>0){
		i++;
		s[i]=x%2;
		x/=2;
	}
	int ans=0;
	for(int j=i; j>=1; j--){
		ans=ans*10+s[j];
	}
	return ans;
}
int zje(int y){
	int x=y,i=0,s[10000];
	while(x>=10){
		i++;
		s[i]=x%10;
		x/=10;
	}
	i++;
	s[i]=x%10;
	x/=10;
	int ans=s[1],c=1;
	for(int j=2; j<=i; j++){
		c*=2;
		ans=ans+s[j]*c;
	}
	return ans;
}
int yhh(int a,int b){
	int i=0,s[10000];
	int sum=ejz(a)+ejz(b);
	while(sum>=10){
		i++;
		s[i]=sum%10;
		sum/=10;
	}
	i++;
	s[i]=sum%10;
	sum/=10;
	for(int j=1; j<=i; j++){
		if(s[j]!=0) s[j]=1;
	}
	int ans=0;
	for(int j=1; j<=i; j++){
		ans=ans*10+s[j];
	}
	return zje(ans);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[50005];
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		hh+=a[i];
	}
	if(k==0){
		cout<<hh;
		return 0;
	}
	int ans=0;
	int f[500][500];
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			f[i][j]=yhh(f[i][j-1],a[i]);
			if(f[i][j]==k) ans++; 
		}
	}
	cout<<ans-2;
	return 0;
}
