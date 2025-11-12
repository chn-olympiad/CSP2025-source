#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
const int b1 = 37;
const int mod = 1e9+7;
int n,q;
int cnt;
int a[maxn],b[maxn];
map<int,int> ex;
vector<vector<int>> G;
vector<int> tmp;
string s,t;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	G.push_back(tmp);
	for (int i = 1;i<=n;i++){
		cin>>s>>t;
		for (unsigned int j = 0;j<s.size();j++){
			a[i] = (a[i]*b1+s[j]-'a'+1)%mod;
			b[i] = (b[i]*b1+t[j]-'a'+1)%mod;
		}
		int l = s.size();
		if (!ex[l]) {
			ex[l] = ++cnt;
			tmp.clear();
			tmp.push_back(i);
			G.push_back(tmp);
		}
		else{
			G[ex[l]].push_back(i);
		}
//		cout<<a[i]<<" "<<b[i]<<endl;
	}
	for (int i = 1;i<=q;i++){
		int res=0;
		cin>>s>>t;
		if (s.size()!=t.size()){
			cout<<0<<endl;
			continue;
		}
		unsigned int st=0,ed=s.size()-1;
		while(s[st] == t[st] && st<s.size()-1) st++;
		while(s[ed] == t[ed] && ed>0) ed--;
		for (unsigned int i = 0;i<=st;i++){
			int at = 0,bt = 0;
			for (unsigned int j = i;j<s.size();j++){
				at = (at*b1+s[j]-'a'+1)%mod;
				bt = (bt*b1+t[j]-'a'+1)%mod;
				if (j<ed) continue;
//				cout<<i<<" "<<j<<" "<<at<<" "<<bt<<endl;
				if (ex[j-i+1]) {
					for (auto v:G[ex[j-i+1]]){
						if (a[v] == at && b[v] == bt) res++;
					}
				}
			}
		}
		cout<<res<<endl;
	}
}