#include<bits/stdc++.h>
using namespace std;
int m,n,a[100],b,temp;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
    for(int i=0;i<n*m;i++){
    	cin>>a[i];
	}
	b=a[0];
	for(int j=1;j<=n*m;j++){
		if(a[j]<a[j+1]){
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
		if(a[0]==b){
			cout<<1<<" "<<1;
			return 0;
		}
		for(int x=1;x<=n;x++){
			for(int y=1;y<=m;y++){
				if(y==m&&a[2]==b){
					cout<<n<<" "<<n;
					return 0;
				}
				else if(a[n]==b){
					cout<<x+1<<" "<<y;
					return 0;
				}
			}
		}
	}
    return 0;
}

