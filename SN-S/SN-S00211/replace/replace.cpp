#include<bits/stdc++.h>
#define ld long double
using namespace std;
const int maxn=1e5+10;
const int inf=1e18;
string a[maxn][2];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	while(m--){
		string x,y;
		cin>>x>>y;
		if(x==y){
			int f=1;
			for(int i=1;i<=n;i++){
				if(a[i][1]==x&&a[i][2]==y){
					cout<<"1\n";
					f=0;
					break;
				}
			}
			if(f){
				cout<<"0\n";
			}
		}
		else{
			cout<<"0\n";
		}
	} 
	return 0;
}
