#include<bits/stdc++.h>
using namespace std;
int n,m,a[120],a1,id,r,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)scanf("%d",a+i);
	a1=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			id=i;
			break;
		}
	}
	c=((id-1)/n+1);
	cout<<c;
	if(c&1){
		cout<<' '<<((id-1)%n+1);
	}else{
		cout<<" "<<n-((id-1)%n+1)+1;
	}
	
	return 0;
}

