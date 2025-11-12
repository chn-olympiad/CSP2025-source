#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,pos,y;
	cin>>n>>m;
	y=n*m;
	vector<int>a(y); 
	for(int i=0;i<y;i++){
		cin>>a[i];
	}
	x=a[0];
	sort(a.rbegin(),a.rend());
	for(int i=0;i<y;i++){
		if(a[i]==x){
			pos=i+1;
		}
	}
	if(((pos+n-1)/n)%2==1){
		cout<<(pos+n-1)/n<<' ';
		if(pos%n==0)cout<<n;
		else cout<<pos%n;
	}
	else {
		cout<<(pos+n-1)/n<<' ';
		if(pos%n==0)cout<<1;
		else cout<<n-(pos%n)+1;
	}
	return 0;
} 
