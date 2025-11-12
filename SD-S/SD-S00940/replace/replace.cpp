#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,M=5e6+5;
const ll mod=1e9+9,P=13331; 
map<ll,int> mp[M];
int n,m,tot=1,tr[M][26],fail[M];
vector<ll> num[M];
queue<int> q;
string s1,s2;
void ins(string s,ll hsh){
	int p=1;
	for(int i=0;i<s.size();i++){
		int c=s[i]-'a';
		if(!tr[p][c]) tr[p][c]=++tot;
		p=tr[p][c];
	}
	num[p].push_back(hsh);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>s1>>s2; ll hsh=0;
		for(int j=0;j<s1.size();j++){
			if(s1[j]==s2[j]) continue;
			for(int k=j;k<s1.size();k++) hsh=(hsh*P%mod+s2[k])%mod;
			ins(s1,hsh);
			break;
		}
	}
	for(int i=0;i<26;i++) tr[0][i]=1;
	q.push(1);
	while(!q.empty()){
		int p=q.front(); q.pop();
		for(int c=0;c<26;c++){
			if(tr[p][c]){
				fail[tr[p][c]]=tr[fail[p]][c];
				mp[tr[p][c]]=mp[fail[tr[p][c]]];
				for(ll v:num[tr[p][c]]) mp[tr[p][c]][v]++;
				q.push(tr[p][c]);
			}else tr[p][c]=tr[fail[p]][c];
		}
	}
	while(m--){
		cin>>s1>>s2; int l=0,r=s1.size()-1;
		while(s1[l]==s2[l]) l++;
		while(s1[r]==s2[r]) r--;
		ll hsh=0,ans=0; int p=1;
		for(int j=0;j<s1.size();j++){
			if(j>=l) hsh=(hsh*P%mod+s2[j])%mod;
			int c=s1[j]-'a'; p=tr[p][c];
			if(j>=r) ans+=mp[p][hsh];
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
