#include<iostream>
using namespace std;
int n[5],a1[5][100005],a2[5][100005],a3[5][100005],b[5][100005][1],c[5][100005][1],cha[5][100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int q=0;q<t;q++){
		cin>>n[q];
		for(int w=0;w<n[q];w++){
			cin>>a1[q][w]>>a2[q][w]>>a3[q][w]; 
		}
	}
	for(int q=0;q<t;q++){
		for(int w=0;w<n[q];w++){
			b[q][w][0]=1;
			c[q][w][0]=a1[q][w];
			if(a1[q][w]<a2[q][w]){
				b[q][w][0]=2;
				c[q][w][0]=a2[q][w];
				if(a2[q][w]<a3[q][w]){
					b[q][w][0]=3;
					c[q][w][0]=a3[q][w];
				}
			}
			if(a1[q][w]>a2[q][w]){
				if(a3[q][w]>a1[q][w]){
					b[q][w][0]=3;
					c[q][w][0]=a3[q][w];
				}
			}
		}	
	}
	int count1[5][1],count2[5][1],count3[5][1];
	for(int q=0;q<t;q++){
		int x=0,y=0,z=0;
		for(int w=0;w<n[q];w++){
			if(b[q][w][0]==1){
				x++;
			}
			if(b[q][w][0]==2){
				y++;
			}
			if(b[q][w][0]==3){
				z++;	
			}
		}
		count1[q][0]=x;
		count2[q][0]=y;
		count3[q][0]=z;
	}  
	for(int q=0;q<t;q++){
		for(int w=0;w<n[q];w++){
			cha[q][w]=-1;
		} 
	}
	int result[5];
	for(int q=0;q<t;q++){
		result[q]=0;
	for(int w=0;w<n[q];w++){
		result[q]=result[q]+c[q][w][0];
	}
}
	for(int q=0;q<t;q++){
		if(count1[q][0]<=n[q]/2&&count2[q][0]<=n[q]/2&&count3[q][0]<=n[q]/2){
			cout<<result[q]<<endl;
	    }
	    if(count1[q][0]>n[q]/2){
	    	for(int q=0;q<t;q++){
				for(int w=0;w<n[q];w++){
					if(a1[q][w]>=a2[q][w]){
						if(a1[q][w]>=a3[q][w]){
							if(a2[q][w]>=a3[q][w]){
								cha[q][w]=a1[q][w]-a2[q][w];
							} 
							else{
								cha[q][w]=a1[q][w]-a3[q][w];
								
							}
						}
					}
				}	
			}
			int daxiao[5][100005],count=0;
			for(int q=0;q<t;q++){
				int abab=n[q];
				for(int w=0;w<abab;w++){
					if(cha[q][w]>-1){
						daxiao[q][count]=cha[q][w];	
						count++;
					}
				}
			}
			for(int i=0;i<t;i++){
				for(int q=0;q<count;q++){
					for(int w=q;w<count;w++){
						if(daxiao[i][q]>daxiao[i][w]){
							int zhou=daxiao[i][q];
							daxiao[i][q]=daxiao[i][w];
							daxiao[i][w]=zhou;
						}
			
					}
				}
			}
			int xyz[5][1];
			for(int i=0;i<t;i++){
				xyz[i][0]=0;
				for(int q=0;q<count1[i][0]-n[i]/2;q++){
					xyz[i][0]=xyz[i][0]+daxiao[i][q];
				}
			}
			
			cout<<result[q]-xyz[q][0]-1<<endl;
		}
		if(count2[q][0]>n[q]/2){
	    	for(int q=0;q<t;q++){
				for(int w=0;w<n[q];w++){
					if(a2[q][w]>=a1[q][w]){
						if(a2[q][w]>=a3[q][w]){
							if(a2[q][w]>=a3[q][w]){
								cha[q][w]=a2[q][w]-a1[q][w];
							} 
							else{
								cha[q][w]=a2[q][w]-a3[q][w];
							}
						}
					}
				}	
			}
			int daxiao[5][100005],count=0;
			for(int q=0;q<t;q++){
				int abab=n[q];
				for(int w=0;w<abab;w++){
					if(cha[q][w]>-1){
						daxiao[q][count]=cha[q][w];
						count++;
					}
				}
			}
			for(int i=0;i<t;i++){
				for(int q=0;q<count;q++){
					for(int w=q;w<count;w++){
						if(daxiao[i][q]>daxiao[i][w]){
							int zhou=daxiao[i][q];
							daxiao[i][q]=daxiao[i][w];
							daxiao[i][w]=zhou;
						}
			
					}
				}
			}
			int xyz[5][1];
			for(int i=0;i<t;i++){
				xyz[i][0]=0;
				for(int q=0;q<count2[i][0]-n[i]/2;q++){
					xyz[i][0]=xyz[i][0]+daxiao[i][q];
				}
			}
			cout<<result[q]-xyz[q][0]-1<<endl;
		}
		if(count3[q][0]>n[q]/2){
	    	for(int q=0;q<t;q++){
				for(int w=0;w<n[q];w++){
					if(a3[q][w]>=a1[q][w]){
						if(a3[q][w]>=a2[q][w]){
							if(a2[q][w]>=a1[q][w]){
								cha[q][w]=a3[q][w]-a2[q][w];
							} 
							else{
								cha[q][w]=a3[q][w]-a1[q][w];
							}
						}
					}
				}	
			}
			int daxiao[5][100005],count=0;
			for(int q=0;q<t;q++){
				int abab=n[q];
				for(int w=0;w<abab;w++){
					if(cha[q][w]>-1){
						daxiao[q][count]=cha[q][w];
						count++;
					}
				}
			}
			for(int i=0;i<t;i++){
				for(int q=0;q<count;q++){
					for(int w=q;w<count;w++){
						if(daxiao[i][q]>daxiao[i][w]){
							int zhou=daxiao[i][q];
							daxiao[i][q]=daxiao[i][w];
							daxiao[i][w]=zhou;
						}
			
					}
				}
			}
			int xyz[5][1];
			for(int i=0;i<t;i++){
				xyz[i][0]=0;
				for(int q=0;q<count3[i][0]-n[i]/2;q++){
					xyz[i][0]=xyz[i][0]+daxiao[i][q];
				}
			}
			cout<<result[q]-xyz[q][0]-1<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
