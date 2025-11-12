#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100001];
int temp,P;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n*m;i++){
		cin>>a[i];
	}
	temp=a[0];
	sort(a,a+n*m);
	//for (int i=0;i<n*m;i++){
	//	cout<<a[i];
	//}
	for (int i=n*m;i>=0;i--){
		if (a[i]!=temp){
			P++;
		}
		else {
			break;
		}
	}
	//cout<<P<<endl;
	if (P<=n){
		cout<<1<<" "<<n;
		return 0;
	}
	if ((P/n)%2==1){
		cout<<P/n+1<<" "<<n-(P%n-1);
		//cout<<endl<<'1';
	}
	else{
		cout<<P/n+1<<" "<<P%n;
		//cout<<endl<<'2';
	}
	return 0;
}
