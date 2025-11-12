#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,k;
int a[500010];
bool f=true,f_=true;

int yh(int a,int b){
	ll a_[30],b_[30],ans[30],v=0;
	int c=a,d=b,l=0,r=0;
	while(c){
		a_[++l]=c%2;
		c/=2;
	}
	while(d){
		b_[++r]=d%2;
		d/=2;
	}
	int n=max(l,r);
	for(int i=l+1;i<=n;i++)a_[i]=0;
	for(int i=r+1;i<=n;i++)b_[i]=0;
	for(int i=1;i<=n;i++){
		if(a_[i]==b_[i])ans[i]=0;
		else ans[i]=1;
	}
	for(int i=1;i<=n;i++)v+=pow(2,i-1)*ans[i];
	return v;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1){
			f_=false;
			f=false;
		}
		else if(a[i]==0)f=false;
	}
	if(f){
		if(n==1)cout<<0;
		else cout<<n/2;
	}
	else if(f_){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k)cnt++;
		}
		if(k==0){
			for(int i=1;i<n;i++){
				if(a[i]==1&&a[i+1]==1)cnt++;
			}
		}
		cout<<cnt;
	}
	else{
		int ans=0,sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				ans++;
				a[i]=-1;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==-1)sum=0;
			else{
				sum=yh(sum,a[i]);
				if(sum==k){
					ans++;
					sum=0;
				}
			}
		}
		if(sum==k)ans++;
		cout<<ans;
	}
}

