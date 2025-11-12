#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],vis[500010];
long long ans;
int main(){
  freopen("xor.in","r",stdin);
  freopen("xor.out","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=n;i++){
  	if(vis[i]==1)continue;
  	int num=a[i],t=0;
  	if(a[i]==k){
  		vis[i]=1,ans++;
  		continue;
		}
  	for(int j=i+1;j<=n;j++){
  		num=num^a[j];
			if(vis[i]==1){
				t=-1;
				break;
			}
  		if(num==k){
  			t=j;
  			break;
			}
		}
		if(t==-1)continue;
		if(num==k)ans++;
  	for(int j=i;j<=t;j++)vis[j]=1;
	}
	cout<<ans;
  return 0;
}
