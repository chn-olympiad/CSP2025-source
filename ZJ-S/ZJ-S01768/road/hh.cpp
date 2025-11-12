#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	srand(time(0));
	freopen("road5.in","w",stdout);
	cout<<10000<<' '<<1000000<<' '<<10<<'\n';
	for(int i=1;i<=1000000;i++){
		cout<<i%10000+1<<' '<<((i+1)%10000+1)<<' '<<rand()*rand()<<'\n';
	}
	for(int i=1;i<=10;i++){
		cout<<1000000000<<' ';
		for(int j=1;j<=10000;j++) cout<<100000000<<' ';
	}
	return 0;
}

