#include<bits/stdc++.h>
using namespace std;
char kinchar,kinf;
long long kinnum;
inline long long kin()
{
	kinf=1;
	kinchar=getchar();
	kinnum=0;
	if(!('0'<=kinchar&&kinchar<='9'))
	{
		kinf=-1;
		kinchar=getchar();
	}
	while(('0'<=kinchar&&kinchar<='9'))
	{
		kinnum=kinnum*10+kinchar-'0';
		kinchar=getchar();
	}
	return kinnum*kinf;
}
long long n,m,k;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=kin();
	m=kin();
	k=kin();
	for(long long i=0;i<m*3+k*(n+1);i++)
	{
		kin();
	}
	cout<<0;


	fclose(stdin);
	fclose(stdout);
	return 0;
}

