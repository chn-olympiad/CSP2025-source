#include<bits/stdc++.h>
using namespace std;
map<int,int> cnt;
int main(){
freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,q;
		cin>>a>>q;
		char b='b';
		int w=a.find(b);
		int w1=q.find(b);
		cnt[(w1-w)]++;
		cout<<cnt[w1-w]<<" ";
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		char t='b';
		int w=a.find(t);
		int w1=b.find(t);
		cout<<cnt[w1-w]<<"\n";
	}
}
