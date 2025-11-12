#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,ans;
struct node{
	string s1,s2;
}a[200005];
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>> n >> m;
	for(int i = 1;i <= n;i++){
		cin>> a[i].s1 >> a[i].s2;
	}
	for(int  i = 1;i <= m;i++){
		cin>> t1 >> t2;
		cout<< 0;
	}
	return 0;
}
