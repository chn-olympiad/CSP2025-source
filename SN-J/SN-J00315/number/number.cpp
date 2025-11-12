#include<bits/stdc++.h>
using namespace std;
int opp=1,c[10005];
string a;
bool tmp(int a,int b) {
	return a>b;
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i=0,r=0;
	cin>>a;
	opp=a.length();
	for(i=0; i<opp; i++) {
		if(a[i]<='9'&&a[i]>='0') {
			c[r]=a[i]-'0';
			//cout<<c[r]<<endl;
			r++;

		}
	}
//	for(i=0;i<r;i++)
//	cout<<c[i]<<" ";
	sort(c,c+r,tmp);//cout<<r<<endl;

	for(i=0; i<r; i++)
		cout<<c[i]/*<<" "8*/;
	return 0;
}
