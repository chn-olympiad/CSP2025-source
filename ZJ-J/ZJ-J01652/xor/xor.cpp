#include <bits/stdc++.h>

using namespace std;
const int N=5e5+5;
int a[N];
int sum[N]={};
int b[N];
int n,k;
int cnt0=0,cnt1=0;
int mx=-1;
map<int,int> mp;
void dfs(int s,int cnt,int sum){
	if(s==n+1){
		mx=max(mx,cnt);
		return ;
	}
	if(sum^a[s]==k){
		dfs(s+1,cnt+1,0);
	}
	else {
		dfs(s+1,cnt,sum^a[k]);
		dfs(s+1,cnt,sum);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		cnt0+=(a[i]==0);
		cnt1+=(a[i]==1);
		sum[i]=sum[i-1]^a[i];
		mp[a[i]]++;
	}
	sort(b+1,b+1+n);
	if(b[1]==b[n]&&b[1]==1){
		if(k!=0&&k!=1){
			cout<<0;
			return 0;
		}
		if(k==0){
			cout<<n/2;
			return 0;
		}
		if(k==1){
			cout<<n;
			return 0;
		}
	}
	if(b[1]==0&&b[n]==1){
		if(k==0){
			int ans=0;
			int i=1;
			int cnt=0;
			while(i<=n){
				if(a[i]==1){
					cnt++;
				}else{
					ans+=cnt/2;
					cnt=0;
				}
				i++;
			}
			ans+=cnt/2;
			cout<<ans+cnt0;
			return 0;
		}
		if(k==1){
			cout<<cnt1;
			return 0;
		}
	}
	if(b[1]==0&&b[n]==0){
		if(k==0){
			cout<<n;
			return 0;
		}
		if(k!=0){
			cout<<0;
			return 0;
		}
	}
	if(b[1]==b[n]){
		if(k==0){
			cout<<n/2;
			return 0;
		}
		if(k==b[1]){
			cout<<n;
			return 0;
		}
		cout<<0;
		return 0;
	}
	if(k==0){
		int ans=0;
		int i=1;
		int cnt=1,nx=a[1];
		while(i<=n){
			if(a[i]!=nx){
				ans+=cnt/2;
				i=i+2;
				nx=a[i];
				cnt=1;
				continue;
			}
			if(i==0){
				ans++;
			}
			if(a[i]==nx){
				cnt++;
			}
			i++;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<mx;
	return 0;
}
