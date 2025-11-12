#include<bits/stdc++.h>
using namespace std;
long long a[10000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000005];
	gets(s);
	long long t=0;
	for(int i=0;i<strlen(s);i++){
			a[i]=int(s[i]);
			t++;
	}
	for(int i=0;i<t;i++){
		if(a[i]<48||a[i]>57){
		   a[i]=-1;
		}
	}
	sort(a,a+t);
	for(int i=t-1;i>=0;i--){
		if(a[i]>=0){
			cout<<a[i]-48;
	    }
	}
	return 0;
}
