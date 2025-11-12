#include<bits/stdc++.h>
using namespace std;
int n,m,ans[110],num;
bool cmp(int a,int b){
	if(a<b)return a>b;
	return a<b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>ans[i];
	int grade=ans[1];
	sort(ans,ans+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(grade==ans[i])num=i;
	}
	int c=num/n+1;
	int r;
	if(c%2==1){
		r=num%n;
	}else{
		r=n-num%n-1;
	}
	cout<<c<<" "<<r;
	return 0;
}
