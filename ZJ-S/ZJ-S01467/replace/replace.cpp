#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n,q;
string x,y,a,b;
unordered_map<string,unordered_map<string,int> >mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		int l=0,r=x.length()-1;
		while(x[l]==y[l]) l++;
		while(x[r]==y[r]) r--;
		a.clear(),b.clear();
		for(int j=l;j<=r;j++) a+=x[j],b+=y[j];
		mp[a][b]++;
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		int l=0,r=x.length()-1;
		while(x[l]==y[l]) l++;
		while(x[r]==y[r]) r--;
		a.clear(),b.clear();
		for(int j=l;j<=r;j++) a+=x[j],b+=y[j];
		cout<<mp[a][b]<<endl;
	}
	return 0;
}