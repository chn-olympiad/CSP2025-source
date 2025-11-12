#include<bits/stdc++.h>
using namespace std;
int n,m,s[1000],k[1000],cnt[1000],c[1000];
string s1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	int f=n;
	cin>>s1;
	for(int i=0;i<n;i++){
		s[i+1]=s1[i]-'0';
		if(!s[i+1]) f--;
	}
	if(m==n){
		if(f==n){
			long long ans=1;
			for(int i=n;i>=2;i--){
				ans*=i%998244353;
				ans%=998244353;
			}
			cout<<ans;
		}else cout<<0;
		return 0;
	}
	if(m>f){
		cout<<0;
		return 0;
	} 
	if(f==n){
		long long ans=1;
		for(int i=0;i<m;i++){
			ans*=(n-i)%998244353;
			ans%=998244353;
		}
		cout<<ans;
		return 0;	
	}
	if(f==0){
		cout<<0;
		return 0;
	}
	if(m==1&&f>=1){
		int j=0;
		for(int i=1;i<=n;i++){
			if(s[i]) k[++j]=i;
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&c[i]);
		}
		long long ans1=0;
		for(int i=1;i<=j;i++){
			int cnt=0;
			for(int z=1;z<=n;z++){
				if(c[z]>=k[i]) cnt++;
			}
			long long ans=1;
			for(int z=n;z>=2;z--){
				if(z==k[i]){
					ans*=min(z,cnt)%998244353;
					ans%=998244353;
				}
				ans*=z%998244353;
				ans%=998244353;
			}
			ans1+=ans;
		}
		cout<<ans1;
	}
	return 0;
}

