#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r,cnt;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(i==0)
		r=a[i];
	}
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(r==a[i])
		cnt=i+1;
	}
    int m1,n1;
	if(cnt%n!=0){
		m1=cnt/n+1;
		if(m1%2!=0){
		if(cnt!=n)
		 n1=cnt%n;
		else
		 n1=n;
		}
		else{
		if(cnt%4==0)
			n1=1;
		else
		n1=n+1-cnt%n;
		}
	}
	else
	{
		m1=cnt/n;
		if(m1%2!=0)
			n1=n;
		else
		n=1;
	}
	cout<<m1<<" "<<n1;
}