#include <bits/stdc++.h>
using namespace std;
string a,b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int t=0;
	for(int i=0;i<a.size();i++)
		if(a[i]>='0'&&a[i]<='9')	t++;
	for(int j=1;j<=t;j++){
		int n=-1,m=-1;
		for(int i=0;i<a.size();i++){
			if(a[i]>='0'&&a[i]<='9'&&a[i]-'0'>n)
				m=i,n=a[i]-'0';
		}
		if(m!=-1&&n!=-1)	b[j]=a[m],a[m]='a';
	}
	for(int j=1;j<=t;j++)
		cout<<b[j];
	return 0;
}
