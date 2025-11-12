#include <bits/stdc++.h>
using namespace std;

string s;
int a[1000010],ans[1000010];
int t=0,anst=0,sum=0;

inline void mymax() {
	int ma=-5,bh=0;
	for(int j=1; j<=t; j++) {
		if(a[j]!=-1) {
			if(a[j]>ma) {
				ma=a[j];
				bh=j;
			}
		}
	}
	anst++;
	ans[anst]=ma;
	a[bh]=-1;
	sum--;
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int l=s.size();
	for(int i=0; i<l; i++) {
		if(s[i]>='0'&&s[i]<='9') {
			t++;
			a[t]=s[i]-'0';
		}
	}
	sum=t;
	while(sum>0) {
		mymax();
	}
	for(int i=1; i<=anst; i++) {
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
