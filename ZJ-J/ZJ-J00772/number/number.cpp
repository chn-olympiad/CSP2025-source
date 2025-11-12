#include <bits/stdc++.h>
using namespace std;
int a[1000001]={0},lena=0,len=0;
char s[1000001]="";
int main(){ 
	FILE *fin=NULL,*fout=NULL;
	fin=fopen("number.in","r");
	fout=fopen("number.out","w");
	//if(fin==NULL)cout<<"?";
	//cout<<"a";
	while(1){
		fscanf(fin,"%c",&s[len]);
		if(s[len]=='\0')break;
		len++;
	}
	//cout<<s[len]<<""; 
	for(int i=0;i<len;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[lena]=s[i]-'0';
			lena++;
		}
	}
	//cout<<"c"; 
	sort(a,a+lena);
	for(int i=lena-1;i>=0;i--){
		fprintf(fout,"%d",a[i]);
	}
	//cout<<"d"; 
	return 0;
}
