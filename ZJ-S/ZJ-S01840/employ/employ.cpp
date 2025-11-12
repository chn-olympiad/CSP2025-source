#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
const int mod=998244353;
string s;
int n,m,sum,p[N],a[N],b[N],ans;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++) sum+=(int)(s[i]-'0');
	p[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=p[i-1]*i%mod;
	}
	sort(a+1,a+1+n);
	if(m==1){
		m=s.find('1')+1;int cnt=0;
		for(int i=0;i<n;i++) if(s[i]=='1') b[++cnt]=i+1;
		int f=1;
		for(int i=1;i<=sum;i++){
			int id=b[i];
			int l=0,r=n,c=n+1;
			while(l<=r){
				int mid=(l+r)>>1;
				if(a[mid]>=id) r=mid-1,c=min(c,mid);
				else l=mid+1;
			}
			ans=(ans+(n-c+1)*p[n-i]%mod*f%mod)%mod;
			f=f*(c-i)%mod;
		}
		cout<<ans;
	}
		int ans=1;
		if(sum!=n || a[1]==0) {cout<<0;return 0;}
		cout<<p[n];
	return 0;
}
