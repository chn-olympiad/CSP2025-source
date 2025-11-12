#include <bits/stdc++.h>
using namespace std;
#define read(x) scanf("%d",&x)
const int N=2e5+10;
int n,q;
map<string,string>book;
int main()
{
  	freopen("replace.in","r",stdin);
   	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		book[s1]=s2;
	}
	while(q--){
		string c1,c2;
		cin>>c1>>c2;
		if(book[c1]==c2) cout<<1<<'\n';
		else cout<<0<<"\n";
	}
	return 0;
}

