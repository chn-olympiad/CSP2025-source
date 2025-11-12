#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,y,a1;
	vector<int> a;
	cin>>n>>m;
	cin>>a1;
	a.push_back(a1);
	for(int i=2;i<=n*m;i++){
		int b;
		cin>>b;
		a.push_back(b);
	}
	sort(a.rbegin(),a.rend());
	for(int i=1;i<=n*m;i++){
		if(a[i-1]==a1){
			x=ceil(i/double(n));
			y=i%n;
			if(x%2==1){
				y=i%n;
				if(y==0){
					y=n;
				}
			}else if(x%2==0){
				y=n-i%n+1;
				
			}
			break;
		}
	}
	cout<<x<<' '<<y;
	return 0;
}
