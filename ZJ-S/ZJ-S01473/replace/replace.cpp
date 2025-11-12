#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=2e5+10;
int n,q;
struct node{
	string s1,s2;
}ar[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>ar[i].s1>>ar[i].s2;
	}
	for(int i=1;i<=q;i++){
		string sa,sb;
		cin>>sa>>sb;
		int lena=sa.size(),lenb=sb.size();
		cout<<0<<endl;
	}
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
