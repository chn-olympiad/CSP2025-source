#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N=1e5+10,P=998244353;
string s1[N],s2[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,Q;
	cin>>n>>Q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(Q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=T2.size()){
			cout<<"0\n";
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int lt=0;
			while(1){
				lt=t1.find(s1[i],lt);
				if(lt==EOF) break;
				string s=t1;
				for(int k=lt;k<lt+s1[i].size();k++)
					s[k]=s2[i][k-lt];
				if(s==t2) ans++;
				lt++;
			}	
		}
		cout<<ans<<endl;
	}
	return 0;
}
//CSP-S2025 rp++
//[10,25]
