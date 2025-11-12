#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int n;cin>>n;
	while(n--){
		int m;cin>>m;
		int t=0;
		for(int i=1;i<=m;i++){
			int a,b,c;cin>>a>>b>>c;
			t+=max(max(a,b),c);
		}
		cout<<t<<endl;
		
	}
	
	return 0;
} 