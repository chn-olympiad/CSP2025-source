#include<bits/stdc++.h>
using namespace std;
const int N=105;
int ans,ansx,ansy;
int a[N];
int s=1;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		scanf("%d",&a[i]);
		if(a[i]>a[1]) ++s;
	}
	int k;
	k=s/n;
	if(s%n==0){
		ansx=k;
		if(k%2==0){
			ansy=1;
		}
		else ansy=n;
	}
	else{
		++k;
		int mod=s%n;
		if(k%2==0){
			ansx=k;
			ansy=n+1-mod;
		}
		else{
			ansx=k;
			ansy=mod;
		}
	}
	cout<<ansx<<" "<<ansy;
	return 0;
}
