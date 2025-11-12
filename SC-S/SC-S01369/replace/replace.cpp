#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=1e7+5;
int n,q,a[N],cnt[M];
string s[N][3];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		a[i]=s[i][1].size()-s[i][2].size();
		cnt[a[i]+5000000]++;
	}
	while(q--){
		string t1,t2;
		int ans=0;
		cin>>t1>>t2;
		if(n<=100&&q<=100&&t1.size()<=200&&t2.size()<=200){
			for(int i=0;i<(int)t1.size();i++)
				for(int j=1;j<=n;j++){
					int x=s[j][1].size();
					if(i+x-1<(int)t1.size()&&t1.substr(i,x)==s[j][1]){
						ans+=(t1.substr(0,i)+s[j][2]+t1.substr(i+s[j][2].size(),(int)t1.size()-i-s[j][2].size())==t2);
					}
				}
			cout<<ans<<'\n';
		}
		else
			cout<<cnt[t1.size()-t2.size()+5000000]<<'\n';
	}
	return 0;
}