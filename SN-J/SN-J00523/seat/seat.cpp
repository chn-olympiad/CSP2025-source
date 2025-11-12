#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int l=n*m;
	int a[l];
	for(int i=0;i<l;i++){
		cin>>a[i];
	}
	int x=a[0];
	sort(a,a+l);
	int k=l-1;
	while(k>=0){
		for(int i=1;i<=m;i++){
			if(i%2==0){
				for(int j=n;j>=1;j++){	
					if(a[k]==x){	
						cout<<i<<" "<<j;
						return 0;
					}
					k--;
				}
			}
			else{
				for(int j=1;j<=n;j++){
					if(a[k]==x){
						cout<<i<<" "<<j;
						return 0;
					}
					k--;
				}
			}
		}
	}
	//?S??b!!
	return 0;
}
