#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PQ priority_queue
#define ump unordered_map
#define inf 0x3f3f3f3f
using namespace std;
const int N=2e5+10,P=13331,M=5e6+10;
int n,q,mx;
string s[N][3];
ump<string,string> mp;
ull hs1[N],hs2[N],p[N];
bool check(int l,int r){
	return (hs1[r]-hs1[l-1]*p[r-l+1])==(hs2[r]-hs2[l-1]*p[r-l+1]);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
		mp[s[i][1]]=s[i][2];
		mx=max(mx,(int)s[i][1].size());
	}
	p[0]=1;
	for(int i=1;i<=mx;i++) p[i]=p[i-1]*P;
	while(q--){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int len=t1.size();
		t1=' '+t1;
		t2=' '+t2;
		for(int i=1;i<=len;i++){
			hs1[i]=hs1[i-1]*P+t1[i];
			hs2[i]=hs2[i-1]*P+t2[i];
		}
		for(int i=1;i<=len;i++){
			for(int j=1;i+j-1<=len;j++){
				string k=t1.substr(i,j);
				string kk=t2.substr(i,j);
				if(mp[k]==kk&&check(1,i-1)&&check(i+j,len)) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	
	
	return 0;
} 
