//南亭序 SN-S00092 西安市第二十五中学 																																																																				ccf cnm 
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	 
	int t;
	scanf("%d",&t);
	for(int u=1;u<=t;u++){
		int n=0,N[100005][4],C1=0,C2=0,C3=0,a=0,b=0,c=0;
		scanf("%d",&n);
		vector<int> c1(100005,0);
		vector<int> c2(100005,0);
		vector<int> c3(100005,0);
		for(int i = 1; i <= n; i++){
			scanf("%d %d %d",&N[i][1],&N[i][2],&N[i][3]);
			if(max(N[i][1],max(N[i][2],N[i][3]))==N[i][1]){
				c1[a]=i;
				C1++;
				a++;
			}else if(max(N[i][1],max(N[i][2],N[i][3]))==N[i][2]){
				c2[b]=i;
				C2++;
				b++;
			}else if(max(N[i][1],max(N[i][2],N[i][3]))==N[i][3]){
				c3[c]=i;
				C3++;
				c++;
			}
		}
		
		
		printf("		%d %d %d\n",C1,C2,C3);
//		int sum=0;
//		for(int i=0;i<C1;i++){
//			sum+=N[c1[i]][1];
//			printf("%d ",c1[i]);
//		}
//		printf("\n");
//		for(int i=0;i<C2;i++){
//			sum+=N[c2[i]][2];
//			printf("%d ",c2[i]);
//		}
//		printf("\n");
//		for(int i=0;i<C3;i++){
//			sum+=N[c3[i]][3];
//			printf("%d ",c3[i]);
//		}
//		printf("\n");
		
		if(C1>(n/2)){
			while(C1>(n/2)){
				int t=1e9,l;
				for(int i = 0; i < C1; i++){
					if(N[c1[i]][1]<t&&N[c1[i]][1]!=0){
						t=N[c1[i]][1];
						l=i;
					}
				}
				if(max(N[c1[l]][2],N[c1[l]][3])==N[c1[l]][2]){
					c2[b]=c1[l];
					c1[l]=0;
					b++;
					C2++;
				}else {
					c3[c]=c1[l];
					c1[l]=0;
					c++;
					C3++;
				}
				C1--;
			}
		}
		if(C2>(n/2)){
			while(C2>(n/2)){
				int t=1e9,l;
				for(int i = 0; i < C2; i++){
					if(N[c2[i]][2]<t&&N[c2[i]][2]!=0){
						t=N[c2[i]][2];
						l=i;
					}
				}
				if(max(N[c2[l]][1],N[c2[l]][3])==N[c2[l]][1]){
					c1[a]=c2[l];
					c2[l]=0;
					a++;
					C1++;
				}else {
					c3[c]=c2[l];
					c2[l]=0;
					c++;
					C3++;
				}
				C2--;
			}
		}
		if(C3>(n/2)){
			while(C3>(n/2)){
				int t=1e9,l;
				for(int i = 0; i < C3; i++){
					if(N[c3[i]][3]<t&&N[c3[i]][3]!=0){
						t=N[c3[i]][3];
						l=i;
					}
				}
				if(max(N[c3[l]][2],N[c3[l]][1])==N[c3[l]][2]){
					c2[b]=c3[l];
					c3[l]=0;
					b++;
					C2++;
				}else {
					c1[a]=c3[l];
					c3[l]=0;
					a++;
					C1++;
				}
				C3--;
			}
		}


		int sum=0;
		for(int i=0;i<=a;i++){
			sum+=N[c1[i]][1];
			printf("%d ",c1[i]);
		}
		printf("\n");
		for(int i=0;i<=b;i++){
			sum+=N[c2[i]][2];
			printf("%d ",c2[i]);
		}
		printf("\n");
		for(int i=0;i<=c;i++){
			sum+=N[c3[i]][3];
			printf("%d ",c3[i]);
		}
		printf("\n");
		printf("		%d\n",sum);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 








//方便拉视野 
