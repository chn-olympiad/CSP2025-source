#include <bits/stdc++.h>
using namespace std;
int main(){ 
	FILE *fin=NULL,*fout=NULL;
	fin=fopen("seat.in","r");
	fout=fopen("seat.out","w");
	int n=0,m=0,a[101]={0},b[101]={0},r,wei=0;
	fscanf(fin,"%d %d",&n,&m);
	for(int i=0;i<n*m;i++){
		fscanf(fin,"%d",&a[i]);
	}
	r=a[0];
	sort(a,a+(n*m));
	for(int i=0;i<n*m;i++){
		b[i]=a[n*m-i-1];
		if(b[i]==r){
			wei=i;
		}
	}
	int c,d;
	c=wei/n+1;
	if(c%2!=0)d=wei%n+1;
	else d=n-(wei%n);
	fprintf(fout,"%d %d",c,d);
	return 0;
}

