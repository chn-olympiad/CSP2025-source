#include<bits/stdc++.h>
using namespace std;
long long n,q,mxas,mnas;
struct Node{
	long long len;
	string sf,ss;
}s[20005];
bool cmp(Node x,Node y){
	return x.len<y.len;
}
void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].sf>>s[i].ss;
		s[i].len=s[i].sf.size();
		mxas=max(mxas,s[i].len);
		mnas=max(mnas,s[i].len);
	}
	sort(s+1,s+1+n,cmp);
	while(q--){
		long long ans=0,ls;
		string st,ed;
		cin>>st>>ed;
		ls=st.size();
		if(st.size()!=ed.size()||st.size()>mxas){
			cout<<"0"<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			if(s[i].len>ls){
				continue;
			}
			for(int j=0;j<=ls-s[i].len;j++){
				bool flag=true;
				for(int k=0;k<s[i].len;k++){
					if(s[i].sf[k]!=st[j+k]||s[i].ss[k]!=ed[j+k]){
						flag=false;
						break;
					}
				}
				for(int k=j+s[i].len;k<ls;k++){
					if(st[k]!=ed[k]){
						flag=false;
						break;
					}
				}
				if(flag){
					ans++;
				}
				if(st[j]!=ed[j]){
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long t=1;
	while(t--){
		solve();
	}
	return 0;
}
