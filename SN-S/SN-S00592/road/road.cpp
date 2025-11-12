//肖苏焓 SN-S00592 西安铁一中滨河高级中学 
#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,n1,n2,n3,t,minn=10000000,maxx=0;
long long sum1,sum2,sum3;
int flag1[10050],flag2[100010][1010][2],kk[10050],flag3[10050],flag4[10050];
void road(int x,int y,int z){
	if(x>=n1){
		minn=min(minn,z);
		return;
	}
	else{

		for(int i=1;i<=flag1[y];i++){
			
			if(flag3[i]!=-1){
				flag3[flag2[y][i][0]]=-1;
				road(x+1,flag2[y][i][0],z+flag2[y][i][1]);
				flag3[flag2[y][i][0]]=0;
				
				
				
			}
		}
		
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n1>>n2>>n3;
	for(int i=1;i<=n2;i++){
		int a1,a2,a3;
		cin>>a1>>a2>>a3;
		flag1[a1]++;
		flag1[a2]++;
		flag2[a1][flag1[a1]][0]=a2;
		flag2[a1][flag1[a1]][1]=a3;
		flag2[a2][flag1[a2]][0]=a1;
		flag2[a2][flag1[a2]][1]=a3;
		maxx=max(maxx,a1);
	}
//	for(int i=1;i<=maxx;i++){
//		for(int j=1;j<=flag1[i];j++){
//			cout<<i<<" "<<flag2[i][j][0]<<" "<<flag2[i][j][1]<<endl;
//		}
//		
//	}
//	for(int i=n2+1;i<=n2+n3;i++){
//		int a1,a2;
//		cin>>a1;
//		flag4[i]=-1;
//		kk[i]=a1;
//		for(int j=1;j<=n2;j++){
//			int a3;
//			cin>>a3;
//			flag1[i]++;
//			flag1[j]++;	
//			flag2[j][flag1[j]][0]=i;
//			flag2[j][flag1[j]][1]=a3;
//			flag2[i][flag1[i]][0]=j;
//			flag2[i][flag1[i]][1]=a3;
//					
//		}
//	}
	road(1,1,0);
	cout<<minn;
}
