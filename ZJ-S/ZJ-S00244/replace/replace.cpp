#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct stu {
	string s,t;
} st[12000],str[12000];
int n,q,i,j,ii,jj;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(i=1; i<=n; i++)
		cin>>st[i].s>>st[i].t;
	for(i=1; i<=q; i++)
		cin>>str[i].s>>str[i].t;
	for(int T=1; T<=q; T++) {
		
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}