#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n*m+5];
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}long long x=a[1];
	sort(a+1,a+n*m+1,cmp);
	long long ans_n,ans_m;
	for(long long i=1;i<=n*m;i++){
		if(a[i]==x){
			if(i%n==0){
				ans_n=i/n;
			}else{
				ans_n=i/n+1;
			}
			if(ans_n%2==0){
				ans_m=n-i%n+1;
			}else if(ans_n==1){
				ans_m=n;
			}else{
				ans_m=i%n;
			}
			cout<<ans_n<<" "<<ans_m;
			return 0;
		}
	}
	return 0;
}
