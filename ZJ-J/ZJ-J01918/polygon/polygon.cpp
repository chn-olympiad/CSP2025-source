#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,l[6000],lst=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
		lst=max(lst,l[i]);
	}
	if(n==1||n==2) cout<<0;
	if(n==3){
		if(2*lst<l[1]+l[2]+l[3]) cout<<1;
		else cout<<0;
	}
	return 0;
}
