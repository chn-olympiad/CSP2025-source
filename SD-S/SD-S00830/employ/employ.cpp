#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,a[10005],b[10005];
	cin>>n>>m;
	long long k;
	cin>>k;
	long long ans=0;
	while(k!=0){
		if(k%10==1){
			ans++;
		}
		k/=10;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	long long cnt=1;
	for(int i=ans-m;i<=ans;i++){
		cnt*=i;
	}
	for(int i=1;i<=m;i++){
		cnt/=i;
	}
	cout<<cnt;
	return 0;
} 
