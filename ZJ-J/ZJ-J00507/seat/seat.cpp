#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,m;
int a[10001];
int lin;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			lin=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	int l=1,r=n*m;
	while(l<r){
		int mid=(l+r)/2;
		if(a[mid]>lin){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
//	cout<<"l's val "<<l<<endl;
	if((l/n)%2==0&&l%n!=0){
		cout<<l/n+1<<" "<<l%n;
	}
	else if((l/n)%2==1&&l%n!=0){
		cout<<l/n+1<<" "<<m-(l%n)+1;
	}
	else if((l/n)%2==0&&l%n==0){
		cout<<l/n<<" "<<1;
	}
	else if((l/n)%2==1&&l%n==0){
		cout<<l/n<<" "<<m;
	}
	return 0;
}