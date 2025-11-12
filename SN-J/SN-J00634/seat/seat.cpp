#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[105];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	long long h=a[1],b;
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		if(a[i]==h){
			b=m*n-i+1;
		}
	}
	long long hang,lie;
	if(b%n==0){
		lie=b/n;
	}else{
		lie=b/n+1;
	}
	if(lie%2==0){
		hang=n-b&n;
	}else{
		hang=b%n+1;
	}
	cout<<lie<<" "<<hang;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
