#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod=998244353;
int n,m,ans;
string s;
vector<int>rq;
vector<int>c;
vector<int>p;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	c.resize(n+1);
	cin>>s;
	rq.resize(n+1);
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0'){
			rq[i]=0;
		}
		else rq[i]=1;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	p.resize(n);
	for(int i=0;i<n;i++){
		p[i]=i+1;
	}
	vector<int>p2=p;
	do{
		int res=0,fq=0;
		for(int i=0;i<n;i++){
			if(rq[i+1]==0||fq>=c[p[i]]){
				fq++;
			}
			else {
				res++;
			}
		}
		if(res>=m){
			ans++;
			ans%=mod;
		}
		next_permutation(p.begin(),p.end());
	}while(p!=p2);
	cout<<ans<<endl;
}
