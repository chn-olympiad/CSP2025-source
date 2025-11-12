#include<bits/stdc++.h>
using namespace std;
int n,k,lis[550000],ans;
bool vis[550000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>lis[i];
		if(lis[i]==k){
			vis[i]=1;ans++;
		}
	}int pre=0,res=0;
	for(int i=0;i<n;i++){
		if(!vis[i]){
			res^=lis[i];
			if(res==k){
				ans++;pre=i+1;res=0;
			}else{
				int res1=res;
				for(int j=pre;j<i;j++){
					res1^=lis[j];
					if(res1==k){
						ans++;pre=i+1;res=0;
					}
				}
			}
		}else{
			pre=i+1;res=0;
		}
	}
	cout<<ans;
	return 0;
}