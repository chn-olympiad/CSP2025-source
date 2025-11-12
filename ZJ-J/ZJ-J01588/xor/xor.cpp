#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,k,ans,cnt1,cnt0,zc,a[500010],c[500010];
bool vis[500010],flag,B=1,X=1;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(zc==0)zc=c[i];
		if(c[i]!=zc)X=0;
		if(c[i]>1)B=0;
		if(B){
			if(c[i]==1){
				cnt1++;
				if(flag){
					cnt0++;
					flag=0;
				}
				else{
					flag=1;
				}
			}
			else{
				cnt0++;
				flag=0;
			}
		}
		a[i]=a[i-1]^c[i];
	}
	if(B){
		if(k==1)cout<<cnt1<<endl;
		else cout<<cnt0<<endl;
		return 0;
	}
	if(X){
		if(k==0)cout<<n/2<<endl;
		else if(k==zc)cout<<n<<endl;
		else cout<<"0"<<endl;
		return 0;
	}
	flag=0;
	for(int len=1;len<=n;len++){
		for(int l=1;l<=n&&(l+len-1)<=n;l++){
			flag=0;
			for(int i=l;i<l+len;i++){
				if(vis[i]){
					flag=1;
					break;
				}
			}
			if(flag)continue;
			if((a[l+len-1]^a[l-1])==k){
				ans++;
				for(int i=l;i<l+len;i++)vis[i]=1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}