#include<bits/stdc++.h>
using namespace std;
int N=10010;
int xiua[10010];
int xiub[10010];
int xiuc[10010];
int xiuxiu[10010][3];
int ans=0;
void csh(int ab[],int longs){
	for(int i=0;i<longs;i++){
		ab[i]=0;
	}
}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		int n;
		cin>>n;
		ans=0;
		 for(int i=0;i<n;i++){//输入并排序 xiuxiu为排序结果 
		 	cin>>xiua[i]>>xiub[i]>>xiuc[i];
		 	
			 
		 	if(xiua[i]>=xiub[i]){//xiua大于xiub 
		 		if(xiua[i]>=xiuc[i]){//xiua大于xiuc 
		 			xiuxiu[i][0]=0;
		 			if(xiub[i]>=xiuc[i]){//xiua xiub xiuc 
		 				xiuxiu[i][1]=2;
		 				xiuxiu[i][2]=3;
					 }
					 else{//xiua xiuc xiub 
					 	xiuxiu[i][1]=3;
					 	xiuxiu[i][2]=2;
					 }
				}
				else{//xiua小于xiuc
				  xiuxiu[i][0]=2;
				  xiuxiu[i][1]=0;//xiuc xiua xiub
				  xiuxiu[i][2]=1;
				} 
			 }
			 else{//xiua小于xiub
			  if(xiua[i]>=xiuc[i]){//xiua大于xiuc 
			  xiuxiu[i][0]=1;
			  xiuxiu[i][1]=0;//xiub xiua xiuc
			  xiuxiu[i][2]=2; 
			  }
			  else{//xiua小于xiuc(xiua垫底) 
			  	xiuxiu[i][2]=0;
				if(xiub[i]>=xiuc[i]){//xiub大于xiuc 
					xiuxiu[i][0]=1;//xiub xiuc xiua
					xiuxiu[i][2]=2;
				}
				else{//xiub小于xiuc
				xiuxiu[i][0]=2;
				xiuxiu[i][1]=1;//xiuc xiub xiua 
				}
			  }
			 }
		}
		//排序结束*/
		for(int i=0;i<n;i++){//统计 
			if(xiuxiu[i][0]==0){
				ans+=xiua[i];
			//	tj0++;
			}
			if(xiuxiu[i][0]==1){
				ans+=xiub[i];
			//tj1++;
			}
			if(xiuxiu[i][0]==2){
				ans+=xiuc[i];
			//tj2++;
			}
		}
		cout<<ans;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
