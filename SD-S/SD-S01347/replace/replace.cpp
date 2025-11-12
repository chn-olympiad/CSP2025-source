#include<bits/stdc++.h>
#define endl "\n"
#define int long long 
#define PII pair<int,int>
using namespace std;
const int maxN=1e6+10,INF=INT_MAX;
//vector<PII> g[maxN];
//priority_queue<PII,vector<PII>,greater<PII> >pq;
int n,q;
string s1[maxN],s2[maxN],t1,t2;
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--){
		int ans=0;
		cin>>t1>>t2;
		int l=0,r=t1.size();
		while(l<r){
			if(t1[l]==t2[l])l++;
			else if(t1[r]==t2[r])r--;
			else break;
		}
		for(int i=1;i<=n;i++){
			if(r-l+1>s1[i].size()) continue;
			int len=s1[i].size(),lt=t1.size();
			for(int j=max(r-len,0ll);j<min(l+len,lt);j++){
				int ll=j,rr=j+s1[i].size(),fl=0;
				for(int k=ll;k<rr;k++){
					if(s1[i][k-ll]!=t1[k]){
						fl=1;
						break;
					}
					if(k>=l&&k<=r) continue;
					if(s2[i][k-ll]!=t1[k]){
						fl=1;
						break;
					}
				}
				if(!fl){
					//cout<<i<<endl;
					for(int k=0;k<len;k++){
						if(s2[i][k]!=t2[ll+k]){
							fl=1;
							break;
						}
					}
				}
				if(!fl){
					ans++;
					//cout<<i<<' '<<endl;
				} 
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}//Ren5Jie4Di4Ling5%
