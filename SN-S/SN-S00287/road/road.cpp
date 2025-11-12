//惠子轩  SN-S00287  西安铁一中滨河高级中学 
#include <bits/stdc++.h>
using namespace std;
int n, m, k,p=0;
int main(){
	freopen("road","r",stdin);
	freopen("road","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++){
		int ui,vi,wi;
		cin>>ui>>vi>>wi;
		p+=wi;
	}
	
cout<<	p;
	
	return 0;
}
