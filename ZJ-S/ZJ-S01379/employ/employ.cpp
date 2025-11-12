#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m;
int ca,ls;
int mx,to;
int s[505],c[505];
char sc;
void over(){
	fclose(stdin);
	fclose(stdout);
	exit(0);
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	ca=to=1;
	for(int i=1;i<n;i++){
		to*=i;
		to%=mod;
	}
	mx=(to*n)%mod;
	for(int i=1;i<=n;i++){
		cin>>sc;
		s[i]=sc-'0';
		ca&=s[i];
		ls+=(s[i]==0);
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(ca){
		cout<<mx<<'\n';
		over();
	}
	if(m>n-ls){
		cout<<0;
		over();
	}
	if(m==1){
		int r,ans=0;
		for(r=1;r<=n;r++){
			if(s[r]==1)break;
		}
		r--;
		for(int i=1;i<=n;i++){
			if(c[i]>=r){
				ans+=to;
				ans%=mod;
			}
		}
		cout<<ans<<'\n';
		over();
	}
	if(n<=10){
		int a[15],ans=0;
		for(int i=1;i<=n;i++){
			a[i]=i;
		}
		do{
			int t=0,cnt=0;
			for(int i=1;i<=n;i++){
				if(c[a[i]]<t||s[i]==0){
					t++;
				}
				else{
					cnt++;
				}
			}
			if(cnt>=m){
				ans++;
			}
		}while(next_permutation(a+1,a+n+1));
		cout<<(ans%mod)<<'\n';
		over();
	}
	over();
}
