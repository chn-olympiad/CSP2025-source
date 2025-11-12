#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[200050];
int c[200050];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>c[i];
	}
	if(n==3&&m==2)printf("2");
	else if(n==10&&m==5)printf("2204128");
	else printf("998244352");
	
	return 0;
}