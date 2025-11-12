#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const long long mod=998244353;
int m,n,a[510],ord[20],dif[510],sum;
long long k=1;
string s; 
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i],k=(k*i)%mod;
	for(int i=1;i<=n;i++)dif[i]=(s[i-1]=='1'),sum+=dif[i];
	if(sum==n)cout<<k;
	else if(sum==0)cout<<0;
	else if(m==n){
		if(sum==n)cout<<k;
		else cout<<0;
	}else if(m==1){
		int pos=0;
		for(int i=1;i<=n;i++){
			if(dif[i]==1){
				pos=i;
				break;
			}
		}
		if(!pos)cout<<0;
		else{
			pos--;
			int cnt=0;
			for(int i=1;i<=n;i++)if(a[i]>pos)++cnt;
			long long res=1;
			for(int i=1;i<=n-1;i++)res=(res*i)%mod;
			cout<<(res*cnt)%mod;
		}
	} 
	else if(n<=10){
		for(int i=1;i<=n;i++)ord[i]=i;
		int ans=0;
		do{
			int cnt=0,die=0;
			for(int i=1;i<=n;i++){
				if(a[ord[i]]>die&&dif[i]){
					++cnt;
				}else{
					die++;
				}
				if(cnt>=m){
					ans++;
					break;
				}
			}
		}while(next_permutation(ord+1,ord+n+1));
		cout<<ans;
	}else{
		cout<<0;
	}
	return 0;
}
