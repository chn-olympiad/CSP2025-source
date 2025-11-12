#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("road.in","r",stdout);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int w,a,c;
	cin>>w>>a>>c;
	int ans=0,sum=0;
	for(int i=1;i<=m;i++){
		ans+=w;
	}
	for(int j=1;j<=k;j++){
		sum=sum+a+c;
	}
	if(ans>sum){
		cout<<ans;
    }else if(ans<sum){
		cout<<sum;
	}else{
		cout<<ans;
	}
	return 0;
}
