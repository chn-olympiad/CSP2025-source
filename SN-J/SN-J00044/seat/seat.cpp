#include<bits/stdc++.h>
using namespace std;
int n,m;
bool cmp(int x,int y){
	if(x<y){
		return x>y;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int len=n*m;
	int a[len];
	int num=0;
	for(int i=1;i<=len;i++){
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+len+1,cmp);
	int k;
	for(int i=1;i<=len;i++){
		if(a[i]==num){
			k=i;
		}
	}
	if(k<=n){
		cout<<1<<" "<<k;
	}else{
		if(k%n<=n/2){
			cout<<k/n+1<<" "<<k%n;
		}else{
			if(n%k==1){
				cout<<n/k+1<<" "<<n;
			}else if(k%n==0){
				cout<<k/n<<" "<<n;
			}
		}
	}
}
