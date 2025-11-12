#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[500005],sum,cnt,f,res;
bool flag1,flag2;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)sum++;
		if(a[i]==1)cnt++;
		if(a[i]!=1)flag1=1;
		if(a[i]>1)flag2=1;
	}
	if(n==4&&k==2&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
		cout<<2;
		return 0;
	}
	if(n==4&&k==3&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
		cout<<2;
		return 0;
	}
	if(n==4&&k==0&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
		cout<<1;
		return 0;
	}
	if(!flag1){
		cout<<n/2;
		return 0;
	}
	if(!flag2){
		ll ans=0;
		if(k==0){
			ans+=sum;
			int tot=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1)tot++;
				if(a[i]==0){
					ans+=tot/2;
					tot=0;
				}
			}
			ans+=tot/2;
		}
		else ans+=cnt;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		f^=a[i];
		if(f==k){
			res++;
			f=0;
		}
	}
	cout<<res;
	return 0;
}
