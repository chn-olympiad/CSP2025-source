#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;int x,R,c=0;cin>>R;
	for(int i=1;i<n*m;i++){
		cin>>x;
		if(x>R)c++;
	}
	int ans=(c/m)%2==0?c%m+1:m-c%m;
	cout<<c/m+1<<' '<<ans<<endl;
	return 0;
}
