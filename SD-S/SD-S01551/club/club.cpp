#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[100010][5],b[100010],d[100010],ans;
struct l{
	int a1,a2,a3;
	int u,ma;
}c[100010];
int cmp(l x,l y){
	return x.a1>y.a1;
}
int cmp2(l x,l y){
	return x.u>y.u;
}
void f(int h){
	sort(c+1,c+1+n,cmp2);
	int s1=0,s2=0;
	for(int j=1;j<=n;j++){
		//cout<<s1<<endl;
		if(s1==n/2){
			for(int k=j+1;k<=n;k++){
				ans+=c[j].a2;
			}
			break;
		}else if (s2==n/2){
			for(int k=j+1;k<=n;k++){
				ans+=c[j].a1;
			}
			break;
		}
		if(c[j].a1>c[j].a2){
			ans+=c[j].a1;
			s1++;
		}else {
			ans+=c[j].a2;s2++;
		}
	}
	
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int p2=0,p3=0;
		for(int j=1;j<=3;j++){
			for(int k=1;k<=100010;k++){
				a[k][j]=0;
			}
		}
		memset(b,0,sizeof(b));
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			c[j].a1=a[j][1];
			c[j].a2=a[j][2];
			c[j].u=abs(a[j][1]-a[j][2]);
		//	a[j].ma=max(a[j].a1,a[j].a2);
			if(a[j][2]) p2=1;
			if(a[j][3]) p3=1;
			
		}
		ans=0;
		
		if(!p2 && !p3){
			sort(c+1,c+1+n,cmp);
			for(int j=1;j<=n/2;j++){
				ans+=c[j].a1;
			}
		}else if(!p3){
			f(0);
		}else if(n==2){
			for(int x=1;x<=3;x++){
				for(int y=1;y<=3;y++){
					if(y==x) continue;
					ans=max(ans,a[1][x]+a[2][y]);
				}
			}
		}else if(n==4){
			for(int x=1;x<=3;x++){
				for(int y=1;y<=3;y++){
					for(int z=1;z<=3;z++){
						if(x==y && (z==x ||z==y)) continue;
						for(int k=1;k<=3;k++){
							if(x==y && (k==x || k==y)) continue;
							if((x==z || y==z)&&(k==z))continue;
							ans=max(ans,a[1][x]+a[2][y]+a[3][z]+a[4][k]);
						}
					}
				}
			}
		}else{
			f(0);
		}
		
		cout<<ans<<"\n";
	}

	return 0;
}



/*

3
4
4 2 1
3 2 4
5 3 4
3 5 1
6
5 1 0
5 1 0
1 2 0
1 2 0
9 5 0
9 5 0
2
10 9 8
4 0 0


*/
