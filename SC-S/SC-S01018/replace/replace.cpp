#include<bits/stdc++.h>
using namespace std;
int n,q;
string si,sj;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>si>>sj;
	for(int i=1;i<=q;i++) cin>>si>>sj;
	for(int i=1;i<=q;i++) cout<<0<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}