#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
const int mod=998244353;
bool flag=true;
int n,m,ccnt;
string s;
vector<int> a,b,xs;
map<int,int> mp;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>s;
	a.resize(n+1);
	b.resize(n+1);
	xs.resize(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<s.length();i++){
		if(s[i]=='1'){
			xs[i+1]=xs[i];
			ccnt++;
		}
		else {
			flag=false;
			xs[i+1]=xs[i]+1;
		}
	}
	if(ccnt<m){
		cout<<0<<endl;
		return 0;
	}
	if(flag){
		long long ans=1;
		for(int i=2;i<=n;i++)ans=(ans*i)%mod;
		cout<<ans<<endl;
	}else if(m==1){
		sort(a.begin()+1,a.end());
		int x=a[1],cnt=0;
		for(int i=0;i<=n;i++){
			if(xs[i]>=x)break;
			else cnt++;
		}
		long long ans=n-cnt;
		for(int i=2;i<=n-1;i++)ans=(ans*i)%mod;
		cout<<ans<<endl;
	}else {
		sort(a.begin()+1,a.end());
		for(int i=1;i<=n;i++){
			int j;
			if(i==1)j=0;
			else j=b[i-1];
			for(;j<=n;j++){
				if(xs[j]>=a[i]){
					j--;
					break;
				}
			}
			b[i]=j;
		}
		int cnt=0;
		for(int i=0;i<n;i++)
			if(s[i]=='1'&&i<=b[n])cnt++;
		if(cnt<=m){
			cout<<0<<endl;
			return 0;
		}
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*(b[i]-i+1));
		}
	}
	return 0;
}
