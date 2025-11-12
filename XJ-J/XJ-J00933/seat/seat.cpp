#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
int score;
bool cmp(int a,int b){
	return a>b;
}
int num;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;i++){
		cin>>a[i];
	}
	score=a[1];

	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==score){
			
			num=i;
			break;
		}
	}
	if(num<=n){
		cout<<1<<" "<<num;
	}
	else if(num%n==0){
		if((num/n)%2==1){
			cout<<num/n<<' '<<n; 
		}
		else{
			cout<<num/n<<' '<<1;
		}
	}
	else if((num/n+1)%2==1){
		cout<<num/n+1<<' '<<num%n;
	}
	else {
		cout<<num/n+1<<' '<<n-num%n+1;
	}
	return 0;
}
