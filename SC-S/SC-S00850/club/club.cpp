#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n;
struct St{
	ll a,b,c;
	ll id;//理想中去的部门 
}a[100005];
ll f,f1,k;
ll s[100005];
bool cmp1(St a,St b){
	return a.a>b.a;
}
ll cnt[4],ans;
void dfs(ll idx){
	if(idx==n+1){
		ll sum1=0;
		for(ll i=1;i<=n;i++){
			if(s[i]==1) sum1+=a[i].a;
			else if(s[i]==2) sum1+=a[i].b;
			else sum1+=a[i].c; 
		}
		ans=max(ans,sum1);
		return;
	}
	for(ll i=1;i<=3;i++){
		if(cnt[i]+1<=k){
			s[idx]=i;
			cnt[i]++;
			dfs(idx+1);
			cnt[i]--; 
		}
	}
}
ll dp[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		f=1,f1=1;
		cnt[1]=cnt[2]=cnt[3]=0;
		ans=0;
		for(ll i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].id=i;
			if(a[i].b>0 or a[i].c>0) f=0;
			if(a[i].c>0) f1=0; 
		}
		k=n/2;
		if(f==1){
			sort(a+1,a+1+n,cmp1);
			for(ll i=1;i<=k;i++) ans+=a[i].a;
			cout<<ans<<"\n";
		}
		else if(n<=10){
			dfs(1);
			cout<<ans<<"\n";
		}
		else{
			for(ll i=1;i<=n;i++){
				if(a[i].a>a[i].b and a[i].a>a[i].c){
					if(cnt[1]+1<=k){
						cnt[1]++;
						ans+=a[i].a;
					}
					else{
						if(cnt[2]+1<=k and cnt[3]+1>k){
							cnt[2]++;
							ans+=a[i].b;
						}
						else if(cnt[3]+1<=k and cnt[2]+1>k){
							cnt[3]++;
							ans+=a[i].c;
						}
						else{
							if(a[i].b>a[i].c){
								cnt[2]++;
								ans+=a[i].b;
							}
							else{
								cnt[3]++;
								ans+=a[i].c;
							}
						}
					}
				}
				else if(a[i].b>a[i].a and a[i].b>a[i].c){
					if(cnt[2]+1<=k){
						cnt[2]++;
						ans+=a[i].b;
					}
					else{
						if(cnt[1]+1<=k and cnt[3]+1>k){
							cnt[1]++;
							ans+=a[i].a;
						}
						else if(cnt[3]+1<=k and cnt[1]+1>k){
							cnt[3]++;
							ans+=a[i].c;
						}
						else{
							if(a[i].a>a[i].c){
								cnt[1]++;
								ans+=a[i].a;
							}
							else{
								cnt[3]++;
								ans+=a[i].c;
							}
						}
					}
				}
				else if(a[i].c>a[i].b and a[i].c>a[i].a){
					if(cnt[3]+1<=k){
						cnt[3]++;
						ans+=a[i].c;
					}
					else{
						if(cnt[2]+1<=k and cnt[1]+1>k){
							cnt[2]++;
							ans+=a[i].b;
						}
						else if(cnt[1]+1<=k and cnt[2]+1>k){
							cnt[1]++;
							ans+=a[i].a;
						}
						else{
							if(a[i].a>a[i].b){
								cnt[1]++;
								ans+=a[i].a;
							}
							else{
								cnt[2]++;
								ans+=a[i].b;
							}
						}
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}