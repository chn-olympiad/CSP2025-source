#include<bits/stdc++.h>
using namespace std;
long long i,a[2000],n,m,t,ans=0,j;
bool cmp(long long q,long long p){
	if (q>=p) return 1;
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (i=1;i<=n*m;i++)
		cin>>a[i];
	t=a[1];
	sort(a+1,a+1+n*m,cmp);
	for (i=1;i<=m;i++){
		if (i%2==0){
			for (j=n;j>=1;j--){
				ans++;
				if (a[ans]==t){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for (j=1;j<=n;j++){
				ans++;
				if (a[ans]==t){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
