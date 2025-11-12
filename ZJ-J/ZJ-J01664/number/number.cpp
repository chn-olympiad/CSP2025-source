#include <bits/stdc++.h>
using namespace std;
int a[1000010],i,n,k;
string st;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>st;
	n=st.size();
	for(i=0;i<n;i++)
		if(st[i]>='0'&&st[i]<='9') a[++k]=st[i]-48;
	sort(a+1,a+1+k);
	for(i=k;i>=1;i--) cout<<a[i];
	return 0;
}
