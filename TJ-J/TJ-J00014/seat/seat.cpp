#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
int s,a[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>s){
			sum++;
		}
	}
	int ss=(sum+1)%n;
	if(ss==0){
		ss=n;
	}
	if(((sum+n)/n)%2==1){
		cout<<(sum+n)/n<<' '<<ss<<endl;
	}else{
		cout<<(sum+n)/n<<' '<<n-ss+1<<endl;
	}
	return 0;
}

