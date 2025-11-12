//SN-J00794 王美萱 西安市曲江第一学校 
#include<bits/stdc++.h>
using namespace std;
int n,m,shu,pai;
int a[120];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	shu=n*m;
	for(int i=1;i<=shu;i++){
		cin>>a[i];
	}
	int xr=a[1];
	sort(a+1,a+1+shu,cmp);
	for(int j=1;j<=shu;j++){
		if(a[j]==xr){
			pai=j;
			break;
		}
	}
	if(pai%n==0){
		if((pai/n)%2==1){
			cout<<pai/n<<" "<<n;
			return 0;
		}
		else{
			cout<<pai/n<<" "<<"1";
			return 0;
		}
	}
	if(pai%n==1){
		if((pai/n+1)%2==0){
			cout<<pai/n+1<<" "<<n;
			return 0;
		}
		else{
			cout<<pai/n+1<<" "<<"1";
			return 0;
		}
	}
	for(int i=1;i<=n-1;i++){
		if(pai%n==i){
			if((pai/n+1)%2==0){
				cout<<pai/n+1<<" "<<n-i+1;
				return 0;
			}
			else{
				cout<<pai/n+1<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
