#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,i,k,cnt=0;
	char s[1000005],t[1000005];
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(i=0;i<1000000;i++){
		s[i]=getchar();
	}
	for(k=0;k<1000000;k++){
		if(s[k]>=48&&s[k]<=57){
			t[cnt]=s[k];
			cnt=cnt+1;
		}
	}
	for(i=0;i<=cnt;i++){
		for(k=0;k<cnt-1;k++){
			if(t[k]<t[k+1]){
				a=t[k+1];
				t[k+1]=t[k];
				t[k]=a;
			}
		}
	}
	for(i=0;i<cnt;i++){
		cout<<t[i];
	}
	
	return 0;
}
