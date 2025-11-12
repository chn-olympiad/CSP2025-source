#include <bits/stdc++.h>
using namespace std;
int a[5004];
int d[5004];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long s=0;
	int n;
	cin>>n;
	
	cin>>a[1];
	int k=a[1];
	int f=1;
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]!=k)f=0;
	}
	if(f){
		long long y=1;
		
		for(int i=1;i<=n;i++){
			y*=2;
			y%=998244353;
		}
		y+=998244353;
		y-=n*(n-1)/2;
		y-=n+1;
		cout<<y%998244353;
		return 0;
	}
	
	if(n<=20){
		for(int i=0;i<(1<<n);i++){
			int m=0;
			int ss=0;
			for(int j=0;j<n;j++){
				
				if((1<<j)&i){
					
					ss+=a[j+1];
					m=max(m,a[j+1]);
				}
			}
			
			if(ss>m*2){
				s++;
				s%=998244353;
			}
			
		}
		cout<<s%998244353;
		return 0;
	}
	else{
		
		for(int i=0;i<((long long)1<<n);i++){
			int m=0;
			int ss=0;
			for(int j=0;j<n;j++){
				
				if((1<<j)&i){
					
					ss+=a[j+1];
					m=max(m,a[j+1]);
				}
			}
			
			if(ss>m*2){
				s++;
				s%=998244353;
			}
			
		}
		cout<<s%998244353;
		return 0;
	}
	
}