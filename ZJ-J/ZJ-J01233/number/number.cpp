#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
string s;
int a[maxn],n,m;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(isdigit(s[i]))a[++m]=s[i]-'0';
	}
	sort(a+1,a+1+m);
	for(int i=m;i>=1;i--)printf("%d",a[i]);
	return 0;
}