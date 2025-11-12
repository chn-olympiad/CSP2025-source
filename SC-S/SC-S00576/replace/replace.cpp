#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int,int>
#define ull unsigned long long
const int N=2e5+10;
const int P=37;
bool ud[N];
ull p[N];
struct str{
	string s;
	vector<ull>hs;
	void init(string s){
		this->s=s;
		hs.push_back(0);
		for(int i=1;i<=s.size();i++){
			hs.push_back(hs.back()*P+s[i-1]-'a'+1);
		}
	}
	ull get(int l,int r){
		return hs[r]-hs[l-1]*p[r-l+1];
	}
}s[N][2];
pi getxyz(string s1,string s2){
	int n=s1.size();
	int p1=0,p2=n+1;
	s1=' '+s1,s2=' '+s2;
	for(int i=1;i<=n;i++){
		if(s1[i]!=s2[i])break;
		p1=i;
	}
	for(int i=n;i>=1;i--){
		if(s1[i]!=s2[i])break;
		p2=i;
	}
	return {p1,p2};
}
bool chk(string s){
	bool ch=true;
	for(int i=1;i<=s.size();i++){
		if(s[i-1]>'b')ch=false;
	}
	return ch;
}
pi pl[N];
map<int,int>mp;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	p[0]=1;
	for(int i=1;i<N;i++)p[i]=p[i-1]*P;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	bool fl=true;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		fl&=chk(s1);
		fl&=chk(s2);
		s[i][0].init(s1);
		s[i][1].init(s2);
		if(s1==s2){
			ud[i]=true;continue;
		}
		pl[i]=getxyz(s1,s2);
		mp[s[i][0].get(pl[i].first+1,pl[i].second-1)]++;
//		cout<<pl[i].first<<" "<<pl[i].second<<" PL\n";
	}
	for(int i=1;i<=q;i++){
		str st[2];
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";continue;
		}
		st[0].init(t1);
		st[1].init(t2);
		pi ppl=getxyz(t1,t2);
//		if(fl&&q>1){
//			cout<<mp[st[0].get(ppl.first+1,ppl.second-1)]<<"\n";
//			continue;
//		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(ud[i])continue;
			int s0=pl[i].first,s1=pl[i].second;
			int t0=ppl.first,t1=ppl.second;
			if(st[0].get(t0+1,t1-1)==s[i][0].get(s0+1,s1-1)){
				if(st[1].get(t0+1,t1-1)==s[i][1].get(s0+1,s1-1)){
					int lenr=s[i][0].s.size()-s1+1;
					if(t0>=s0&&t2.size()-t1+1>=lenr){
						if(st[0].get(t0-s0+1,t0)==s[i][0].get(1,s0)){
							if(st[0].get(t1,t1+lenr-1)==s[i][0].get(s1,s[i][0].s.size())){
								cnt++;
							}
						}
					}
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}