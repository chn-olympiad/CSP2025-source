#include <bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
int main(){
	freopen("number.in ","r",stdin);
	freopen("number.out ","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9') a[i]=s[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(a[j+1]>a[j]){
				char e=a[j];
				a[j]=a[j+1];
				a[j+1]=e;
			}
		}
	}
	for(int i=0;i<=n;i++){
		printf("%c",a[i]);
	}
	return 0;
}
