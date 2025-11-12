#include<bits/stdc++.h>
using namespace std;
const int maxnn=10005;
int t,n,x,y,z,flag;
int memb[maxnn]={0};
int zo[3*maxnn][5]={0};
void px(int p,int i,int b,int c){
	if(zo[i][1]<p+1){
		if(zo[i][2]==0){
			zo[i][1]=p;
			zo[i][2]=b;
			zo[i][3]=c;
			return ;
		}
		else{
			px(zo[i][1],i+1,zo[i][2],zo[i][3]);
			zo[i][1]=p;
			zo[i][2]=b;
			zo[i][3]=c;
			return ;
		}
	}
	else{
		px(p,i+1,b,c);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	int ans=0;
	cin>>t;
	while(t){
		memset(zo,0,sizeof(zo));
		memset(memb,0,sizeof(memb));
		ans=0;
		cin>>n;
		flag=n;
		for(int i=1;i<=n;i++){
			cin>>x>>y>>z;
			px(x,1,i,1);
			px(y,1,i,2);
			px(z,1,i,3);
		}
		x=0;y=0;z=0;
		int az=0,bz=0,cz=0;
		for(int i=1;i<=3*n;i++){
			az=0;bz=0;cz=0;
			if(zo[i][3]==1){
				if(x!=n/2){
					if(memb[zo[i][2]]!=1){
						if(x+1==n/2){
						for(int j=i+1;j<=3*n;j++){
							if(zo[j][3]==1&&memb[zo[j][2]]!=1){
								az=j;
								break;
							}
						}
						for(int j=i+1;j<=3*n;j++){
							if(zo[j][3]!=1&&memb[zo[j][2]]!=1&&zo[az][2]!=zo[j][2]){
								if(zo[j][3]==2){
									bz=j;
									break;
								}
								else{
									cz=j;
									break;
								}
							}
						}
						
						}
						
					
						if(bz!=0&&y<n/2){
							if(zo[bz][1]+zo[az][1]>zo[i][1]){
								memb[zo[az][2]]=1;
								memb[zo[bz][2]]=1;
								ans+=zo[bz][1]+zo[az][1];
								flag+=2;
								x++;
								y++;
								
							}
							else{
								memb[zo[i][2]]=1;
								ans+=zo[i][1];
								flag++;
								x++;
								
							}
						}
						else if(cz!=0&&z<n/2){
							if(zo[cz][1]+zo[az][1]>zo[i][1]){
								memb[zo[az][2]]=1;
								memb[zo[cz][2]]=1;
								ans+=zo[cz][1]+zo[az][1];
								flag+=2;
								x++;
								z++;
							
							}
							else{
								memb[zo[i][2]]=1;
								ans+=zo[i][1];
								flag++;
								x++;
							}
						}
						else{
							memb[zo[i][2]]=1;
								ans+=zo[i][1];
								flag++;
								x++;
								
						}			
					}
				}
				
			}
			else if(zo[i][3]==2){
				if(y!=n/2){
					if(memb[zo[i][2]]!=1){
						if(y+1==n/2){
						for(int j=i+1;j<=3*n;j++){
							if(zo[j][3]==2&&memb[zo[j][2]]!=1){
								bz=j;
								break;
							}
						}
						for(int j=i+1;j<=3*n;j++){
							if(zo[j][3]!=2&&memb[zo[j][2]]!=1&&zo[bz][2]!=zo[j][2]){
								if(zo[j][3]==1){
									az=j;
									break;
								}
								else{
									cz=j;
									break;
								}
							}
						}
					}
						if(az!=0&&x<n/2){
							if(zo[az][1]+zo[bz][1]>zo[i][1]){
								memb[zo[az][2]]=1;
								memb[zo[bz][2]]=1;
								ans+=zo[bz][1]+zo[az][1];
								flag+=2;
								x++;
								y++;
								
							}
							else{
								memb[zo[i][2]]=1;
								ans+=zo[i][1];
								flag++;
								y++;			
							}
						}
						else if(cz!=0&&z<n/2){
							if(zo[cz][1]+zo[bz][1]>zo[i][1]){
								memb[zo[bz][2]]=1;
								memb[zo[cz][2]]=1;
								ans+=zo[cz][1]+zo[bz][1];
								flag+=2;
								y++;
								z++;
							}
							else{
								memb[zo[i][2]]=1;
								ans+=zo[i][1];
								flag++;
								y++;
							}
						}
						else{
							memb[zo[i][2]]=1;
							ans+=zo[i][1];
							flag++;
							y++;
						}			
					}
				}
				
			}
			else{
				if(z!=n/2){
					if(memb[zo[i][2]]!=1){
						if(z+1==n/2){
						for(int j=i+1;j<=3*n;j++){
							if(zo[j][3]==3&&memb[zo[j][2]]!=1){
								cz=j;
								break;
							}
						}
						for(int j=i+1;j<=3*n;j++){
							if(zo[j][3]!=3&&memb[zo[j][2]]!=1&&zo[cz][2]!=zo[j][2]){
								if(zo[j][3]==2){
									bz=j;
									break;
								}
								else{
									az=j;
									break;
								}
							}
						}
					}
						if(bz!=0&&y<n/2){
							if(zo[bz][1]+zo[cz][1]>zo[i][1]){
								memb[zo[cz][2]]=1;
								memb[zo[bz][2]]=1;
								ans+=zo[bz][1]+zo[cz][1];
								flag+=2;
								z++;
								y++;
								
							}
							else{
								memb[zo[i][2]]=1;
								ans+=zo[i][1];
								flag++;
								z++;
							}
						}
						else if(az!=0&&x<n/2){
							if(zo[az][1]+zo[cz][1]>zo[i][1]){
								memb[zo[az][2]]=1;
								memb[zo[cz][2]]=1;
								ans+=zo[cz][1]+zo[az][1];
								flag+=2;
								x++;
								z++;
							}
							else{
								memb[zo[i][2]]=1;
								ans+=zo[i][1];
								flag++;
								z++;
							}
						}
						else{
							memb[zo[i][2]]=1;
								ans+=zo[i][1];
								flag++;
								z++;
						}			
						}
					}
																		
				}
				if(flag==n){
					break;
				}
	
		}
		cout<<ans<<endl;
		t--;
	} 
	return 0;
} 

