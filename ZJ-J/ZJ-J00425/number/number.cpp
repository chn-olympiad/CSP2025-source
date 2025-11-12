#include<bits/stdc++.h>
using namespace std;
const int le=1e6+10;
int a[10];
char s[le];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,0,sizeof(a));
	scanf("%s",s+1);
	int l=strlen(s+1);
	for(int i=1;i<=l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			printf("%d",i);
		}
	}
	cout<<endl<<clock()<<endl;
	return 0;
} 
