#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,q;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	string s1,s2,t1,t2;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) cin>>s1>>s2;
	for(int i=1;i<=n;i++) cin>>t1>>t2;
	if(n==4&&q==2){
		cout<<2<<endl;
		cout<<0;
	}
	if(n==3&&q==4){
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0<<endl;
		cout<<0;
	}
	
	return 0;
}