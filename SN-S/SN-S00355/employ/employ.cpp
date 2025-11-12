//李欣航 SN-S00355 西安铁一中滨河高级中学 
#include<bits/stdc++.h>
using namespace std;

int t,n;
int a[20010][5];
int ans=0;
int mx=-10;
int x=0,y=0,z=0;
int w=n/2;
int d1[20010],d2[20010],d3[20010];
int md[20010];
int chao=0;

int zeta(int g){
	int h=-g;
	if(g>=0)
	return g;
	else
	return h;
}
int cmp(int g,int h){
	return g<h;
}



int main (){
	freopen ("club.in","r",stdin);
	freopen ("clnb.out","w",stdout);
	
	cin>>t;
	for(int p=1;p<=t;p++){
		ans=0;
		mx=-1;
		
		
	cin>>n;
	for(int i=1;i<=n;i++){//outside
		
		for(int j=1;j<=3;j++){//inside
			cin>>a[i][j];
			
			
			if(mx<a[i][j]){
				mx=a[i][j];
			}
			
			
			if(mx==a[i][1])
			x+=1;
			if(mx==a[i][2])
			y+=1;
			if(mx==a[i][3])
			z+=1;
			
			d1[i]=zeta((a[i][1]-a[i][2]));
			d2[i]=zeta((a[i][2]-a[i][3]));
			d3[i]=zeta((a[i][1]-a[i][3]));
			md[i]=min(d1[i],min(d2[i],d3[i]));
		}
				
		ans+=mx;
		
		if(x>w){
			chao=x-w;
		}
		if(y>w){
			chao=y-w;
		}
		if(z>w){
			chao=z-w;
		}
		
		sort(md+1,md+1+n,cmp);
		for(int j=1;j<=n;j++){
			cout<<md[j]<<endl;
		}
		for(int j=1;j<=chao;j++){
			ans=ans-md[j];
		}
		
		
		
		if(n=2){
		for(int i=1;i<=n;i++){//outside
		
		for(int j=1;j<=3;j++){//inside
			cin>>a[i][j];
			
		}
	
	}
	if(a[1][1]>a[1][2]&&a[1][2]>a[1][3])
	;
	
	}
	
	
	cout<<ans<<endl;
	
	
	
	
}}
	return 0;
}


