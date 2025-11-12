#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	long long int n,k;
	int cnt=0;
	cin>>n>>k;
	
	long long int a[n];
	bool f1=1;
	for(long long int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f1=0;
		}
	}
	if(k==0){
		if(f1){
			cout<<n/2;
		}else{
			int cnt=0;
			for(int i=0;i<n;i++){
				if(a[i]==0){
					cnt++;
				}else if(a[i]==1 && a[i+1]==1){
					cnt++;
					a[i+1]=-1;
				}
			}
			cout<<cnt;
		}
	}else if(k==1){
		int cnt=0;
		for(int i=0;i<n;i++){
			if(a[i]==1){
				cnt++;
			} 
		}
		cout<<cnt;
	}
	
	return 0;
} 
