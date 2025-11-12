#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[1005];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;++i){
		cin>>a[i];
	}
	long long t=a[1],id=0;
	sort(a+1,a+1+n*m,cmp);
	for(long long i=1;i<=n*m;++i){
		if(a[i]==t){
			id=i;
			break;
		}
	}
	for(long long i=1;i<=m;++i){
		if(i%2==1){
			for(long long j=1;j<=n;++j){
				if((i-1)*n+j==id){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(long long j=n;j>=1;--j){
				if((i-1)*n+(n-j+1)==id){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

