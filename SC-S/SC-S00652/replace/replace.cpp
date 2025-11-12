#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=5e6+10,bas=1331;
struct NODE{
	ull l,r;
	int l1,r1;
};
map<pair<string,string>,vector<NODE> > mp;
int n,q;
string s1,s2,s3,s4;
char s[N],t[N];
ull HASH(string S){
	ull h=0;
	for(auto it:S){
		h=h*bas+it;
	}
	return h;
}
ull ha1[N],mi[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	mi[0]=1;
	for(int i=1;i<N;i++)mi[i]=mi[i-1]*bas;
	for(int i=1;i<=n;i++){
		cin>>s+1>>t+1;
		int l=1,r=strlen(s+1),m=r;
		s3.clear(),s4.clear();
		while(s[l]==t[l]&&l<=m)s3.push_back(s[l]),l++;
		while(s[r]==t[r]&&r>0)r--;
		if(l>r)continue;
		for(int j=r+1;j<=m;j++)s4.push_back(s[j]);
		s1.clear();s2.clear();
		for(int j=l;j<=r;j++)s1.push_back(s[j]),s2.push_back(t[j]);
		mp[{s1,s2}].push_back({HASH(s3),HASH(s4),l-1,m-r});
	}
	while(q--){
		cin>>s+1>>t+1;
		if(strlen(s+1)!=strlen(t+1)){
			cout<<0<<'\n';
			continue;
		}
		int m=strlen(s+1);
		for(int i=1;i<=m;i++){
			ha1[i]=ha1[i-1]*bas+s[i];
		}
		int l=1,r=m;
		while(s[l]==t[l]&&l<=m)l++;
		while(s[r]==t[r]&&r>0)r--;
		s1.clear();s2.clear();
		for(int j=l;j<=r;j++)s1.push_back(s[j]),s2.push_back(t[j]);
		auto it1=mp[{s1,s2}];
		int ans=0;
		for(NODE it:it1){
			if(it.l==ha1[l-1]-ha1[l-1-it.l1]*mi[it.l1]&&it.r==ha1[r+it.r1]-ha1[r]*mi[it.r1]&&l-it.l1>0&&it.r1+r<=m){ 
				ans++;
			}	
		}
		cout<<ans<<'\n';
	}
	return 0;
} //nqlogn