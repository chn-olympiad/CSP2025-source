#include<bits/stdc++.h>
using namespace std;
int x,y,ans;
string a[200001],b[200001],c,d;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>x>>y;
	for(int i=1;i<=x;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=y;i++){
		cin>>c>>d;
		ans=0;
		for(int j=1;j<=x;j++){
			if(c.size()<a[j].size()||c.find(a[j])==-1) continue;
			if(a[j]==c&&b[j]==d){
				++ans;
			}
			for(int k=1;k<c.size()-a[j].size();k++){
				string o=c.substr(0,k-1),q=c.substr(k+a[j].size(),c.size());
				if(o+b[j]+q==d){
					++ans;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
---------
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/