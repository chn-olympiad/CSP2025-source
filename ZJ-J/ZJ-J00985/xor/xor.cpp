#include <bits/stdc++.h>

using namespace std;
long long n,k;
const int N=5e5+5;
int a[N];
int sum[N];
bool vis[N];
long long ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			sum[i]=a[i];
		}
		else{
			sum[i]=a[i]^sum[i-1];
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=1;j<=n-i;j++){
//			cout<<sum[j-1]<<' '<<sum[j+i]<<endl;0
			bool f=0;
			for(int t=j;t<=j+i;t++){
				if(vis[t]){
					f=1;
					break;
				}
			}
			if(f){
				continue;
			}
			if(j==1){
				if(sum[j+i]==k){
					for(int p=j;p<=j+i;p++){
						vis[p]=1;
						
						
					}
//					cout<<a[i+j]<<endl;
					ans++;
				}
			}
			else{
				if((sum[j+i]^sum[j-1])==k){
					for(int p=j;p<=j+i;p++){
						vis[p]=1;			
					}
//					cout<< (sum[j-1]^sum[j+i]) <<endl;
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

