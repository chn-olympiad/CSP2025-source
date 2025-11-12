#include<bits/stdc++.h>
using namespace std;

char s[1000005];
int a[100005],b=1,c=0,d=0;

int main(){
	scanf("%s",s+1);
	int l=strlen(s+1);
	 for(int i=1;i<=l;i++){
	 	if(s[i]=='0'){
	 		a[b]=0;
	 		b++;
		 }
		 if(s[i]=='1'){
	 		a[b]=1;
	 		b++;
		 }
		 if(s[i]=='2'){
	 		a[b]=2;
	 		b++;
		 }
		 if(s[i]=='3'){
	 		a[b]=3;
	 		b++;
		 }
		 if(s[i]=='4'){
	 		a[b]=4;
	 		b++;
		 }
		 if(s[i]=='5'){
	 		a[b]=5;
	 		b++;
		 }
		 if(s[i]=='6'){
	 		a[b]=6;
	 		b++;
		 }
		 if(s[i]=='7'){
	 		a[b]=7;
	 		b++;
		 }
		 if(s[i]=='8'){
	 		a[b]=8;
	 		b++;
		 }
		 if(s[i]=='9'){
	 		a[b]=9;
	 		b++;
		 }
	 }
	for(int i=1;i<=l;i++)
		if(a[i]>0)
			c++;
	for(int i=1;i<=c;i++){
		if(a[i]<a[i+1]){
			int k=a[i];
			a[i]=a[i+1];
			a[i+1]=k;
		}
	}
	for(int i=1;i<=l;i++)
		if(s[i]=='0')
			d++;
	for(int i=1;i<=c;i++)
		printf("%d",a[i]);
	for(int i=1;i<=d;i++)
		printf("%d",0);
	return 0;
}