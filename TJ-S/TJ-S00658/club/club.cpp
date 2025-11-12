#include<bits/stdc++.h>
using namespace std;
const int M=1e5+10;
int x[M],y[M],z[M];
int xi=1,yi=1,zi=1;
int maxi(int a,int b,int c){
	return max(max(a,b),c);
}
int find_mxi(int a,int b,int c){
	int t=maxi(a,b,c);
	if(t==a) return 1;
	else if(t==b) return 2;
	else return 3;
}
int mini(int a,int b,int c){
	return min(min(a,b),c);
}
int midd(int a,int b,int c){
	return a+b+c-maxi(a,b,c)-mini(a,b,c);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
		int n;
		long long ans=0;
		cin>>n;
		
		for(int i=1;i<=n;i++){
			int t1,t2,t3;
			scanf("%d%d%d",&t1,&t2,&t3);
			int mx=maxi(t1,t2,t3);
			int md=mx-midd(t1,t2,t3);
			int pos=find_mxi(t1,t2,t3); 
			if(pos==1){
				x[xi]=md;
				xi++;
			}else if(pos==2){
				y[yi]=md;
				yi++;
			}else{
				z[zi]=md;
				zi++;
			}
			ans+=mx;
		}
		xi--,yi--,zi--;
		//cout<<ans<<endl;
		
		if(yi>n/2){
			for(int i=1;i<=yi;i++){
				swap(x[i],y[i]);
			}
			swap(xi,yi);
		}if(zi>n/2){
			for(int i=1;i<=zi;i++){
				swap(x[i],z[i]);
			}
			swap(xi,zi);
		}
		
		if(xi>n/2){
			int num=xi-n/2;
			sort(x,x+xi+1);
			/*for(int i=1;i<=xi;i++){
				cout<<x[i]<<' ';
			}
			cout<<endl;*/
			for(int i=1;i<=num;i++){
				ans-=x[i];
				//cout<<ans<<' ';
			}
			
		}
		cout<<ans<<'\n';
		for(int i=1;i<=M;i++){
			x[i]=0;
			y[i]=0;
			z[i]=0;
		}
		xi=1,yi=1,zi=1,ans=0;
	}
	return 0;
}

