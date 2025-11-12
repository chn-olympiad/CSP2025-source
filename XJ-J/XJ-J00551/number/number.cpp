#include<bits/stdc++.h>
using namespace std;
char a[1000100];
int b[1000100];
bool cmp(int a,int b){
	return a>b;
}
int s=0;
int main ( ) {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>a;
	cin.get(a[100010]);
	int l=strlen(a);
	for(int i=0;i<l;i++){
		if(a[i]>='0'&&a[i]<='9') {
			b[i]=int (a[i])-int ('0');
			if(int (a[i])-int ('0')==0) s++;
		}
	}
	sort(b,b+l,cmp);
	for(int i=0;i<l;i++){
		if(b[i]!=0) cout <<b[i];
		else if(b[i]==0&&s!=0){
			cout <<"0";
			s--;
		}
		
	}
	return 0;
} 
