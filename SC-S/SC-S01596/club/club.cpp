#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		vector<int>ka,kb,kc;int sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int a,b,c;cin>>a>>b>>c;
			if(a>b&&a>c)ka.push_back(a-max(b,c)),sum+=a;
			else if(b>a&&b>c)kb.push_back(b-max(a,c)),sum+=b;
			else if(c>b&&c>a)kc.push_back(c-max(b,a)),sum+=c;
			else sum+=max(a,max(b,c));
		}
		if(ka.size()<=n/2&&kb.size()<=n/2&&kc.size()<=n/2)cout<<sum<<'\n';
		else{
			if(ka.size()>n/2){
				sort(ka.begin(),ka.end());
				for(int i=0;i<ka.size()-n/2;i++)sum-=ka[i];
				cout<<sum<<'\n';
			}
			else if(kb.size()>n/2){
				sort(kb.begin(),kb.end());
				for(int i=0;i<kb.size()-n/2;i++)sum-=kb[i];
				cout<<sum<<'\n';
			}
			else if(kc.size()>n/2){
				sort(kc.begin(),kc.end());
				for(int i=0;i<kc.size()-n/2;i++)sum-=kc[i];
				cout<<sum<<'\n';
			}
		}
	}
	return 0;
}