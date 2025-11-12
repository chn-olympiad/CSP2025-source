#include<bits/stdc++.h>
using namespace std;

int t=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int r=0;r<t;r++){
		int n=0;
		cin>>n;
		if(n==1){
			int t1,t2,t3;
			cin>>t1>>t2>>t3;
			cout<<t3<<endl;
		}else if(n==2){
			int maxnem=0;
			int maxtrm=0;
			bool find[10010]={};
			int a[n+10][n+10]={};
			int brr[n+10][n+10]={};
			int ren[n+10][n+10]={};
			int tteemmpp=0;
			for(int i=0;i<n;i++){
				int tem=0,trm=0;
				cin>>tem>>trm;
//				tem--;
//				trm--;
				maxnem=max(maxnem,tem);
				maxtrm=max(maxtrm,trm);
				if(!find[trm]){
					tteemmpp++;
					find[trm]=1;
				}
				cin>>a[tem][trm];
				brr[i][0]=tem;
				brr[i][1]=trm;
				brr[i][2]=a[tem][trm];
			}
			if(tteemmpp==1){
				int maxsum=0;
				for(int i=0;i<=maxnem;i++){
					maxsum=max(maxsum,brr[i][2]);
				}
//				cout<<max(b[])
				cout<<maxsum<<endl;
				continue;
			}
//				cout<<max(a[0][0]+a[1][1],max(a[0][0]+a[1][0],max(a[1][0],a[])))
			int maxsum=0;
			for(int j=0;j<=maxnem;j++){
				for(int k=0;k<=maxtrm;k++){
					for(int f=0;f<=maxnem;f++){
						for(int z=0;z<=maxtrm;z++){
							if(ren[j][k]==1 || ren[f][z]==1) continue;
//							cout<<a[j][k]+a[f][z]<<" ";
							if(maxsum>a[j][k]+a[f][z] && !(ren[j][k]==1 || ren[f][z]==1)){
								ren[j][k]=0;
								ren[f][z]=0;
							}else if(!(ren[j][k]==1 || ren[f][z]==1)){
								maxsum=a[j][k]+a[f][z];
								ren[j][k]++;
								ren[f][z]++;
							}
						}
					}
					for(int i=0;i<=maxnem;i++){
						for(int l=0;l<=maxtrm;l++){
							ren[i][l]=0;
						}
					}
				}
			}
//			cout<<endl;
			cout<<maxsum<<endl;
		}else if(n==4){
			int maxnem=0;
			int maxtrm=0;
			int a[n+10][n+10]={};
			int ren[n+10][n+10]={};
			for(int i=0;i<n;i++){
				int tem=0,trm=0;
				cin>>tem>>trm;
//				tem--;
//				trm--;
				maxnem=max(maxnem,tem);
				maxtrm=max(maxtrm,trm);
				cin>>a[tem][trm];
			}
			
//				cout<<max(a[0][0]+a[1][1],max(a[0][0]+a[1][0],max(a[1][0],a[])))
			int maxsum=0;
			for(int j=0;j<=maxnem;j++){
				for(int k=0;k<=maxtrm;k++){
					for(int f=0;f<=maxnem;f++){
						for(int z=0;z<=maxtrm;z++){
							for(int d=0;d<=maxnem;d++){
								for(int w=0;w<=maxtrm;w++){
									for(int v=0;v<=maxnem;v++){
										for(int q=0;q<=maxtrm;q++){
											if(ren[j][k]==2 || ren[f][z]==2 || ren[d][w]==2 || ren[v][q]==2) continue;
											if(maxsum>a[j][k]+a[f][z]+a[d][w]+a[v][q]){
												ren[j][k]--;
												ren[f][z]--;
												ren[d][w]--;
												ren[v][q]--;
											}else{
												maxsum=a[j][k]+a[f][z]+a[d][w]+a[v][q];
												ren[j][k]++;
												ren[f][z]++;
												ren[d][w]++;
												ren[v][q]++;
											}
										}
									}
									for(int v=0;v<=maxnem;v++){
										for(int s=0;s<=maxtrm;s++){
											ren[v][s]=0;
										}
									}
								}
//								for(int p=0;p<=maxnem;p++){
//									for(int o=0;o<=maxtrm;o++){
//										ren[p][o]=0;
//									}
//								}
							}
							for(int d=0;d<=maxnem;d++){
								for(int h=0;h<=maxtrm;h++){
									ren[d][h]=0;
								}
							}
						}
//						for(int g=0;g<=maxnem;g++){
//							for(int e=0;e<=maxtrm;e++){
//								ren[g][e]=0;
//							}
//						}
					}
					for(int i=0;i<=maxnem;i++){
						for(int l=0;l<=maxtrm;l++){
							ren[i][l]=0;
						}
					}
				}
			}
			cout<<maxsum<<endl;
			
		}

	}
	return 0;
}
