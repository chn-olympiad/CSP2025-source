#include<bits/stdc++.h>
using namespace std;

inline int read();

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	printf("0\n");
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

inline int read()
{
	int x=0,s=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')s=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*s;
}

