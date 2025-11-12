#include<bits/stdc++.h>
using namespace std;
const int p=313;
int mod=1e9+9;
char s1[200010],s2[200010];
char t1[200010],t2[200010];
long long c1[200010],c2[200010];
int pw(long long x,int k){
	long long sum=1;
	while(k>0){
		if(k%2==1) sum=sum*x%mod;
		x=x*x%mod;
		k/=2; 
	}
	return sum;
}
map<int,int>mp,mp2;
int tot=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		scanf("%s%s",s1+1,s2+1);
		int len=strlen(s1+1);
		cout<<len<<endl;
		int sum1=0,sum2=0;
		for(int j=1;j<=len;j++){
			sum1=(1ll*sum1*p+s1[j])%mod;
		}
		for(int j=1;j<=len;j++){
			sum2=(1ll*sum2*p+s2[j])%mod;
		}
		mp[sum1]=sum2;
	}
	while(q--){
		scanf("%s%s",t1+1,t2+1);
		int len=strlen(t1+1);
		if(len!=strlen(t2+1)){
			cout<<0<<endl;
		}else{
			c1[0]=c2[0]=0;
			for(int i=1;i<=len;i++){
				c1[i]=(c1[i-1]*p+t1[i])%mod;
				c2[i]=(c2[i-1]*p+t2[i])%mod;
			}			
			int ans=0;
			for(int l=1;l<=len;l++){
				for(int r=l;r<=len;r++){
					long long a=(c1[r]-c1[l-1])*pw(pw(p,mod-2),l)%mod;
					long long b=(c2[r]-c2[l-1])*pw(pw(p,mod-2),l)%mod;
					if(mp[a]==b) ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 
