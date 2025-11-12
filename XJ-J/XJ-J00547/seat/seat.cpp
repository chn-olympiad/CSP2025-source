#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,m,a[N],p;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int o=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==o){
			p=i;
			break;
		}
	}
	if(p%n!=0){
		cout<<p/n+1<<" ";
		int k=p/n+1;
		if(k%2==0){
			cout<<n-p%n+1;
		}
		else{
			cout<<p%n;
		}
	}
	else{
		cout<<p/n<<" ";
		int k=p/n;
		if(k%2==0){
			cout<<p%n;
		}
		else{
			cout<<n-p%n;
		}
	}
	return 0;
}
