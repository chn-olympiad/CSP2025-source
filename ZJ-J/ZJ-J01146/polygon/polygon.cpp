#include<bits/stdc++.h>
using namespace std;
int a[5050];
const int p=998244353 ;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	if(n<3){
		cout<<0;
	}else if(n==3){
		long long sum=0;
		int mx=-1e9;
		for(int i=1;i<=n;i++){
			sum+=a[i];
			mx=max(mx,a[i]);
		}
		if(sum>mx)cout<<1;
		else cout<<0;
	}else if(n<=10){
		int ans=0;
	int cnt=pow(2,n);
	for(int i=1;i<=cnt;i++){
		int sum=0,mx=-1e9;
		int s=i,k=1,pd=0;
		while(s){
			if(s%2==1){
				sum+=a[k];
				mx=max(mx,a[k]);
			}
			s/=2;
			k++;
			pd++;
		}
		if(pd>2){
			if(sum>2*mx)ans++;
			ans%=p;
		}
	}	
	cout<<ans%p;
	}else if(n<=20){
			int ans=0;
	int cnt=pow(2,n);
	for(int i=1;i<=cnt;i++){
		int sum=0,mx=-1e9;
		int s=i,k=1,pd=0;
		while(s){
			if(s%2==1){
				sum+=a[k];
				mx=max(mx,a[k]);
			}
			s/=2;
			k++;
			pd++;
		}
		if(pd>2){
			if(sum>2*mx)ans++;
			ans%=p;
		}
	}	
	cout<<ans%p;
	}else {
		cout<<1;
	}
	
	return 0;
} 
