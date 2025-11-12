#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int b[105];
bool cmp1(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n*m+1,cmp1);
	int ans;
	for(int i=1;i<=n*m;i++){
		if(a[1]==b[i]){
			ans=i;
			break;
		}
	}
	int ans1=(ans+n-1)/n,ans2;
	if(ans1%2==0){
		ans2=n+1-((ans-1)%n+1);
	}else{
		ans2=(ans-1)%n+1;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}

