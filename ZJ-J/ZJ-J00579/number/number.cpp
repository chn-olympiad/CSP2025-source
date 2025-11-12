#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],b[100005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.length(),z=0;
	for(int i=0;i<n;i++){
		if(s[i]>=48&&s[i]<=57){
			z++;
			a[z]=s[i]-48;
		}
	}
	sort(a+1,a+z+1);
	for(int i=1;i<=z;i++){
		b[i]=a[z-i+1];
	}
	for(int i=1;i<=z;i++){
		printf("%d",b[i]);
	}
	return 0;
}
