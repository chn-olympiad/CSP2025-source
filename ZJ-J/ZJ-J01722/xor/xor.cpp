#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5*5+10;
int n,k,i,t,w,sum,ans,a[N],ans1,ma;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
		freopen("xor.in","r",stdin);
		freopen("xor.out","w",stdout);
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==1) ans++;
			ma=max(ma,a[i]);
		}
		if(ans==n){
			if(k==0) cout<<n/2;
			else if(k==1) cout<<n;
			else cout<<0;
			return 0;
		}
		if(ma==1){
			if(k>1)cout<<0;
			if(k==0){
				for(int i=1;i<<=n;i++)
					if(a[i]==1&&a[i+1]==1)
						sum++,a[i]=a[i+1]=0;
				cout<<sum+n-ans;
			}
			if(k==1) cout<<ans;
			return 0;
		}
		t=1;w=1;
		sum=a[t];
		while(t<=n&&w<=n&&t<=w){
			if(t==w&&a[t]==k){
				ans1++;t++;w++;
			}
			else if(t==w&&a[t]!=k) w++;
			else if(t<w){
				sum^=a[w];
				if(sum==k) ans1++,t=w+1,w=t,sum=a[t];
				else if(sum>k) t++;
				else w++;
			}
		}
		cout<<ans1;
		return 0;
}