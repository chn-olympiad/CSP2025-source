#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[107];
bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==ans){
			ans=i;
			break;
		}
	}
	int lie;
	if(ans%n!=0) lie=ans/n+1;
	else lie=ans/n;
	if(lie%2==0) cout<<lie<<" "<<n-(ans%n)+1;
	else{
		if(ans%n==0) cout<<lie<<" "<<n;
		else cout<<lie<<" "<<ans%n;
	}
	return 0;
}
