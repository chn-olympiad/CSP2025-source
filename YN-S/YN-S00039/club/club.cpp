#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a[100][100];
	cin>>t;
	for(int z=1;z<=t;z++){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		if(n==2){
			int ts=-1;
			for(int i=1;i<=3;i++){
				int sum=a[1][i];
				for(int j=1;j<=3;j++){
					if(i!=j)
						sum+=a[2][j];
				}
				if(sum>ts)
					ts=sum;
			}
			cout<<ts;
		}
			
	}
		return 0;
}


