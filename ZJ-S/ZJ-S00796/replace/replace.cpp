#include<bits/stdc++.h>
using namespace std;
int n,q,mx;
map<string,map<string,int> >mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s,st;
		cin>>s>>st;
		mp[s][st]++;
		mx=max(mx,(int)s.size());
	}
	while(q--){
		string st,ed;cin>>st>>ed;
		if(st.size()!=ed.size())cout<<0<<'\n';
		else {
			long long sum=0;
			int i=0,j=st.size()-1;
			while(st[i]==ed[i])i++;
			while(st[j]==ed[j])j--;
			if(j-i+1>mx)cout<<sum<<'\n';
			else {
				for(;i>=0;i--){
					for(int k=j;k<st.size()&&k-i+1<=mx;k++){
						string e=st.substr(i,k-i+1);
						string d=ed.substr(i,k-i+1);
						if(mp.count(e)&&mp[e].count(d))sum+=1ll*mp[e][d];
					}
				}
				cout<<sum<<'\n';
			}
		}
	}
	return 0;
}
