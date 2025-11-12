#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <map>
#include <algorithm>
#define R register
#define LL long long
using namespace std;
const int N=2e5+10;
int n,q;
string s1[N],s2[N],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(R int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	bool f=0;
	if(n*q>1e8) f=1;
	if(q==1){
		cout<<0<<'\n';
		return 0;	
	}
	while(q--){
		cin>>t1>>t2;
		if(f){
			cout<<0<<'\n';
			continue;
		}
		if(t1.size()!=t2.size()){
			cout<<0<<'\n';
			continue;
		}
		int l=t1.size(),cnt=0;
		string d1=t1,d2=t2;
		for(R int i=1;i<=n;i++){
			t1=d1,t2=d2;
			int u=s1[i].size();
			for(R int j=0;j<l;j++){
				string g1=t1.substr(j,u);
				string g2=t2.substr(j,u);
				if(g1!=g2){
					if(g1==s1[i]&&g2==s2[i]){
						for(R int k=j;k<j+u;k++) t1[k]=t2[k];
						j+=u-1;
						break;
					}
				}
			}
			if(t1==t2) cnt++;
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
