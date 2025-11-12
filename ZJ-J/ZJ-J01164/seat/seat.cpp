#include<bits/stdc++.h>
using namespace std;
int const N=1e5+5;
long long n,m,sum,a[N];
long long l,r,mid,pos,res;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	sum=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sum){
			pos=i;
			break;
		}
	}
	if(pos%n!=0) res=pos%n;
	else res=n;
	if((pos+n-1)/n%2==1){
		cout<<(pos+n-1)/n<<" "<<res;
	}else{
		cout<<(pos+n-1)/n<<" "<<n-res+1;
	}
	return 0;
}
