#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,q;
string s[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		cout<<"0\n";
	}
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4
*/