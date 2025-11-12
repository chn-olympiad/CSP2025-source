#include<bits/stdc++.h>
using namespace std;
int T;
long long maxn,n,ans;
int a1[100005],a2[100005],a3[100005];
struct node{
	int shuliang=0;
	int minzhi=1e9;
	int mina=0;
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
cin>>T;
	while(T--){
		node club[4];
		cin>>n;
		maxn=n/2;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		int maxa;
		for(int i=1;i<=n;i++){
			if(a1[i]>a2[i]){
				if(a1[i]>a3[i]){
					maxa=1;
				}else{
					maxa=3;
				}
			}else{
				if(a2[i]>a3[i]){
					maxa=2;
				}else{
					maxa=3;
				}
			}
			
			//jia ru
			if(maxa==1){
				if(club[1].shuliang+1<=maxn){
					club[1].shuliang+=1;
					if(club[1].minzhi>a1[i]){
						club[1].minzhi=a1[i];club[1].mina=i;
					}
					ans+=a1[i];
					a1[i]=0;
					continue;
				}else{
					int lsmax=a2[club[1].mina]>a3[club[1].mina]?2:3;
					int last=lsmax==2?3:2;
						if(lsmax==2){
							if(a1[i]+a2[club[1].mina]>club[1].minzhi&&club[2].shuliang+1<=maxn){	club[2].shuliang+=1;
							ans+=(a1[i]+a2[club[1].mina]-club[1].minzhi);
								if(club[2].minzhi>a2[club[1].mina]){
									club[2].minzhi=a2[club[1].mina];club[2].mina=club[1].mina;
								}
								a2[club[1].mina]=0;
							
							//	club[1].shuliang+=1;
							if(club[1].minzhi>a1[i]){
								club[1].minzhi=a1[i];club[1].mina=i;
								
							}
								a1[i]=0;
								continue;
							}
						}else{
							if(a1[i]+a3[club[1].mina]>club[1].minzhi&&club[3].shuliang+1<=maxn){	club[3].shuliang+=1;
							ans+=(a1[i]+a3[club[1].mina]-club[1].minzhi);
								if(club[3].minzhi>a3[club[1].mina]){
									club[3].minzhi=a3[club[1].mina];club[3].mina=club[1].mina;
								}
								a3[club[1].mina]=0;
							
							//	club[1].shuliang+=1;
							if(club[1].minzhi>a1[i]){
								club[1].minzhi=a1[i];club[1].mina=i;
								
							}
								a1[i]=0;
								continue;
							}
						}//bidazhi
						if(lsmax==3){
							if(a1[i]+a2[club[1].mina]>club[1].minzhi&&club[2].shuliang+1<=maxn){	club[2].shuliang+=1;
							ans+=(a1[i]+a2[club[1].mina]-club[1].minzhi);
								if(club[2].minzhi>a2[club[1].mina]){
									club[2].minzhi=a2[club[1].mina];club[2].mina=club[1].mina;
								}
								a2[club[1].mina]=0;
							
							//	club[1].shuliang+=1;
							if(club[1].minzhi>a1[i]){
								club[1].minzhi=a1[i];club[1].mina=i;
								
							}
								a1[i]=0;
								continue;
							}
						}else{
							if(a1[i]+a3[club[1].mina]>club[1].minzhi&&club[3].shuliang+1<=maxn){	club[3].shuliang+=1;
							ans+=(a1[i]+a3[club[1].mina]-club[1].minzhi);
								if(club[3].minzhi>a3[club[1].mina]){
									club[3].minzhi=a3[club[1].mina];club[3].mina=club[1].mina;
								}
								a3[club[1].mina]=0;
							
							//	club[1].shuliang+=1;
							if(club[1].minzhi>a1[i]){
								club[1].minzhi=a1[i];club[1].mina=i;
								
							}
								a1[i]=0;
								continue;
							}
						}//bixiaozhi
				}if(club[2].shuliang+1<=maxn&&a2[i]>a3[i]){
					club[2].shuliang+=1;
					if(club[2].minzhi>a2[i]){
						club[2].minzhi=a2[i];club[2].mina=i;
					}ans+=a2[i];
					a2[i]=0;
					continue;
				}if(club[3].shuliang+1<=maxn&&a3[i]>a3[i]){
					club[3].shuliang+=1;
					if(club[3].minzhi>a3[i]){
						club[3].minzhi=a3[i];club[3].mina=i;
					}ans+=a3[i];
					a3[i]=0;
					continue;
				}
			}
			
			
			
			
			
			
			if(maxa==2){
				if(club[2].shuliang+1<=maxn){
					club[2].shuliang+=1;
					if(club[2].minzhi>a2[i]){
						club[2].minzhi=a2[i];club[2].mina=i;
					}ans+=a2[i];
					a2[i]=0;
					continue;
				}else{
					int lsmax=a1[club[2].mina]>a3[club[2].mina]?1:3;
						if(lsmax==1){
							if(a2[i]+a1[club[2].mina]>club[2].minzhi&&club[1].shuliang+2<=maxn){	club[1].shuliang+=1;
							ans+=(a2[i]+a1[club[2].mina]-club[2].minzhi);
								if(club[1].minzhi>a2[club[1].mina]){
									club[1].minzhi=a1[club[1].mina];club[1].mina=club[2].mina;
								}
								a1[club[2].mina]=0;
							
							//	club[2].shuliang+=1;
							
								if(club[2].minzhi>a2[i]){
								club[2].minzhi=a2[i];club[2].mina=i;
								}
								a2[i]=0;
								continue;
							}
						}else{
							if(a2[i]+a3[club[2].mina]>club[2].minzhi&&club[3].shuliang+1<=maxn){	club[3].shuliang+=1;
							ans+=(a2[i]+a3[club[2].mina]-club[2].minzhi);
								if(club[3].minzhi>a3[club[2].mina]){
									club[3].minzhi=a3[club[2].mina];club[3].mina=club[2].mina;
								}
								a3[club[2].mina]=0;
							//	club[2].shuliang+=1;
							
								if(club[2].minzhi>a2[i]){
								club[2].minzhi=a2[i];club[2].mina=i;
								}
								a2[i]=0;
								continue;
							}
						}//bidazhi
						if(lsmax==3){
							if(a2[i]+a1[club[2].mina]>club[2].minzhi&&club[1].shuliang+2<=maxn){	club[1].shuliang+=1;
							ans+=(a2[i]+a1[club[2].mina]-club[2].minzhi);
								if(club[1].minzhi>a2[club[1].mina]){
									club[1].minzhi=a1[club[1].mina];club[1].mina=club[2].mina;
								}
								a1[club[2].mina]=0;
							
							//	club[2].shuliang+=1;
							if(club[2].minzhi>a2[i]){
								club[2].minzhi=a2[i];club[2].mina=i;
								}
								a2[i]=0;
								continue;
							}
						}else{
							if(a2[i]+a3[club[2].mina]>club[2].minzhi&&club[3].shuliang+2<=maxn){	club[3].shuliang+=1;
							ans+=(a2[i]+a3[club[2].mina]-club[2].minzhi);
								if(club[3].minzhi>a3[club[2].mina]){
									club[3].minzhi=a3[club[2].mina];club[3].mina=club[2].mina;
								}
								a3[club[2].mina]=0;
							
							//	club[2].shuliang+=1;
							if(club[2].minzhi>a2[i]){
								club[2].minzhi=a2[i];club[2].mina=i;
								}
								a2[i]=0;
								continue;
							}
						}//bixiaozhi
				}if(club[1].shuliang+1<=maxn&&a1[i]>a3[i]){
					club[1].shuliang+=1;
					if(club[1].minzhi>a1[i]){
						club[1].minzhi=a1[i];club[1].mina=i;
					}
					ans+=a1[i];
					a1[i]=0;
					continue;
				}if(club[3].shuliang+1<=maxn&&a3[i]>a3[i]){
					club[3].shuliang+=1;
					if(club[3].minzhi>a3[i]){
						club[3].minzhi=a3[i];club[3].mina=i;
					}ans+=a3[i];
					a3[i]=0;
					continue;
				}
			}
			
			
			
			
			if(maxa==3){
				if(club[3].shuliang+1<=maxn){
					club[3].shuliang+=1;
					if(club[3].minzhi>a3[i]){
						club[3].minzhi=a3[i];club[3].mina=i;
					}ans+=a3[i];
					a3[i]=0;
					continue;
				}else{
					int lsmax=a2[club[3].mina]>a1[club[3].mina]?2:1;
					int last=lsmax==2?1:2;
						if(lsmax==2){
							if(a3[i]+a2[club[3].mina]>club[3].minzhi&&club[2].shuliang+3<=maxn){	club[2].shuliang+=1;
								ans+=(a3[i]+a2[club[3].mina]-club[3].minzhi);
								if(club[2].minzhi>a2[club[3].mina]){
									club[2].minzhi=a2[club[3].mina];club[2].mina=club[3].mina;
								}
								a2[club[3].mina]=0;
							
							//	club[3].shuliang+=1;
							if(club[3].minzhi>a3[i]){
								club[3].minzhi=a3[i];club[3].mina=i;
							}
								a3[i]=0;
								continue;
							}
						}else{
							if(a3[i]+a1[club[3].mina]>club[3].minzhi&&club[1].shuliang+3<=maxn){	club[1].shuliang+=1;
								ans-=(club[3].minzhi+a3[i]+a1[club[3].mina]);
								if(club[1].minzhi>a1[club[3].mina]){
									club[1].minzhi=a1[club[3].mina];club[1].mina=club[3].mina;
								}
								a1[club[3].mina]=0;
							//	club[3].shuliang+=1;
							if(club[3].minzhi>a3[i]){
								club[3].minzhi=a3[i];club[3].mina=i;
							} 
								a3[i]=0;
								continue;
							}
						}//bidazhi
						if(lsmax==1){
							if(a3[i]+a2[club[3].mina]>club[3].minzhi&&club[2].shuliang+3<=maxn){	club[2].shuliang+=1;
								ans+=(a3[i]+a2[club[3].mina]-club[3].minzhi);
								if(club[2].minzhi>a2[club[3].mina]){
									club[2].minzhi=a2[club[3].mina];club[2].mina=club[3].mina;
								}
								a2[club[3].mina]=0;
							
							//	club[3].shuliang+=1;
							if(club[3].minzhi>a3[i]){
								club[3].minzhi=a3[i];club[3].mina=i;
							}
								a3[i]=0;
								continue;
							}
						}else{
							if(a3[i]+a1[club[3].mina]>club[3].minzhi&&club[1].shuliang+3<=maxn){	club[1].shuliang+=1;
								ans-=(club[3].minzhi+a3[i]+a1[club[3].mina]);
								if(club[1].minzhi>a1[club[3].mina]){
									club[1].minzhi=a1[club[3].mina];club[1].mina=club[3].mina;
								}
								a1[club[3].mina]=0;
							//	club[3].shuliang+=1;
							if(club[3].minzhi>a3[i]){
								club[3].minzhi=a3[i];club[3].mina=i;
							}
								a3[i]=0;
								continue;
							}
						}//bixiaozhi
				}if(club[2].shuliang+1<=maxn&&a2[i]>a1[i]){
					club[2].shuliang+=1;
					if(club[2].minzhi>a2[i]){
						club[2].minzhi=a2[i];club[2].mina=i;
					}ans+=a2[i];
					a2[i]=0;
					continue;
				}if(club[1].shuliang+1<=maxn&&a1[i]>a1[i]){
					club[1].shuliang+=1;
					if(club[1].minzhi>a1[i]){
						club[1].minzhi=a1[i];club[1].mina=i;
					}ans+=a1[i];
					a1[i]=0;
					continue;
				}
			}
		}
		memset(a1,0,n);
		memset(a2,0,n);
		memset(a3,0,n);
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
