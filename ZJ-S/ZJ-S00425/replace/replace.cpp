//yun qi cha:0pts
//yun qi hao:20pts
//yunqi:10%
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;bool flg;
map<pair<int,int>,int> mp;
void sred(int &len,int &pos){
	string ret="";char c=getchar();int cur=0;
	while(c<'a'||c>'z')c=getchar();
	while(c>='a'&&c<='z'){
		cur++;if(c=='b')pos=cur;
		c=getchar();
	}
	len=cur;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int poss=-1,post=-1,lens,lent;
		sred(lens,poss),sred(lent,post);
		if(poss==-1||post==-1)flg=1;
		mp[make_pair(poss-post,lens-lent)]++;
	}
	for(int i=1;i<=m;i++){
		int poss,post,lens,lent;
		sred(lens,poss),sred(lent,post);
		if(poss==-1||post==-1)flg=1;
		if(flg)puts("0");
		else printf("%lld\n",mp[make_pair(poss-post,lens-lent)]);
	}
	return 0;
}

