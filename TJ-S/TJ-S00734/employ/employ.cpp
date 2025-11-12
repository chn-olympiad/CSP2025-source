#include<bits/stdc++.h>
using namespace std;
unsigned long long c(int n,int m) {
	unsigned long long sum=1,s=1;
	for(int i=n,j=2; i>n-m; i--) {
		if(j>m) {
			sum*=i;
		} else {
			s*=j;
			if(sum>=s&&sum%s==0&&s!=1) {
				s=1;
				sum/=s;
			} else {
				sum*=i;
			}
			j++;
		}
	}
	return sum/s;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m>n-m) m=n-m;
	cout<<c(n,m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
