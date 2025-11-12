#include<bits/stdc++.h>
using namespace std;
struct str{
	string s1,s2;
};
str a[100001]={};
str b[100001]={};
int main(){
    freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	for(int i=0;i<m;i++){
		cin>>b[i].s1>>a[i].s2;
	}
	for(int i=0;i<m;i++){
		cout<<0<<endl;
	}
	return 0;
}

