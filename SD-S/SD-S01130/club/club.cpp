#include<bits/stdc++.h>
using namespace std;

struct id{
	int d1,d2,d3;
	int cha1,cha2;
}z[100100];

int t,n,mid;
int s1,s2,s3;
long long ans;

bool cmp(id x,id y){
	int q1=max(x.cha1,x.cha2);
	int q2=max(y.cha1,y.cha2);
	return q1>q2;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0;
		s1=s2=s3=n/2;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&z[i].d1,&z[i].d2,&z[i].d3);
			z[i].cha1=abs(z[i].d1-z[i].d2);
			z[i].cha2=abs(z[i].d2-z[i].d3);
		}
		sort(z+1,z+n+1,cmp);
		for(int i=1;i<=n;i++){
			bool check1=false;
			bool check2=false;
			for(int i=1;i<=3;i++){
				
			}
			if(z[i].cha1 > z[i].cha2){
				if(z[i].d1 >= z[i].d2 && s1!=0){
					ans+=z[i].d1;
					s1--;
				}else if(z[i].d2 >= z[i].d1 && s2!=0){
					ans+=z[i].d2;
					s2--;
				}else{
					check1=true;
				}
			}else{
				if(z[i].d2 >= z[i].d3 && s2!=0){
					ans+=z[i].d2;
					s2--;
				}else if(z[i].d3 >= z[i].d2 && s3!=0){
					ans+=z[i].d3;
					s3--;
				}else{
					check2=true;
				}
			}
			if(check1){
				if(z[i].d2 >= z[i].d3 && s2!=0){
					ans+=z[i].d2;
					s2--;
				}else if(z[i].d3 >= z[i].d2 && s3!=0){
					ans+=z[i].d3;
					s3--;
				}else{
					int mid1=-1;
					int u;
					if(!s1){
						if(z[i].d1 > mid1){
							u=1;
							mid1=z[i].d1;
						}
					}
					if(!s2){
						if(z[i].d2 > mid1){
							u=2;
							mid1=z[i].d2;
						}
					}
					if(!s3){
						if(z[i].d3 > mid1){
							u=3;
							mid1=z[i].d3;
						}
					}
					ans+=mid1;
					if(u==1) s1--;
					if(u==2) s2--;
					if(u==3) s3--;
				}
			}
			if(check2){
				if(z[i].d1 >= z[i].d2 && s1!=0){
					ans+=z[i].d1;
					s1--;
				}else if(z[i].d2 >= z[i].d1 && s2!=0){
					ans+=z[i].d2;
					s2--;
				}else{
					long long mid1=-2;
					int u;
					if(s1!=0){
						if(z[i].d1 > mid1){
							u=1;
							mid1=z[i].d1;
						}
					}
					if(s2!=0){
						if(z[i].d2 > mid1){
							u=2;
							mid1=z[i].d2;
						}
					}
					if(s3!=0){
						if(z[i].d3 > mid1){
							u=3;
							mid1=z[i].d3;
						}
					}
					ans+=mid1;
					if(u==1) s1--;
					if(u==2) s2--;
					if(u==3) s3--;
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
