#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,q,p,dx,tx,ans;
string s[N][4],t[N][4];

pair<string,string> qu(string x,string y){
	string res="";
	int l=0,r=x.size();
	while(x[l]==y[l])
		++l;
	while(x[r]==y[r])
		--r;
	return make_pair(x.substr(l,r-l+1),y.substr(l,r-l+1));
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
		cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;++i)
		cin>>t[i][1]>>t[i][2];
	for(int i=1;i<=q;++i){
		ans=0;
		pair<string,string> p=qu(t[i][1],t[i][2]);
		for(int j=1;j<=n;++j)
			if(s[j][1].find(p.first)<s[j][1].size()&&s[j][2].find(p.second)<s[j][2].size()
			&&t[i][1].find(s[j][1])<t[i][1].size()&&t[i][2].find(s[j][2])<t[i][2].size())
				++ans;
		printf("%d\n",ans);
	}
	return 0;
}
