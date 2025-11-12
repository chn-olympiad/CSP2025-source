#include<bits/stdc++.h>
using namespace std;
int a[1010];
string n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.size();i++) a[int(n[i]-'0')]++;
	for(int i=11;i>=0;i--){
		int k=a[i];
		while(k!=0){
			cout<<i;
			k--;
		}
	}
	return 0;
}
