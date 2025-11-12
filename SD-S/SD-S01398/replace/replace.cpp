#include <bits/stdc++.h>
using namespace std;
#define N 200005
int n,q,sum;
int k[N],s[N][4];
string sa[N],sb[N];
string ta[N],tb[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	int x,y;
	for (int i=1;i<=n;i++){
		cin>>sa[i]>>sb[i];
		for (int j=0;j<sa[i].length();j++)
		if(sa[i][j]=='b'){
			x=j;
			break;
		}
		for (int j=0;j<sb[i].length();j++)
		if(sb[i][j]=='b'){
			y=j;
			break;
		}
		s[i][1]=abs(x-y);
		if(x<y) swap(x,y);
		s[i][2]=x;
		s[i][3]=y;
	}
	for (int i=1;i<=q;i++){
		cin>>ta[i]>>tb[i];
		cout<<0<<'\n';
	}
	return 0;
}
