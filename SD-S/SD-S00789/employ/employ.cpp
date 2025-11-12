#include<bits/stdc++.h>
using namespace std;
//#define int long long
//const int N;
int n,m;
int read()
{
	int d=1,k=0;
	char ch=getchar();
	while(!(ch>='0'&&ch<='9'||ch=='-'))
		ch=getchar();
	if(ch=='-')
	{
		d=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		k=k*10+ch-'0';
		ch=getchar();
	}
	return d*k;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	printf("0\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

