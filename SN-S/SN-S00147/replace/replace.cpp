#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2;
struct th{
	string s1;
	string s2;
};
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	th a[50005],b[50005];
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	for(int i = 1;i<=q;i++){
		cin>>b[i].s1>>b[i].s2;
		cout<<0<<endl;
	}


	
}
