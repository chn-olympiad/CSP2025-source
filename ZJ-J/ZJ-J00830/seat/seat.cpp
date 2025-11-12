#include<bits/stdc++.h>
using namespace std;
int a[105];
int cnt,num,ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int t=a[0];
	sort(a,a+n*m);
	for(int i=0;i<n*m;i++){
		if(a[i]==t){
			cnt=i+1;
		}
	}
	cnt=n*m-cnt+1;
	ans=cnt/3+1;
	cout<<ans;
	if(ans%2==1){
		num=cnt-(ans-1)*n;
	}
	else{
		int j=cnt-(ans-1)*n;
		num=n+1-j;
	}
	cout<<" "<<num;
	return 0;
}
