#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string a;
	cin>>a;
	int n=a.size();
	int b[n],e=0;
	for(int i=0;i<n;i++){
		if(a[i]>=48&&a[i]<=57){
			b[e]=a[i]-'0';
			e++;
		}
	}
	sort(b,b+e);
	for(int i=e-1;i>=0;i--) cout<<(int) b[i];
	cout<<'\n';
	return 0;
}
