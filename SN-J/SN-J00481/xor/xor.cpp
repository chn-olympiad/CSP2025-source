#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,k;
long long a[N];
bool b[N];
bool exchange;
int ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(b,false,sizeof(b));
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			exchange=false;
			break;
		}
	}
	if(k==1)
	{
		if(exchange){
			cout<<n;
			return 0;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==1)
				{
					ans++;
				}
			}	
			cout<<ans;
			return 0;
		}
	}else
	{
		if(exchange){
			cout<<n/2;
			return 0;
		}else{
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
				}
			}
			for(int i=1;i<=n;i++){
				if(a[i]==1&&!b[i]){
					if(a[i+1]==1){
						b[i+1]=true;
						ans++;
					}
				}
			}
			cout<<ans;
			return 0;
		}
	}
}
