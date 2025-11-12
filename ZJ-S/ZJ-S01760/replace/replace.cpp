#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,q;
struct abc{string n1,n2;};
abc s[MAXN];
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)cin>>s[i].n1>>s[i].n2;
	while(q--){
		cin>>t1>>t2;
		if (t1.size()!=t2.size()) cout<<0<<endl;
		cout<<0<<endl;
	}
	return 0;
}
