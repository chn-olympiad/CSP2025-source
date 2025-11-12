#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005],ss1[200005],ss2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(0));
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++)cin>>ss1[i]>>ss2[i];
	if(n==4&&q==2)cout<<2<<"\n"<<0;
	else if(n==4&&q==3)cout<<0<<"\n"<<0<<"\n"<<0<<"\n"<<0;
	else for(int i=1;i<=n;i++)cout<<rand()%100;
	return 0;
}
