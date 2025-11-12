#include<bits/stdc++.h>
#define ll long long
 
using namespace std;

const int maxn=1e9;

int n,q;
map<pair<string,string>,int> chg;
string c1[100005],c2[100005];
string core;

int find(string a,string b,string x,string y){
	for(int i=0;i<a.size();i++){
		int j=i,k=0;
		string tmp=a;
		while(tmp[j]==x[k]&&j<tmp.size()&&k<x.size()){
//			j++;k++;
			tmp[j++]=y[k++];
		}
//		cout<<a<<" "<<x<<" "<<tmp<<" "<<b<<" "<<y<<" "<<k<<" "<<i<<"\n";
		if(tmp==b)return 1;
	}
	return -1;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>c1[i]>>c2[i];
//		chg[{a,b}]++;
	}
	for(int i=1;i<=q;i++){
		string a,b;
		cin>>a>>b;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(find(a,b,c1[i],c2[i])!=-1){
				ans++;
			}
		}
		cout<<ans<<"\n";
		
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


*/

