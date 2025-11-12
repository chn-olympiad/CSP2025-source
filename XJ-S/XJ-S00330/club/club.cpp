#include<bits/stdc++.h>

using namespace std;

int n,a[100005][5],b[5]={0},ans=0,z;//z=n的一半 

void f(int o,int an,int bn,int cn,int y,int s,int c[]){//o=没排人数 an=a的人数 y=正在排的人 s=满意度之和 
	if(o==0){
		return ;
	}
	if(an>z){
		s-=a[y-1][1];
	}
	if(bn>z){
		s-=a[y-1][2];
	}
	if(cn>z){
		s-=a[y-1][3];
	}
	if(an<z){
		s+=a[y][1];
		f(o-1,an+1,bn,cn,y+1,s,c);
		ans=max(s,ans);
		if(bn<z){
			s-=a[y][1];
			s+=a[y][2];
			f(o-1,an-1,bn+1,cn,y+1,s,c);
			ans=max(s,ans);
			if(cn<z){
				s-=a[y][2];
				s+=a[y][3];
				f(o-1,an,bn-1,cn+1,y+1,s,c);
				ans=max(s,ans);	
			}
		}
		if(cn<z){
			s-=a[y][1];
			s+=a[y][3];
			f(o-1,an-1,bn,cn+1,y+1,s,c);
			ans=max(s,ans);	
			if(bn<z){
				s-=a[y][3];
				s+=a[y][2];
				f(o-1,an,bn+1,cn-1,y+1,s,c);
				ans=max(s,ans);	
			}
		}
	}else if(bn<z){
		s+=a[y][2];
		f(o-1,an,bn+1,cn,y+1,s,c);
		ans=max(s,ans);
		if(an<z){
			s-=a[y][2];
			s+=a[y][1];
			f(o-1,an+1,bn-1,cn,y+1,s,c);
			ans=max(s,ans);
			if(cn<z){
				s-=a[y][1];
				s+=a[y][3];
				f(o-1,an-1,bn,cn+1,y+1,s,c);
				ans=max(s,ans);	
			}
		}
		if(cn<z){
			s-=a[y][2];
			s+=a[y][3];
			f(o-1,an,bn-1,cn+1,y+1,s,c);
			ans=max(s,ans);	
			if(an<z){
				s-=a[y][1];
				s+=a[y][1];
				f(o-1,an+1,bn,cn-1,y+1,s,c);
				ans=max(s,ans);	
			}
		}
	}else{
		s+=a[y][3];
		f(o-1,an,bn,cn+1,y+1,s,c);
		ans=max(s,ans);
		if(an<z){
			s-=a[y][3];
			s+=a[y][1];
			f(o-1,an+1,bn,cn-1,y+1,s,c);
			ans=max(s,ans);
			if(bn<z){
				s-=a[y][3];
				s+=a[y][2];
				f(o-1,an-1,bn+1,cn,y+1,s,c);
				ans=max(s,ans);	
			}
		}
		if(bn<z){
			s-=a[y][3];
			s+=a[y][2];
			f(o-1,an,bn+1,cn-1,y+1,s,c);
			ans=max(s,ans);	
			if(an<z){
				s-=a[y][1];
				s+=a[y][1];
				f(o-1,an+1,bn-1,cn,y+1,s,c);
				ans=max(s,ans);	
			}
		}
	}
	return ;
}

int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int fa=1,fb=1;
		cin>>n;
		if(n%2==0){
			z=n/2;
		}else{
			z=ceil(n/2);
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][3]!=0){
				fb=0;
				fa=0;
			}
			if(a[i][2]!=0){
				fa=0;
			}
			//每个人的最优部门 
			if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][1]){
				a[i][0]=1;
			}else if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][2]){
				a[i][0]=2;
			}else if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][3]){
				a[i][0]=3;
			}else{
				a[i][0]=0;
			}
			b[a[i][0]]++;
		}
		if(n==2){//1
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j){
						if(a[1][i]+a[2][j]>ans){
							ans=a[1][i]+a[2][j];
						}
					}
				}
			}
			cout<<ans<<endl;
			continue;
		}
		if(fa==1){//12
			int d[10005]={0};
			for(int i=1;i<=n;i++){
				d[i]=a[i][1];
			}
			sort(d,d+n+1);
			for(int i=n;i>=n+1-z;i--){
				ans+=d[i];
			}
			cout<<ans<<endl;
			return 0;
		}
		if(b[1]<=z&&b[2]<=z&&2*b[3]<=z){//最好(每个人都分到最佳) 
			for(int i=1;i<=n;i++){
				ans+=a[i][a[i][0]];
			}
			cout<<ans<<endl;
			continue;
		}
		if(n<=30){//枚举 
			int c[100005]={0};
			c[1]=1;
			f(n, 0,0,0, 1,0,c);
			cout<<ans<<endl;
			return 0;
		}else{
			
		}
	}
	return 0;
}
/*
4
3 3 3
3 3 3
3 3 3
3 3 3

12

4
9 5 0
8 6 0
9 0 0
7 0 0


*/
