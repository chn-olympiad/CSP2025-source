//SN-J01215 齐睿渊  富平县怀德初级中学 
#include<bits/stdc++.h>
using namespace std;
int a[110];
int cmpp(int x,int y){
	return x>y;
}

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int num;
	cin>>num;
	a[1]=num;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmpp);
	int lio=1;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n,z=lio;j>=1,z<=n*i;j--,z++){	
				if(a[z]==num){
					cout<<i<<" "<<j;
					break;
				}
			}
		}else{
			for(int j=1,z=lio;j<=n,z<=n*i;j++,z++){	
				if(a[z]==num){
					cout<<i<<" "<<j;
					break;
				}	
			}
		}
		
		lio+=n;
	}
	return 0;
}
