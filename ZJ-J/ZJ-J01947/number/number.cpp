#include<bits/stdc++.h>
using namespace std;
string t[1005],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	int l=n.length();
	for(int i=0;i<=l;i++)t[n[i]]+=n[i];
	for(int i=9+'0';i>=0+'0';i--)cout<<t[i];
	return 0;
}
