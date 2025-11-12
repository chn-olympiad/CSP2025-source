#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long a[1000000];
	cin>>s;
	for(int i=1;i<=s.size();i++){
		if(s[i]-'0'>=1&&s[i]-'0'<=9){
			a[i]=s[i]-'0';
		}
	}
	for(int i=1;i<=s.size();i++){
		for(int j=1;j<=s.size();j++){
			if(a[i]>a[j]){
				int w=a[i];
				a[i]=a[j];
				a[j]=w;
			}
		}
	}
	for(int i=1;i<=s.size();i++){
	    printf("%d",a[i]);
	}
	return 0;
}