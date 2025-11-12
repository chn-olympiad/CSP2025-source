#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e6+10;
struct node{
	string x,y;
}f[N];
signed main()
{
	
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		f[i].x=a;
		f[i].y=b;
	}
	for(int i=1;i<=q;i++){
		string a,b;
		cin>>a>>b;
		int cnt=0;
		int t=0;
		if(a.size()!=b.size()){
			cout<<0<<"\n";
			t=1;
		}
		if(t==0){
			for(int j=1;j<=n;j++){
				if(a.find(f[i].x)==0&&b.find(f[i].y)==0){
					cnt++;
				}
			}
			cout<<cnt<<"\n";
		}
		
	}
	
	return 0;
}

