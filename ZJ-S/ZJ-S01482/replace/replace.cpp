#include <bits/stdc++.h>
using namespace std;
int n,q;
string u,v;
struct node{
	string a,b;
	int ax,bx,al,bl;
}s[200005];
int find(string s){
	for (int i=0;i<s.length();i++)
		if (s[i]=='b') return i;
}
	
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b;
		s[i].ax=find(s[i].a);
		s[i].bx=find(s[i].b);
		s[i].al=s[i].a.length()-1,s[i].bl=s[i].b.length()-1;
	}
	while (q--){
		int ans=0;
		cin>>u>>v;
		int ux=find(u),vx=find(v);
		int ul=u.length()-1,vl=v.length()-1;
		if (ul!=vl){
			printf("0\n");
			continue;
		}
		for (int i=1;i<=n;i++){
			if (s[i].ax<=ux&&s[i].al<=ul)
				if (s[i].bx<=vx&&s[i].bl<=vl)
					ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}