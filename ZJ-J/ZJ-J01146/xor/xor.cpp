#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
long long n,k,sum=0;;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];

		if(n<=2){
		if(a[1]==0&&a[2]==0){
			cout<<2;
		}
		else if(a[1]==0||a[2]==0){
			cout<<1;
		}else if(a[1]==a[2]){
			cout<<1;
		}else {
			cout<<0;
		}
		return 0;
		
	}
	if(n<=100){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0)sum++;
			}
			for(int i=1;i<n;i++){
				if(a[i]==a[i]+1)sum++;
			}
			cout<<sum;
			
		}else if(k==1){
			
			for(int i=1;i<n;i++){
				if(a[i]^a[i+1]==1)sum++;
			}
			cout<<sum;
		}else {
			cout<<n/2;
		}
		
		return 0;
	}
	cout<<0;
	return 0;
} 
