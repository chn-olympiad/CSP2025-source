#include<bits/stdc++.h>
using namespace std;
long long a[200005][4],t,n,ans,ct[5],s[4][200005];
multiset<pair<long long,long long> >ss;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		memset(s,0,sizeof(s));
		memset(ct,0,sizeof(ct));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			ss.insert({a[i][1],1});
			ss.insert({a[i][2],2});
			ss.insert({a[i][3],3});
			auto it=ss.end();
			it--;
			auto it2=(--it);
			it++;
			ans+=((*it).first);
			ct[((*it).second)]++;
			s[(*it).second][ct[(*it).second]]=((*it).first)-((*it2).first);
			ss.clear();
		}
		if(ct[1]>n/2){
			sort(s[1]+1,s[1]+1+ct[1]);
			for(int i=1;i<=ct[1]-n/2;i++){
				ans-=s[1][i];
			}
		}
		else if(ct[2]>n/2){
			sort(s[2]+1,s[2]+1+ct[2]);
			for(int i=1;i<=ct[2]-n/2;i++){
				ans-=s[2][i];
			}
		}
		else if(ct[3]>n/2){
			sort(s[3]+1,s[3]+1+ct[3]);
			for(int i=1;i<=ct[3]-n/2;i++){
				ans-=s[3][i];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//chzx_lfw AKIOI!!!!!
