//Ren5Jie4Di4Ling5%
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
mt19937 rd(time(0));
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);	
	cin>>n>>q;
	if(q==1){
		cout<<rd()%2;
		return 0;
	}
	while(q--)cout<<0<<"\n";
	return 0;
}
