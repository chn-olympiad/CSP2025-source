#include <bits/stdc++.h>
using namespace std;
char s[1000001];
long long a[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int t=1,n=strlen(s);
	for(int i=0;i<n;i++){
		if(s[i]<'a'){
			a[t]=s[i]-48;
			t++;
		}
	}
	for(int i=1;i<=t;i++){
		for(int j=1;j<=t-i;j++){
			if(a[i]<a[i+1]){
				int temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}
	}
	for(int i=1;i<t;i++){
		cout<<a[i];
	}
	return 0;
} 
