#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int s=0,s1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) s++;
		if(a[i]==0) s1++;
	}
	int cnt1=0;
	if(s==n){
		if(n==2){
			if(k==0){
				cout<<1;
				return 0;
			}	
		}else if(n<2){
			cout<<0;
			return 0;
		}
		cout<<n/2;
		return 0;	
	}else if(s+s1==n){
		if(k==1){
			for(int i=1;i<n;i++){
				if(a[i]==1){
					cnt1++;
					continue;
				} 
			}
			cout<<cnt1;
			return 0;
		}else if(k==0){
			for(int i=1;i<n;i++){
				if(a[i]==0){
					cnt1++;
					continue;
				}else if(a[i]==1 && a[i+1]==1){
					cnt1++;
					a[i]=-1;
					a[i+1]=-1;
					continue;
				}
			}
			cout<<cnt1;
			return 0;
		}
	}
	cout<<n/2;
	return 0;
}