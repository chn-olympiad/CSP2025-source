#include<bits/stdc++.h>
#define lon long long
using namespace std;
int n,q;
struct str{
	string a,b;
	int len;
	int qza,hza,qzb,hzb;
}st[200010];
string x,y;
int qzx,hzx,qzy,hzy;
int len;
lon ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>st[i].a>>st[i].b;
		st[i].len=st[i].a.size();
		for(int i=0;i<len;i++) if(st[i].a[i]=='b'){
			st[i].qza=i;
			break;
		}
		for(int i=0;i<len;i++) if(st[i].b[i]=='b'){
			st[i].qzb=i;
			break;
		}
		for(int i=len-1;i>=0;i--) if(st[i].a[i]=='b'){
			st[i].hza=len-i+1;
			break;
		}
		for(int i=len-1;i>=0;i--) if(st[i].b[i]=='b'){
			st[i].hzb=len-i+1;
			break;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		len=x.size();
		for(int i=0;i<len;i++) if(x[i]=='b'){
			qzx=i;
			break;
		}
		for(int i=len-1;i>=0;i--) if(x[i]=='b'){
			hzx=len-i-1;
			break;
		}
		for(int i=0;i<len;i++) if(y[i]=='b'){
			qzy=i;
			break;
		}
		for(int i=len-1;i>=0;i--) if(y[i]=='b'){
			hzy=len-i-1;
			break;
		}
		for(int i=1;i<=n;i++){
			if(st[i].qza-st[i].qzb==qzx-qzy && st[i].qza<=qzx && st[i].hza<=hzx && st[i].qzb<=qzy && st[i].hzb<=hzy) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*

aaaabaaaa
aaaaaabaa

aba
aabaa

*/
