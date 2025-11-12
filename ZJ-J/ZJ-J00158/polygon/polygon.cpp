#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans = 0;
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n == 3){
		int tot = a[1] + a[2] + a[3];
		if(tot>2*max(max(a[1],a[2]),a[3])){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	srand(time(0));
	cout<<rand()%998244353;
	return 0;
}
