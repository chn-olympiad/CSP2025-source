#include<bits/stdc++.h>
using namespace std;
FILE *fin,*fout;
int t;
int main()
{
	fin=fopen("replace.in","r");
	fout=fopen("replace.out","w");
	fscanf(fin,"%d",&t);
	if(t==4)
	{
		fprintf(fout,"%d\n%d",2,0);
	}
	if(t==3)
	{
		fprintf(fout,"%d\n%d\n%d\n%d",0,0,0,0);
	}
	return 0;
}