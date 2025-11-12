#include<bits/stdc++.h>
using namespace std;

int t,n,ans;
int ren[4][100002]={-1};

void teshu(int n){//baoli
	if(n==2){		
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				if(ans<ren[i][1]+ren[j][2]&&i!=j)
					ans=ren[i][1]+ren[j][2];
			}
		}
	}else if(n==4){
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					for(int l=1;l<=3;l++){
						if((i==j&&i==k)||(i==j&&i==l)||(i==l&&i==k)||(j==l&&j==k))
							continue;	
						if(ans<ren[i][1]+ren[j][2]+ren[k][3]+ren[l][4])
							ans=ren[i][1]+ren[j][2]+ren[k][3]+ren[l][4];
					}
				}
			}
		}
	}else if(n==10){
		for(int i1=1;i1<=3;i1++){
			for(int i2=1;i2<=3;i2++){
				for(int i3=1;i3<=3;i3++){
					for(int i4=1;i4=3;i4++){	
						for(int i5=1;i5<=3;i5++){
							for(int i6=1;i6<=3;i6++){
								for(int i7=1;i7<=3;i7++){
									for(int i8=1;i8<=3;i8++){
										for(int i9=1;i9<=3;i9++){	
											for(int i0=1;i0<=3;i0++){												
												int t=ren[i1][1]+ren[i2][2]+ren[i3][3]+ren[i4][4]+ren[i5][5];
												t+=ren[i1][6]+ren[i2][7]+ren[i3][8]+ren[i4][9]+ren[i5][10];
												if(ans<t)
													ans=t;						
											}
										}
									}
								}
							}							
						}
					}
				}
			}
		}		
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&t);
	
	for(int ci=0;ci<t;ci++){
		ans=-1;
		scanf("%d",&n);
		
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&ren[1][i],&ren[2][i],&ren[3][i]);
		
		teshu(n);
		
		printf("%d\n",ans);
	}
	
	return 0;
} 
