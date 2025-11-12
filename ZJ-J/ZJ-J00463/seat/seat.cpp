#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	int a[105];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int k = a[0];
	sort(a,a+n*m,greater<int>());
	
	int t;
	for(int i=0;i<n*m;i++){
		if(a[i]==k){
			t=i;
		}
	}
	int x;
	int y = t/n+1;
	if(y&1){
		x = t%n+1;
	}
	else{
		x = n-t%n;
	}
	cout<<y<<" "<<x;
	
	return 0;
}
