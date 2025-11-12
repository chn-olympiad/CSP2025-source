# include <bits/stdc++.h>
using namespace std;
# define For(i,a,b) for(int i=a; i<=b; i++)
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
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int t;
	cin>>t;
	cin>>t;
	For(i,1,t) {
	cout<<0<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


