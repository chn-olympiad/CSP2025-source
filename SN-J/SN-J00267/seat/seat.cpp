#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m; 
	int a;
	int ans=0;
	int sum=1;
	int cnt=0;
	int num=0;
	int nut=0;
	for(int i=1;i<=n*m;i++){
		cin>>a;
		if(i==1){
			ans=a;
		}
		if(a>ans){
			sum++;
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a>ans){
			sum++;
		}
	}
	if((n*m)/sum==0){
		cnt=(n*m)/sum;
	}
	else{
		cnt=(n*m)/sum+1;
		nut=(n*m)%sum;
	}
	if(cnt%2==1&&(n*m)/sum!=0){
		num=n-(n-sum);
	}
	else if(cnt%2==0&&(n*m)/sum==0){
		num=n;
	}
	else if(cnt%2==0&&(n*m)/sum!=0){
		num=sum;
	}
	else if(cnt%2==1&&(n*m)/sum==0){
		num=1;
	}
	cout<<num<<" "<<cnt;
	return 0;
}
