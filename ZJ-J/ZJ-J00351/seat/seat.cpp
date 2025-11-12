#include<iostream>
#include<algorithm>
using namespace std;
int h,l,a[1005],n,m,t,mc=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])mc++;
	}
	int lie=mc/n+(mc%n!=0);
	t=mc%n;
	if(t==0)t=n;
	if(lie%2==1){
		cout<<lie<<' '<<t;
	}else{
		cout<<lie<<' '<<n-t+1;
	}
	return 0;
}