#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
long long n,k,hang,lie,a[100000],m,t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			lie=(i-1)/n+1;
			if(lie%2==0){
			k=i%n;
			if(k==0){
				hang=1;
			}
			else{
				hang=n-k+1;
			}
			}
			else{
				k=i%n;
				if(k==0){
					hang=n;
				}
				else{
					hang=k;
				}
			}
			break;
		}
	}
	cout<<lie<<" "<<hang;
	return 0;
}
