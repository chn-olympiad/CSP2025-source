//刘庭宇 西安市高新第一学校 SN-J00106
#include<bits/stdc++.h>
using namespace std;
int n,a[5010],js,ls;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	js=max(a[1],max(a[2],a[3]));
	if(js*2<a[1]+a[2]+a[3])cout<<1;
	else cout<<0;
	return 0;
}
