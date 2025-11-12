#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200001],s2[200001],f[5000001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<"\n";
			continue;
		}
		string xx1,zz1,xx2,zz2;
		int cnt=0;
		for(int i=1;i<=n;i++){
			int x=t1.find(s1[i]);
			int y=t2.find(s2[i]);
			if(x==-1||y==-1||(x!=y))continue;
			xx1=t1.substr(0,x);
			xx2=t2.substr(0,y);
			zz1=t1.substr(x+s1[i].size(),t1.size()-x-s1[i].size());
			zz2=t2.substr(y+s2[i].size(),t2.size()-y-s2[i].size());
			if(xx1==xx2&&zz1==zz2)cnt++;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}