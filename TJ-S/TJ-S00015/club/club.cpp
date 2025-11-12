#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct di{
	int b,c;
};
bool cmp(di x,di y){
	return x.c<y.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	int a[100009][3];
	int t;
	cin>>t;
	int sum[4]={0},maxn=0;
	di u[100009];
	int summ=0;
	while(t--){
		cin>>n;
		sum[0]=sum[1]=sum[2]=0;
		summ=0;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			maxn=max(a[i][0],max(a[i][1],a[i][2]));
			summ+=maxn;
			for(int j=0;j<3;j++){
				if(maxn==a[i][j]){
					sum[j]++;
					u[i].b=j;
					u[i].c=a[i][j]-max(a[i][(j+1)%3],a[i][(j+2)%3]);
					break;
				}				
			}
		}
		sort(u,u+n,cmp);
		for(int i=0;i<3;i++){
			if(sum[i]>n/2){
//				cout<<"a";
				for(int j=0;j<n;j++){
					if(u[j].b==i){
//						cout<<j<<' '<<u[j].c<<endl;
						sum[i]--;
						summ-=u[j].c;
					}
					if(sum[i]==n/2){
						break;
					}
				}
				break;
			}
		}
		printf("%d\n",summ);
	}
	return 0;
}
