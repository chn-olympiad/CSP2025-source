#include<bits/stdc++.h>
using namespace std;
int n,m,R,x,ans;
int main(){
	freopen("seat3.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	vector<int> a(n*m);
	cin>>R;
	a[0]=R;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	for(long unsigned int i=0;i<a.size();i++){
		if(a[i]==R){
			x=a.size()-i;
			break;
		}
	}
	if(x%n){
		ans=x/n+1;
	}
	else{
		ans=x/n;
	}
	cout<<ans;
	cout<<" ";
	if(ans%2){
		if(x%n){
			cout<<x%n;
		}
		else{
			cout<<n;
		}
	}
	else{
		if(x%n){
			cout<<n+1-(x%n);
		}
		else{
			cout<<"1";
		}
	}
	return 0;
}

