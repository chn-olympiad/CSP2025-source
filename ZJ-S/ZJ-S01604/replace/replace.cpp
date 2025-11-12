#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5,maxm=1e7+5;
int n,q,ans;
struct node{
	int qian,hou;
};
vector<node> b[maxm];
string s1[maxn],s2[maxn];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		int cnt1=0,cnt2=0;
		int n=s1[i].size();
		for(int j=0;j<n;j++){
			if(s1[i][j]=='b'){
				cnt1=j;
			}
			if(s2[i][j]=='b'){
				cnt2=j;
			}
		}
		b[cnt1-cnt2+5000000].push_back({(cnt1),(n-cnt2)});
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<'\n';
			continue;
		}
		int cnt1=0,cnt2=0;
		for(int i=0;i<t1.size();i++){
			if(t1[i]=='b'){
				cnt1=i;
			}
			if(t2[i]=='b'){
				cnt2=i;
			}
		}
		ans=0;
		for(int i=0;i<b[cnt1-cnt2+5000000].size();i++){
			int qq=b[cnt1-cnt2+5000000][i].qian,hh=b[cnt1-cnt2+5000000][i].hou;
			if(qq<=cnt1&&hh<=(t1.size()-cnt2)){
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
