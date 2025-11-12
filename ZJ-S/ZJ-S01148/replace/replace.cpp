#include<bits/stdc++.h>
using namespace std;
map<string,pair<int,string> > mp;
int n,q,ans;
string x,y,s,sum[100005],sb;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		mp[x].first++;
		mp[x].second=y;
	}
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>x>>y;
		int cd=x.size();
		sum[0]=x[0];
		for(int j=1;j<cd;j++) sum[j]=sum[j-1]+x[j];
		for(int j=1;j<=cd;j++){
			for(int k=0;k<=x.size();k++){
				s.clear();
				if(k+j-1>=cd) break;
				for(int h=k;h<=k+j-1;h++) s+=x[h];
				if(mp[s].first!=0){
					sb.clear();
					for(int h=k+j;h<cd;h++) sb+=x[h];
					if(k-1<0){
						if(mp[s].second+sb==y) ans++;
					}else if(sum[k-1]+mp[s].second+sb==y) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
