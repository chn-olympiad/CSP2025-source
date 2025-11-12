#include<bits/stdc++.h>
using namespace std;
long long n,q;
string pq[200001][3];
string qu[200001][3];
map <pair<string,string>,bool> mp;
long long b1,b2;
long long ans;
string t11,t12,t21,t22,t31,t32,t41,t42;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++) {
		cin>>pq[i][1]>>pq[i][2];
		mp[make_pair(pq[i][1],pq[i][2])]=true;
	}
//	cout<<"GOOD"<<"\n";
	for (int i=1;i<=q;i++) {
		cin>>qu[i][1]>>qu[i][2];
		b1=0,b2=0;
		while (qu[i][1][b1]!='b') b1++;
		while (qu[i][2][b2]!='b') b2++;
//		cout<<"#"<<b1<<' '<<b2<<"\n";
		for (int j=b1;j<=b2;j++) t11[(j-b1)]=qu[i][1][j];
		for (int j=b1;j<=b2;j++) t12[(j-b1)]=qu[i][2][j];
//		for (int j=b1;j<=b2;j++) cout<<t11[(j-b1)];
//		cout<<' ';
//		for (int j=b1;j<=b2;j++) cout<<t12[(j-b1)];
//		cout<<"\n";
//		cout<<t11[0]<<' '<<t12[0]<<"\n";
		if (mp[make_pair(t11,t12)]) ans++;
		for (int j=0;j<=b2;j++) t21[j]=qu[i][1][j];
		for (int j=0;j<=b2;j++) t22[j]=qu[i][2][j];
		if (mp[make_pair(t21,t22)]) ans++;
		for (int j=b1;j<=qu[i][1].length();j++) t31[(j-b1)]=qu[i][1][j];
		for (int j=b1;j<=qu[i][2].length();j++) t32[(j-b1)]=qu[i][2][j];
		if (mp[make_pair(t31,t32)]) ans++;
		for (int j=0;j<=qu[i][1].length();j++) t41[j]=qu[i][1][j];
		for (int j=0;j<=qu[i][2].length();j++) t42[j]=qu[i][2][j];
		if (mp[make_pair(t41,t42)]) ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
/*
4 1
abaa aaba
ba ab
aba aab
baa aba
abaa aaba
*/