#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int a[1000005];
bool cmp(int a,int b){
	if(a>b) return a>b;
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.getline(s,1000005);
	int l=strlen(s);
	for(int i=1;i<=1000005;i++){
		a[i]=909;
	}
	for(int i=0;i<l;i++){
		if(s[i]>=48&&s[i]<=57)
		a[i]=(int)s[i]-48;
	}
	sort(a,a+l,cmp);
	for(int i=0;i<l;i++){
		if(a[i]!=909) cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
