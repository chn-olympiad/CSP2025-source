#include<bits/stdc++.h>
using namespace std;
int a[10001],n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int n1=1,m1,sum,t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			sum=i;
			break;
		}
	}
	m1=sum/n;
	if(sum%n!=0)m1++;
	if(m1%2==0){
		n1=n-(sum-sum/n*n)+1;
	}else{
		n1=sum;
		if(sum>n)n1-=sum/n*n;
	}
	cout<<m1<<' '<<n1;
	return 0;
} 
