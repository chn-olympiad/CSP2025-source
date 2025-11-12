#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
struct node{
	int x,y,z;
	int max_,id_max;
	int max_m,id_max_m;
	int ma_c;
}a[N];
int n,T;
int sum[3];
int as[3];
bool cmp(node x,node y){
	return x.ma_c<y.ma_c;
}
int main (){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].x>a[i].y){
				if(a[i].x>a[i].z){
					a[i].max_=a[i].x;a[i].id_max=0;sum[0]++;as[0]+=a[i].max_;
					if(a[i].y>a[i].z){
						a[i].max_m=a[i].y;a[i].id_max_m=1;
					}else{
						a[i].max_m=a[i].z;a[i].id_max_m=0;
					}
				}
				else{
					a[i].max_=a[i].z;a[i].id_max=2;sum[2]++;as[2]+=a[i].max_;
					a[i].max_m=a[i].x;a[i].id_max_m=0;
				}
			}else{
				if(a[i].y>a[i].z){
					a[i].max_=a[i].y;a[i].id_max=1;sum[1]++;as[1]+=a[i].max_;
					if(a[i].x>a[i].z){
						a[i].max_m=a[i].x;a[i].id_max_m=0;
					}else{
						a[i].max_m=a[i].z;a[i].id_max_m=2;
					}
				}
				else{
					a[i].max_=a[i].z;a[i].id_max=2;sum[2]++;as[2]+=a[i].max_;
					a[i].max_m=a[i].y;a[i].id_max_m=1;
				}
			}
			a[i].ma_c=a[i].max_-a[i].max_m;
		}
		//	cout<<as[0]<<" "<<as[1]<<" "<<as[2]<<endl;
		int ans=as[0]+as[1]+as[2];
		for(int k=0;k<3;k++){
			if(sum[k]>n/2){
				//	cout<<1;
				sort(a+1,a+n+1,cmp);
				//for(int i=1;i<=n;i++)	cout<<a[i].ma_c<<" ";
				for(int i=1;i<=n&&sum[k]>n/2;i++){
					//	cout<<a[i].id_max<<" "<<a[i].id_max_m<<endl;
					if(a[i].id_max!=k)	continue;
					//	cout<<i;
					//	cout<<a[i].ma_c;
					sum[k]--;
					ans-=a[i].ma_c;
				}
			}
		}
		//	cout<<as[0]<<" "<<as[1]<<" "<<as[2]<<endl;
		cout<<ans<<endl;
		for(int i=0;i<3;i++)	sum[i]=as[i]=0;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
2 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/