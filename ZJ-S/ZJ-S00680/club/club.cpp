#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=1e5+9;
int T,n,a[N],b[N],c[N];
int main(){freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		vector<int>va,vb,vc;
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];int mx=max(a[i],max(b[i],c[i]));
			ans+=mx;
			if(a[i]==mx)va.pb(i);
			else if(b[i]==mx)vb.pb(i);
			else vc.pb(i);
		}if(va.size()>n/2){
			vector<int>tmp;
			for(int i:va)tmp.pb(max(b[i],c[i])-a[i]);
			sort(tmp.begin(),tmp.end(),greater<int>());
			for(int i=0;i<tmp.size()-n/2;i++)ans+=tmp[i];
		}if(vb.size()>n/2){
			vector<int>tmp;
			for(int i:vb)tmp.pb(max(a[i],c[i])-b[i]);
			sort(tmp.begin(),tmp.end(),greater<int>());
			for(int i=0;i<tmp.size()-n/2;i++)ans+=tmp[i];
		}if(vc.size()>n/2){
			vector<int>tmp;
			for(int i:vc)tmp.pb(max(b[i],a[i])-c[i]);
			sort(tmp.begin(),tmp.end(),greater<int>());
			for(int i=0;i<tmp.size()-n/2;i++)ans+=tmp[i];
		}cout<<ans<<'\n';
	}
	return 0;
}
