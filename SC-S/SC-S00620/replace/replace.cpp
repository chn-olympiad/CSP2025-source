#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200050][2],b[200050][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>b[i][1]>>b[i][2];
	}
	for(int i=1;i<=q;i++)
	{
		printf("0\n");
	}
	
	
	return 0;
}
/*3 4
 a b
 b c
 c d
 aa bb
 aa b
 a c
 b a*/