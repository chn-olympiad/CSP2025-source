#include <bits/stdc++.h>
#include <algorithm> 
using namespace std;
bool cmp(int p,int d){
	return p>d;
}
int arr[105],ans1=0,ans2=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int o = n*m;
	for(int i=1;i<=o;i++){
		cin>>arr[i];
	}
	int y = arr[1];
	sort(arr+1,arr+1+o,cmp);
	int p=0,e=0;
	for(int i=1;i<=o;i++){
		p++;
		if(arr[i]==y){
			break;
		}
	}
	for(int i=o;i>=1;i--){
		e++;
		if(arr[i]==y){
			break;
		}
	}
	if(p%n==0) ans1 = p/n;
	else ans1 = p/n+1;
	ans2 = p%n;
	if(ans1%2!=0){
		ans2 = p%n;
		if(ans2==0) ans2=n;
	}else{
		ans2 = e%n;
		if(ans2==0) ans2=n;
	}
	cout<<ans1<<" "<<ans2; 
	return 0;
}
