#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	std::cin>>n>>m;
	std::vector<int> a(n*m);
	for(int i=0; i<n*m; i++) {
		std::cin>>a[i];
	}
	int x=a[0];
	sort(a.rbegin(),a.rend());
	int num=0;
	for(int i=0; i<n*m; i++) {
		if(a[i]==x) {
			num=i+1;
		}
	}
	if(num%n==0) {
		std::cout<<num/n<<" ";
		if(num/n%2==0) {
			std::cout<<1;
		} else {
			std::cout<<n;
		}
	} else {
		std::cout<<num/n+1<<" ";
		if((num/n+1)%2) {
			std::cout<<num%n;
		} else {
			std::cout<<m-num%n+1;
		}
	}
	return 0;
}
