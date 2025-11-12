#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,inf=0x3f3f3f3f3f3f3f3f;
int n,q;
string s1[N],s2[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	if(n<=100){
		while(q--){
			string t1,t2;
			cin>>t1>>t2;
			int m=t1.size();
			if(m!=t2.size()){
				cout<<0<<endl; continue;
			}
			t1=" "+t1;
			t2=" "+t2;
			int ans=0;
			for(int i=1;i<=m;i++){
				for(int j=1;j<=n;j++){
					string p=t1.substr(i,s1[j].size());
	//				cout<<p<<endl;
					if(p==s1[j]){
						string tmp=t1.substr(0,i)+s2[j]+t1.substr(i+s2[j].size(),m-i-s2[j].size()+1);
	//					cout<<tmp<<endl;
						if(tmp==t2) ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}else{
		
	}
	return 0;
}
