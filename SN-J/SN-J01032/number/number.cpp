#include<bits/stdc++.h>
using namespace std;
char a[1000000];
int b[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int la=strlen(a);
	int j=0;
	for(int i=0;i<la;i++){
		if(a[i]>='0' && a[i]<='9'){
			b[j]=a[i]-'0';
			j++;
		}
	}
	sort(b,b+j);
	for(int i=j-1;i>=0;i--){
		cout<<b[i];
	}
} 
