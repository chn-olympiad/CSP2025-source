#include  <bits/stdc++.h>
using namespace std;
int n,m,a[105],sum1,sum2,c,r;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[1];
	r=a[1];
	for(int i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			c=i;
			while(c>0){
				c-=n;
				sum1++;
			}
			if(sum1%2==1) sum2=i-(sum1-1)*n;
			else sum2=n-(i-(sum1-1)*n)+1;
			cout<<sum1<<" "<<sum2;
			break;
		}
	}
	return 0;
}
