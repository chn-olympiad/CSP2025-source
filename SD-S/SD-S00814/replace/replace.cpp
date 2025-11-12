#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string x,t;
int n,q,ans;
string s[N][2];
map<string,vector<pair<int,int> > > r;
inline bool check(pair<int,int> f,int i){
	int l=f.first,r=f.second;
	string tmp="",tmp2="";
	int m=x.size();
	for(int e=0;e<m;e++){
		if(e<l) tmp+=x[e];
		else if(e>r) tmp2+=x[e];
	}
	string prd=tmp+s[i][1]+tmp2;
//	cout<<prd<<'\n';
	return prd==t;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++){
		ans=0;
		cin>>x>>t;
		r.clear();
		int m=x.size();
		for(int i=0;i<m;i++){
			string tmp="";	
			for(int j=i;j<m;j++){
				tmp+=x[j];
				r[tmp].push_back(make_pair(i,j));
			}
		}
		for(int i=1;i<=n;i++)
			for(auto f:r[s[i][0]])
				if(check(f,i)) ans++;
		cout<<ans<<'\n';
	}
	return 0;
}
