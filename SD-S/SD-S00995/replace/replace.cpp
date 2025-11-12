#include<string>
#include<cstdio>
#include<iostream>
#define int long long
using namespace std;
const int N=2e5+5,INF=1e9;
string s[N][3],ta,tb;
int n,q,l,r,ans,le[N],len;
int cnt_sum(int x){
	int ret=0;
	string so=s[x][1],sn=s[x][2];
	for(int lft=max(r-le[x]+1,0ll);lft<=l;lft++){
		bool f=1;
		int rit=lft+le[x]-1;
		for(int pos=lft,i=0;pos<=rit;pos++,i++){
			if(so[i]!=ta[pos]||sn[i]!=tb[pos]){
				f=0;
				break;
			}
		}
		ret+=f;
	}
	return ret;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		le[i]=s[i][1].size();
	}
	while(q--){
		cin>>ta>>tb;
		len=ta.size(),l=INF,r=0,ans=0;
		for(int i=0;i<len;i++){
			if(ta[i]!=tb[i]){
				l=min(l,i),r=max(r,i);
			}
		}
		for(int i=1;i<=n;i++){
			if(le[i]>=r-l+1&&le[i]<=len){
				ans+=cnt_sum(i);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
