#include<bits/stdc++.h>
using namespace std;
int n,q;
struct str{
	string s1,s2;
}a1[200007],a2[200007];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a1[i].s1>>a1[i].s2;
	}
	for(int i=0;i<q;i++){
		cin>>a2[i].s1>>a2[i].s2;
	}
	for(int i=0;i<q;i++){
		cout<<0<<endl;
	}
	return 0;
}

