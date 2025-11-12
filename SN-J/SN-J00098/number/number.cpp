//LiuShaoAng SN-J00098 XiAnFuLun
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin.tie(0);
	string add;
	cin>>add;
	for(int i=1;i<=add.size();++i){
		max(add[i],add[i+1]);
	}
	cout<<add;
	return 0;
}