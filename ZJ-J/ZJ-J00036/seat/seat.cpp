#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int s[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>cnt;
	s[1]=cnt;
	for(int i=2;i<=n*m;i++){
		cin>>s[i];
	}
	sort(s+1,s+1+n*m,greater<int>());
	int l=1,r=n*m;
	int mid;
	while(l<r){
		mid=(l+r+1)/2;
		if(s[mid]>=cnt){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<(l+n-1)/n<<' ';
	if((l+n-1)/n%2==0){
		cout<<n-l+l/n*n+1<<'\n';
	}else{
		cout<<l-l/n*n+n*(l-l/n*n==0)<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
