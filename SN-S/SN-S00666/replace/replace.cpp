#include<bits/stdc++.h>
using namespace std;
int n,q;
string nn[200100][2];
string qq[200100][2];
long long total=0;
int a1,a2,b1,b2,c1,c2;
char b='b';
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>nn[i][0]>>nn[i][1];
	for(int i=1;i<=q;i++)cin>>qq[i][0]>>qq[i][1];
	for(int i=1;i<=q;i++){
		a1=qq[i][0].find(b);
		a2=qq[i][1].find(b);
		c1=a2-a1;
		for(int j=1;j<=n;j++){
			b1=nn[j][0].find(b);
			b2=nn[j][1].find(b);
			c2=b2-b1;
			if(c1==c2)total++;
		}
	}
	cout<<total;
	return 0;
}
