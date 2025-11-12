#include<bits/stdc++.h>
using namespace std;
#define N 100005
int ans[N][4];
int bm[N][4];
struct WY{
	int a,b,c;
}ren[N][4];
void jch(int ni,int nj,int li,int lj){
	ans[ni][nj]=ans[li][lj]+bm[ni][nj];
	ren[ni][nj].a=ren[li][lj].a;
	ren[ni][nj].b=ren[li][lj].b;
	ren[ni][nj].c=ren[li][lj].c;
	if(nj==1){
		ren[ni][nj].a++;return;
	}
	if(nj==2){
		ren[ni][nj].b++;return;
	}
	if(nj==3){
		ren[ni][nj].c++;return;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>bm[i][1]>>bm[i][2]>>bm[i][3];
		}
		for(int h=1;h<=n;h++){
			for(int i=h;i<=n+h;i++){
				int yi=i;
				if(i>n)i%=n;
				for(int j=1;j<=3;j++){
					if(i==1){
	//					cout<<"first!!!"<<endl;
						ans[i][j]=bm[i][j];
						if(j==1)ren[i][j].a=1;
						else if(j==2)ren[i][j].b=1;
						else if(j==3)ren[i][j].c=1;
						continue;
					}
					if(j==1){
	//					cout<<" now stdt "<<i<<" get into "<<j<<endl;
						if(ren[i-1][1].a < n/2){
							if(ren[i-1][2].a >= n/2){
	//							cout<<"		out 2"<<endl;
								if(ans[i-1][1]>=ans[i-1][3]){
									jch(i,j,i-1,1);
								}
								else{
									jch(i,j,i-1,3);
								}continue;
							}
							if(ren[i-1][3].a >= n/2){
	//							cout<<"		out 3"<<endl;
								if(ans[i-1][1]>=ans[i-1][2]){
									jch(i,j,i-1,1);
								}
								else{
									jch(i,j,i-1,2);
								}continue;
							}
							
							else if(ans[i-1][1]>=ans[i-1][2] && ans[i-1][1]>=ans[i-1][3])jch(i,j,i-1,1);
							else if(ans[i-1][2]>=ans[i-1][3] && ans[i-1][2]>=ans[i-1][3])jch(i,j,i-1,2);
							else jch(i,j,i-1,3);
	//						cout<<"		all"<<endl;
							
						}
						else{
	//						cout<<"		out 1"<<endl;
							if(ren[i-1][2].a >= n/2){
								jch(i,j,i-1,3);continue;
							}
							if(ren[i-1][3].a >= n/2){
								jch(i,j,i-1,2);continue;
							}
							if(ans[i-1][2]>=ans[i-1][3]){
								jch(i,j,i-1,2);
							}
							else{
								jch(i,j,i-1,3);
							}continue;
						}
					}
					else if(j==2){
	//					cout<<" now stdt "<<i<<" get into "<<j<<endl;
						if(ren[i-1][1].b < n/2){
							if(ren[i-1][2].b >= n/2){
	//							cout<<"		out 2"<<endl;
								if(ans[i-1][1]>=ans[i-1][3]){
									jch(i,j,i-1,1);
								}
								else{
									jch(i,j,i-1,3);
								}continue;
							}
							else if(ren[i-1][3].b >= n/2){
	//							cout<<"		out 3"<<endl;
								if(ans[i-1][1]>=ans[i-1][2]){
									jch(i,j,i-1,1);
								}
								else{
									jch(i,j,i-1,2);
								}continue;
							}
							
							else if(ans[i-1][1]>=ans[i-1][2] && ans[i-1][1]>=ans[i-1][3])jch(i,j,i-1,1);
							else if(ans[i-1][2]>=ans[i-1][3] && ans[i-1][2]>=ans[i-1][3])jch(i,j,i-1,2);
							else jch(i,j,i-1,3);
	//						cout<<"		all"<<endl;
							
						}
						else{
	//						cout<<"		out 1"<<endl;
							if(ren[i-1][2].b >= n/2){
								jch(i,j,i-1,3);continue;
							}
							if(ren[i-1][3].b >= n/2){
								jch(i,j,i-1,2);continue;
							}
							if(ans[i-1][2]>=ans[i-1][3]){
								jch(i,j,i-1,2);
							}
							else{
								jch(i,j,i-1,3);
							}continue;
						}
					}
					else if(j==3){
	//					cout<<" now stdt "<<i<<" get into "<<j<<endl;
						if(ren[i-1][1].c < n/2){
							if(ren[i-1][2].c >= n/2){
	//							cout<<"		out 2"<<endl;
								if(ans[i-1][1]>=ans[i-1][3]){
									jch(i,j,i-1,1);
								}
								else{
									jch(i,j,i-1,3);
								}continue;
							}
							if(ren[i-1][3].c >= n/2){
	//							cout<<"		out 3"<<endl;
								if(ans[i-1][1]>=ans[i-1][2]){
									jch(i,j,i-1,1);
								}
								else{
									jch(i,j,i-1,2);
								}continue;
							}
							
							if(ans[i-1][1]>=ans[i-1][2] && ans[i-1][1]>=ans[i-1][3])jch(i,j,i-1,1);
							else if(ans[i-1][2]>=ans[i-1][3] && ans[i-1][2]>=ans[i-1][3])jch(i,j,i-1,2);
							else jch(i,j,i-1,3);
	//						cout<<"		all"<<endl;
							
						}
						else{
	//						cout<<"		out 1"<<endl;
							if(ren[i-1][2].c >= n/2){
								jch(i,j,i-1,3);continue;
							}
							if(ren[i-1][3].c >= n/2){
								jch(i,j,i-1,2);continue;
							}
							if(ans[i-1][2]>=ans[i-1][3]){
								jch(i,j,i-1,2);
							}
							else{
								jch(i,j,i-1,3);
							}continue;
						}
					}
				}
				i=yi;
			}
	//		cout<<endl;
	//		for(int i=1;i<=n;i++){
	//			for(int j=1;j<=3;j++){
	//				cout<<ans[i][j]<<" ";
	//			}
	//			cout<<endl;
	//		}cout<<endl;
	//		for(int i=1;i<=n;i++){
	//			for(int j=1;j<=3;j++){
	//				cout<<ren[i][j].a<<ren[i][j].b<<ren[i][j].c<<" ";
	//			}
	//			cout<<endl;
	//		}
		}
		int nans=-1;
			for(int i=1;i<=3;i++){
				nans=max(ans[n][i],nans);
			}
			cout<<nans<<endl;	
	}
	return 0;
} 