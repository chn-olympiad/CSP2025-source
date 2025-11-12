#include<bits/stdc++.h>
using namespace std;
struct dxdy{
	int manyi,xi;
};
dxdy u[100005],compare[10];
bool cmp(dxdy x,dxdy y){
	if(x.manyi<y.manyi){
		return false;
	}
	if(x.manyi>y.manyi){
		return true;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;
	cin>>t;
	while(t){
		cin>>n;
		int num=n/2;
		for(int i=1;i<=3*n;i++){
			cin>>u[i].manyi;
			if(i%3==0){
				u[i].xi=3;
			}
			else{
				u[i].xi=i%3;
			}
		}
		int u1=0,u2=0,u3=0;
		long long ans=0;
		while(n!=0){
			for(int i=1;i<=3*n;i++){
				for(int j=1;j<=3;j++){
					compare[j].manyi=u[i].manyi;
					compare[j].xi=u[i].xi;
				}
				sort(compare+1,compare+3,cmp);
				for(int j=1;j<=3;j++){
					if(compare[j].xi==1){
						if(u1+1<num){
							u1++;
							ans+=compare[j].manyi;
							n--;
						}
					}
					if(compare[j].xi==2){
						if(u2+1<num){
							u2++;
							ans+=compare[j].manyi;
							n--;
						}
					}if(compare[j].xi==3){
						if(u3+1<num){
							u3++;
							ans+=compare[j].manyi;
							n--;
						}
					}
				}

			}
			cout<<ans;
			return 0;
		}
	}
} 
