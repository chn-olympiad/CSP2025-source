#include<bits/stdc++.h>
using namespace std;
string s;
int a[1005],c,maxn;

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0; i<l; i++) {
		int n=s[i]-'0';
		if(n>=0 && n<=9) {
			a[n]++;
			maxn=max(maxn,n);
		}
	}
	for(int i=maxn;i>=0;i--){
		int q=a[i];
		if(q){
			for(int j=1;j<=q;j++){
				cout<<i;
			}
		}
	}
	return 0;
}
