#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("number1.in","r",stdin);
//	freopen("number.out","w",stdout);
	char s[1000000]="";
	int m=0;
	int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,k=0,l=0;
	cin>>s;
	for(int i=0;i<=strlen(s);i++){
		m++;
		if(s[i]=='0')a++;
		if(s[i]=='1')b++;
		if(s[i]=='2')c++;
		if(s[i]=='3')d++;
		if(s[i]=='4')e++;
		if(s[i]=='5')f++;
		if(s[i]=='6')g++;
		if(s[i]=='7')h++;
		if(s[i]=='8')k++;
		if(s[i]=='9')l++;
	}
	
//	for(int i=0;i<m;i++){
//		int a=0;
//		for(int j=i;j<=m;j++){
//			if(s[j]<a){
//				a=s[j];
//			}
//		}
//		if(a!=i) swap(s[i],s[a]);
//	}
	for(int i=0;i<l;i++){
		cout<<9;
	}
	for(int i=0;i<k;i++){
		cout<<8;
	}
	for(int i=0;i<h;i++){
		cout<<7;
	}
	for(int i=0;i<g;i++){
		cout<<6;
	}
	for(int i=0;i<f;i++){
		cout<<5;
	}
	for(int i=0;i<e;i++){
		cout<<4;
	}
	for(int i=0;i<d;i++){
		cout<<3;
	}
	for(int i=0;i<c;i++){
		cout<<2;
	}
	for(int i=0;i<b;i++){
		cout<<1;
	}
	for(int i=0;i<a;i++){
		cout<<0;
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
