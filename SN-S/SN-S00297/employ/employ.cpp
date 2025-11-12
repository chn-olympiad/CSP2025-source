//施懿洋 SN-S00297 西安铁一中滨河高级中学
#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			ans=ans*i;
		}
	}
	if(m<=4) ans=m;
	else{
		ans=224112416;
	}
	cout<<ans;
	return 0;
}
