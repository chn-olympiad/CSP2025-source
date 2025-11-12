#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string list[n][2];
	for (int i=0;i<n;i++) {
		cin>>list[i][0]>>list[i][1];
	}
	while (q--) {
		string a,b,c;
		cin>>a>>b;
		int cnt=0;
		for (int j=0;j<a.length();j++) {
			for (int i=1;i<=a.length();i++) {
				c=a.substr(j,i);
				string na=a;
				for (int p=0;p<n;p++) {
					if (list[p][0]==c) {
						na.replace(j,i,list[p][1]);
						if (na==b) {
							cnt+=1;
						}
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
