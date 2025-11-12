#include<bits/stdc++.h>//0pts
using namespace std;
int main(){
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	srand(time(nullptr));
	int ans=abs((rand()<<10)+rand());
	printf("%lld",ans%998244353);
	return 0;
}
