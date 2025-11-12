#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,mod=1e9+7;
int n,q,l1[N],l2;
string s1[N],s2[N],t1,t2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i],l1[i]=s1[i].size();
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";
			continue;
		}
		l2=t1.size();
		int ans=0;
		for(int i=1;i<=n;i++){
			int h1=0,h2=0;
			while(1){
				int p1=t1.find(s1[i],h1),p2=t2.find(s2[i],h2);
				if(p1==-1||p2==-1) break;
				if(p1==p2){
					bool flag=true;
					for(int j=0;j<l2;j++)
						if((j<p1||j>p1+l1[i]-1)&&t1[j]!=t2[j]){
							flag=false;
							break;
						}
					if(flag) ans++;
					h1=h2=p1+1;
				}
				else if(p1<p2) h1=p1+1;
				else h2=p2+1;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

