#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[105],n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s=a[1];
	for(int i=2;i<=n*m;i++){
		for(int j=1;j<=n;j++){
			if(a[i]>a[j]){
			swap(a[i],a[j]);
		    }
		}
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i*j-])
		}
	}
    return 0;
} 
