#include<bits/stdc++.h> 
using namespace std;
const int N=5e5+10;
int arr[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int mx=0;
	int mi=1e9;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		mx=max(mx,arr[i]);
		mi=min(mi,arr[i]);
	}
	if(k==0&&mx==1&&mi==1){
		cout<<n/2;
		return 0;
	}
	if(k<=1&&mx==1){
		if(k==1){
			long long sum=0;
			for(int i=1;i<=n;i++){
				if(arr[i]==1){
					sum++;
				}
			}
			cout<<sum;
			return 0;
		}
		if(k==0){
			long long sum=0;
			int f=0;
			for(int i=1;i<=n;i++){
				if(arr[i]==0){
					sum++;
				}
				if(arr[i]==1&&f==0){
					if(arr[i+1]==1){
						sum++;
						f=1;
						continue;
					}
				}
				if(f==1){
					f=0;
				}
			}
			cout<<sum;
			return 0;
		}
	}
	return 0;
}
