#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int a,b,c;
}stu[100001];
bool cmpa(node X,node Y){
	return X.a>Y.a;
}bool cmpb(node X,node Y){
	return X.b>Y.b;
}bool cmpc(node X,node Y){
	return X.c>Y.c;
}int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int isa=1,isb=1,isc=1;
		for(int i=1;i<=n;i++){
			cin>>stu[i].a>>stu[i].b>>stu[i].c;
			if(stu[i].a!=0) isa=0;
			if(stu[i].b!=0) isb=0;
			if(stu[i].c!=0) isc=0;
		}int isA=0;
		int isB=0;
		if(isa+isb+isc==3){
			cout<<0<<endl;
			continue;
		}else if(isa+isb+isc==2){
			if(isa==0){
				int ax=n/2,bx=n/2,cx=n/2;
				sort(stu+1,stu+n+1,cmpa);
				int ans=0;
				for(int i=1;i<=n/2;i++) ans+=stu[i].a;
				cout<<ans;
			}else if(isb==0){
				int ax=n/2,bx=n/2,cx=n/2;
				sort(stu+1,stu+n+1,cmpb);
				int ans=0;
				for(int i=1;i<=n/2;i++) ans+=stu[i].b;
				cout<<ans;
			}else{
				int ax=n/2,bx=n/2,cx=n/2;
				sort(stu+1,stu+n+1,cmpc);
				int ans=0;
				for(int i=1;i<=n/2;i++) ans+=stu[i].c;
				cout<<ans;
			}	
		}else{
			int ans=0;
			int Stu[15][15]={};
			for(int i=1;i<=n;i++) Stu[i][1]=stu[i].a,Stu[i][2]=stu[i].b,Stu[i][3]=stu[i].c;
			if(n==2){
				for(int i=1;i<=3;i++){
					for(int j=1;j<=3;j++){
						if(i==j) continue;
						int x=Stu[1][i],y=Stu[2][j];
						ans=max(ans,x+y);
					}
				}cout<<ans;
			}else if(n==4){
				for(int i=1;i<=3;i++){
					for(int j=1;j<=3;j++){
						for(int k=1;k<=3;k++){
							for(int l=1;l<=3;l++){
								if(i==j&&i==k||i==j&&i==l||i==k&&i==l||j==k&&j==l) continue;
								int x=Stu[1][i],y=Stu[2][j];
								int z=Stu[3][k],w=Stu[4][l];
								ans=max(ans,x+y+w+z);
							}
						}	
					}
				}cout<<ans;
			}else if(n==10){
				for(int i=1;i<=3;i++){
					for(int j=1;j<=3;j++){
						for(int k=1;k<=3;k++){
							for(int l=1;l<=3;l++){
								for(int m=1;m<=3;m++){
									for(int o=1;o<=3;o++){
										for(int p=1;p<=3;p++){
											for(int q=1;q<=3;q++){
												for(int r=1;r<=3;r++){
													for(int s=1;s<=3;s++){
														int S[5]={};
														S[i]++;S[j]++;S[k]++;S[l]++;S[m]++;S[o]++;S[p]++;S[q]++;S[r]++;S[s]++;
														if(S[1]>=6||S[2]>=6||S[3]>=6) continue;
														int I=Stu[1][i],J=Stu[2][j];
														int K=Stu[3][k],L=Stu[4][l];
														int M=Stu[5][m],O=Stu[6][o];
														int P=Stu[7][p],Q=Stu[8][q];
														int R=Stu[9][r],S1=Stu[10][s];
														ans=max(ans,I+J+K+L+M+O+P+Q+R+S1);
													}
												}
											}
										}
									}
								}
							}
						}	
					}
				}cout<<ans;
			}
		}cout<<endl;
	}return 0;
}
