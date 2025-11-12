#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1001]=" ",b[1001]=" ";
	cin>>a;
	cin>>b;
	long long i,j,k=0,l=0;
	int c[1001]={0},d[1001]={0};
	for(i=0;i<1001;i++){
		if(a[i]-48>=0&&a[i]-48<=9&&a[i]!=' '){
		k+=1;
		c[i]=a[i]-48;}
	}for(i=0;i<1001;i++){
		if(b[i]-48>=0&&b[i]-48<=9&&b[i]!=' '){
		l+=1;
		d[i]=b[i]-48;}
	}
	sort(c,c+1001);sort(d,d+1001);
	for(i=1000;i>1000-k;i--){
	cout<<c[i];}
	for(i=1000;i>1000-l;i--){
	cout<<d[i];}

	
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
