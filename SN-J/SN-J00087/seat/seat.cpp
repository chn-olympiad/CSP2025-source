#include <bits/stdc++.h>
using namespace std;
bool cmp(int n,int m){
	return n>m;
}
int n,m;
int r,c;
int x[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>x[i];
		if(i==1){
			r=x[i];
		}
	}
	sort(x+1,x+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(x[i]==r){
			c=i;
		}
	}
	int i=1;
	while(c>n){
		c-=n;
		i+=1;
	}
	cout<<i<<' ';
	if(i%2==0){
		cout<<n+1-c;
	}else{
		cout<<c;
	}
    return 0;
}

