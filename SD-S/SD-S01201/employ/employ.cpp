#include<bits/stdc++.h>
using namespace std;
namespace lkwbian{
	using ll=long long;
	using pii=pair<int,int>;
	#define fi first
	#define se second
	#define mp make_pair
	int n,m;
	int c[15],p[15];
	void Main(){
		cin.tie(nullptr)->sync_with_stdio(0);
		cin>>n>>m;
		string s;
		cin>>s;
		s=' '+s;
		for(int i=1;i<=n;i++)cin>>c[i];
		for(int i=1;i<=n;i++)p[i]=i;
		int ans=0;
		do{
			int now=0;
			for(int i=1;i<=n;i++){
				if(now>=c[i]){
					now++;
					continue;
				}
				if(s[p[i]]=='0'){
					now++;continue;
				}
			}
			if(n-now>=m)ans++;
		}while(next_permutation(p+1,p+n+1));
		cout<<ans;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	lkwbian::Main();
	return 0;
}
//Ren5Jie4Di4Ling5% 
