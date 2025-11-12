#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],k,f=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) f=2;
	}
	if(f==1){
		if(k==1) cout<<n;
		else if(k==0) cout<<n/2;
		else cout<<0;
	}
	if(f==2){
		if(k==1){
			int sum=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) sum++;
			}
			cout<<sum;
		}
		else if(k==0){
			int sum=0;
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					sum+=cnt/2; 
					cnt=0;
					sum++;
				}
				if(a[i]==1){
					cnt++;
				}
			}
			sum+=cnt/2; 
			cout<<sum;
		}
		else{
			cout<<0;
		}
	}
	return 0;
} 
