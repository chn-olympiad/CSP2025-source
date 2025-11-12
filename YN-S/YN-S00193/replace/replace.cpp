#include <bits/stdc++.h>
using namespace std;
const int N=200020,M=1000000;
string s1[N],s2[N],t1,t2;
int sz[N],hd[N],tl[N];
vector <int> vt[N*10];
bool check(int x,int y){
	for(int i=y;i<=s1[x].size()+y-1;i++){
		if(s1[x][i-y]==t1[i]&&s2[x][i-y]==t2[i]) continue;
		return 0;
	}
	for(int i=s1[x].size()+y-1;i<s1[x].size();i++)
		if(t1[i]!=t2[i]) return 0;
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	if(n<=200&&q<=200){
		for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
		while(q--){
			int ans=0;
			cin>>t1>>t2;
			if(t1.size()!=t2.size()){
				cout<<0<<"\n";
				continue;
			}
			int ts=t1.size();
			for(int i=1;i<=n;i++){
				for(int j=0;j<ts;j++){
					if(j+s1[i].size()>ts+1) break;
					ans+=check(i,j);
					if(t1[j]!=t2[j]) break;
				}
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int tmp=0;
		cin>>s1[i]>>s2[i];sz[i]=s1[i].size();
		for(int j=0;j<sz[i];j++){
			if(s1[i][j]=='b') tmp+=j,hd[i]=max(hd[i],j),tl[i]=max(tl[i],sz[i]-j);
			if(s2[i][j]=='b') tmp-=j,hd[i]=max(hd[i],j),tl[i]=max(tl[i],sz[i]-j);
		}
		tmp=tmp+M;
		vt[tmp].push_back(i);
	}
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<"\n";
			continue;
		}
		int tmp=0,hdn=0,tln=0,ans=0,siz=t1.size();
		for(int j=0;j<siz;j++){
			if(t1[j]=='b') tmp+=j,hdn=max(hdn,j),tln=max(tln,siz-j);
			if(t2[j]=='b') tmp-=j,hdn=max(hdn,j),tln=max(tln,siz-j);
		}
		for(int i:vt[tmp+M]){
			if(hd[i]<=hdn&&tl[i]<=tln) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//摆烂了 15pts 保佑我别挂吧