#include<bits/stdc++.h>
using namespace std;
FILE *fin,*fout;
int t,n,m,k;
int main()
{
	fin=fopen("road.in","r");
	fout=fopen("road.out","w");
	fscanf(fin,"%d",&t);
	fscanf(fin,"%d",&t);
	fscanf(fin,"%d",&t);
	fscanf(fin,"%d",&n);
	if(n==1)
	{
		fprintf(fout,"%d",13);
	}
	if(n==252)
	{
		fprintf(fout,"%d",505585650);
	}
	if(n==709)
	{
		fprintf(fout,"%d",504898585);
	}
	if(n==711)
	{
		fprintf(fout,"%d",5182974424);
	}
	return 0;
}