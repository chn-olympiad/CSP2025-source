#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],xiaor,mp[15][15],tot;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i];
	}
	xiaor=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;++i){
		if(a[n*m-i+1]==xiaor){
			xiaor=i;
			break;
		}
	}
	for(int i=1;i<=m;++i){
		if(i%2==1){
			for(int j=1;j<=n;++j){
				mp[i][j]=++tot;
				if(tot==xiaor){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;--j){
				mp[i][j]=++tot;
				if(tot==xiaor){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
//其实这题没什么可诈骗的，仅仅是为了凑字数 
}
