#include<bits/stdc++.h>
using namespace std;
long long n,m,a[20000],ans=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1]){
			ans++;
		}
	}
	int s=(ans-1)/n+1;
	cout<<s<<" ";
	ans-=((ans-1)/n)*n;
	if(s%2){
		cout<<ans;
	}else{
		cout<<n-ans+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
