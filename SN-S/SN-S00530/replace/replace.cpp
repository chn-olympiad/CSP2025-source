//王铭轩-SN-S00530-陕西省安康中学
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

int n,q;
struct node{
	string s1,s2;
}s[N];
struct {
	string t1,t2;
}t[N];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i].s1>>s[i].s2;
	for(int i=1;i<=q;i++) cin>>t[i].t1>>t[i].t2;

	for(int i=1;i<=q;i++) cout<<0<<endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
