#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat0.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	r=a[1];sort(a+1,a+n*m+1,greater<int>());
	int i=1,j=1,k=1;
	while(a[k]!=r){
		k++;
		if(i==n&&j%2==1||i==1&&j%2==0)j++;
		else if(j&1)i++;
		else i--;
	}
	cout<<j<<' '<<i;
	return 0;
}

