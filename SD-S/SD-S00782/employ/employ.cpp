#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,P=998244353;
int n,m,v[N],p[N];
bool SPEA=1;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) cin>>v[i];
	for(int i=1;i<=n;i++) if(s[i]=='0') SPEA=0;
	for(int i=1;i<=n;i++) p[i]=i;
	if(n<=10){//8pts BF
		int ans=0;
		do{
			int c=0,suc=0;
			for(int i=1;i<=n;i++){
				if(c>=v[p[i]]||s[i]=='0') c++;
				else if((++suc)==m){
					ans++;
					break;
				}
			}
		}while(next_permutation(p+1,p+1+n));
		cout<<ans<<"\n";
	}else{//0pts output n!
		int ans=1;
		for(int i=1;i<=n;i++) (ans*=i)%=P;
		cout<<ans<<"\n";
	}
	//20pts SPEA What to do...?
	return 0;
}
