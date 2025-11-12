#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main(){
	freopen("club.in","r",stdin)
	freopen("club.out","w",stdout)
	int x,y;
	int n,m;
	int t;
	cin>>t;
	cin>>n>>m;
	while(t--){
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			int x=max(a,max(b,c));
		}
	}
	for(int i=1;i<=n;i++){
		cout<<x;
	}
	return 0;
} 
