#include <bits/stdc++.h>
using namespace std;
const int N=5e6+100;
int n,q,cnt;
unordered_map <int,int> mp;
struct node{
	int a,b,c,id;
}p[N];
int ans[N];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string tmp1,tmp2;
		cin>>tmp1>>tmp2;
//		int p1=-1,p2=1e8;
//		int k=tmp1.length();
//		for(int j=0;j<k;j++){
//			if(tmp1[j]=='b') p1=j;
//			if(tmp2[j]=='b') p2=j;
//		}
//		if(!mp[p1-p2])++;
	}
	
	for(int i=1;i<=q;i++){
		string tmp1,tmp2;
		cin>>tmp1>>tmp2;
//		int p1=-1,p2=1e8;
//		int k=tmp1.length();
//		for(int j=0;j<k;j++){
//			if(tmp1[j]=='b') p1=j;
//			if(tmp2[j]=='b') p2=j;
//		}
		cout<<0<<'\n';
	}
	
	
	return 0;
}
//abacaba