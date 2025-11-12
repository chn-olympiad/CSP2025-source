#include<bits/stdc++.h>
using namespace std;
long long b[2000000],sum;
string a,c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9') b[++sum]=a[i]-'0';
	}
	sort(b+1,b+sum+1);
	for(int i=sum;i;i--) cout<<b[i];
	return 0;
}
