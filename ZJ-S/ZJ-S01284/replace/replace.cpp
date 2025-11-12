#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
int n,q,ans=0;
string t1,t2;
string s1,s2;
struct qujian{
	int l,r;
};
struct node{
	string g,t;
	bool operator <(const node& now)const{
		return g<now.g;
	}
};
struct zt{
	qujian a;
	node b;
};
map<node,vector<zt>>have;
qujian get(string a,string b){
	int l=-1,r=0;
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]){
			if(l==-1){
				l=i;
			}
			r=i;
		}
	}
	return {l,r};
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> s1 >> s2;
		qujian chayi=get(s1,s2);
		if(chayi.l==-1)continue;
		string cha=s1.substr(chayi.l,chayi.r-chayi.l+1);
		string yi=s2.substr(chayi.l,chayi.r-chayi.l+1);
		have[{cha,yi}].push_back({chayi,{s1,s2}});
	}
	for(int i=1;i<=q;i++){
		cin >> t1 >> t2;
		ans=0;
		qujian now=get(t1,t2);
		string c=t1.substr(now.l,now.r-now.l+1);
		string y=t2.substr(now.l,now.r-now.l+1);
		for(int j=0;j<have[{c,y}].size();j++){
			zt xian=have[{c,y}][j];
			string m=xian.b.g;
			string b=xian.b.t;
			//cout << m << " " << b << endl;
			int st=now.l-xian.a.l;
			int en=now.r+xian.b.g.size()-1-xian.a.r;
			//cout << st << " " << en << endl;
			if(st<0 || en>=t1.size()){
				continue;
			}
			if(t1.substr(st,en-st+1)==xian.b.g && t2.substr(st,en-st+1)==xian.b.t){
				ans++;
			}
		}
		cout << ans << endl;
	}
}