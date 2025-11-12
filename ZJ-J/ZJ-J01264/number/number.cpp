#include<bits/stdc++.h>
using namespace std;
int n,i,j;
string s;
int m[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(m,0,sizeof(m));
    cin>>s;
    n=s.length();
    for(i=0;i<n;i++){
    	if(s[i]>='0' and s[i]<='9')
    	  m[int(s[i]-'0')]++;
	}
	for(i=9;i>=0;i--){
		for(j=1;j<=m[i];j++)
		  printf("%d",i);
	}
	return 0;
}

