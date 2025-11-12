#include <bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int t,n;
struct Node{
	int d1,d2,d3;
}stu[N];
long long ans=0;
long long tmp1,tmp2,tmp3;

bool cmp(Node x,Node y){
	if(x.d1!=y.d1) return x.d1>y.d1;
	else if(x.d2!=y.d2) return x.d2>y.d2;
	else return x.d3>y.d3;
}
int main(){
	
	freopen("club.in","r",stdin);//Òª¸Ä 
	freopen("club.out","w",stdout);
	
	scanf("%d",&t);
	while(t--){
		
		ans=0;
		
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&stu[i].d1,&stu[i].d2,&stu[i].d3);
		}
		
		sort(stu+1,stu+n+1,cmp);
		
//		cout<<endl;
//		for(int i=1;i<=n;i++){
//			printf("%d %d %d\n",stu[i].d1,stu[i].d2,stu[i].d3);
//		}
//		cout<<endl;
		int deadline=n/2;
//		cout<<deadline<<endl;
		tmp1=0;
		for(int i=1;i<=deadline;i++){
			tmp1+=stu[i].d1;
			tmp2=0;
//			cout<<i<<endl;
			for(int j=i+1;j<=i+1+deadline&&j<=n;j++){
				tmp2+=stu[j].d2;
				tmp3=0;
//				cout<<j<<endl;
				for(int z=j+1;z<=j+1+deadline&&z<=n;z++){
					tmp3+=stu[z].d3;
				}
//				cout<<tmp1<<" "<<tmp2<<" "<<tmp3<<endl;
				ans=max(ans,tmp1+tmp2+tmp3);
			}
		}
		
		tmp1=0;
		for(int i=1;i<=deadline;i++){
			tmp1+=stu[i].d2;
			tmp2=0;
			for(int j=i+1;j<=i+1+deadline&&j<=n;j++){
				tmp2+=stu[j].d1;
				tmp3=0;
				for(int z=j+1;z<=j+1+deadline&&z<=n;z++){
					tmp3+=stu[z].d3;
				}
				ans=max(ans,tmp1+tmp2+tmp3);
			}
		}
		
		tmp1=0;
		for(int i=1;i<=deadline;i++){
			tmp1+=stu[i].d3;
			tmp2=0;
			for(int j=i+1;j<=i+1+deadline&&j<=n;j++){
				tmp2+=stu[j].d2;
				tmp3=0;
				for(int z=j+1;z<=j+1+deadline&&z<=n;z++){
					tmp3+=stu[z].d1;
				}
				ans=max(ans,tmp1+tmp2+tmp3);
			}
		}
		
		tmp1=0;
		for(int i=1;i<=deadline;i++){
			tmp1+=stu[i].d2;
			tmp2=0;;
			for(int j=i+1;j<=i+1+deadline&&j<=n;j++){
				tmp2+=stu[j].d3;
				tmp3=0;
				for(int z=j+1;z<=j+1+deadline&&z<=n;z++){
					tmp3+=stu[z].d1;
				}
				ans=max(ans,tmp1+tmp2+tmp3);
			}
		}
		
		tmp1=0;
		for(int i=1;i<=deadline;i++){
			tmp1+=stu[i].d3;
			tmp2=0;
			for(int j=i+1;j<=i+1+deadline&&j<=n;j++){
				tmp2+=stu[j].d1;
				tmp3=0;
				for(int z=j+1;z<=j+1+deadline&&z<=n;z++){
					tmp3+=stu[z].d2;
				}
				ans=max(ans,tmp1+tmp2+tmp3);
			}
		}
		
		tmp1=0;
		for(int i=1;i<=deadline;i++){
			tmp1+=stu[i].d1;
			tmp2=0;
			for(int j=i+1;j<=i+1+deadline&&j<=n;j++){
				tmp2+=stu[j].d3;
				tmp3=0;
				for(int z=j+1;z<=j+1+deadline&&z<=n;z++){
					tmp3+=stu[z].d2;
				}
				ans=max(ans,tmp1+tmp2+tmp3);
			}
		}
		
		cout<<ans<<endl;
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/ 
