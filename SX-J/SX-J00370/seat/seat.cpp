#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long t=n*m;
	for(int i=1;i<=t;i++){
		cin>>a[i];
	}
	int k=a[1];
	int s=0;
	sort(a+1,a+t+1);
	for(int i=1;i<=t;i++){
		if(a[i]==k)s=i;
	}
	s=t-s+1;
	long long q=s/n;
	long long p=s%n;
	long long lie=q+1;
	long long heng;
	if(p==0){
		lie--;
		p=n;
	}
	if(lie%2==0)heng=n-p+1;
	else heng=p;
	cout<<lie<<" "<<heng;
	return 0;
}