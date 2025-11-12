#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],f[500001],l,r,ans,ans1,ans2,s;
bool b,p,h[500001];
int dfs(int x){
	if(f[x]!=0){
		return f[x];
	}
	int m;
	for(int i=x+1;i<=n;i++){
		m=1;
		for(int j=i;j<=n;j++){
			m=m^a[j];
			if(m==k){
				f[x]=max(f[x],dfs(j)+1);
			}
		}
	}return f[x];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;b=1;p=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)b=0;
		if(a[i]>=2)p=0;
		if(a[i]==1)ans++;
		if((a[i]==1&&a[i-1]==1&&h[i-1]==0&&h[i]==0)||a[i]==0){
			h[i]=1;h[i-1]=1;ans2++;
		}
	}if(k==0&&b){
		cout<<n;
	}else if(k==1&&p){
		cout<<ans;
	}else if(k==0&&p){
		cout<<ans2;
	}else if(n<=1e3){
		cout<<dfs(0);
	}else{
		for(int i=1;i<=n;i++){
			s=1;
			for(int j=i;j<=n;j++){
				s=s^a[j];
				if(s==k){
					ans1++;
					i=j;
					break;
				}
			}
		}cout<<ans1;
	}
	
	return 0;
}

