#include<bits/stdc++.h>
using namespace std;
int T;
int u[100005][10];
int ma=INT_MIN;
int f[10];
bool fr=0;
int n;
int b[5];
int c[5];
struct node{
	int x,y,z,maxx,mid,minn;
}a[200005];
bool cmp(int a,int b){
	return a>b;
}
bool cmp1(node a,node b){
	if(a.x==b.x){
		if(a.y==b.y)
			return a.z>b.z;
		return a.y>b.y;
	}
	return a.x>b.x;
}
void dfs(int i,int x,int summ){
	ma=max(ma,summ);
	if(i>n){
		return ;
	}
	if(f[1]<n/2){
		f[1]++;
		dfs(i+1,1,summ+u[i][1]);
		f[1]--;
	}
	if(f[2]<n/2){
		f[2]++;
		dfs(i+1,2,summ+u[i][2]);
		f[2]--;
	}
	if(f[3]<n/2&&fr==0){
		f[3]++;
		dfs(i+1,3,summ+u[i][3]);
		f[3]--;
	}
}
void fun(){
	bool flag=1;
	int summ=0;
	int f[20005]={0};
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&b[1],&b[2],&b[3]);
		c[1]=b[1],c[2]=b[2],c[3]=b[3];
		sort(b+1,b+1+3,cmp);
		if(b[3]!=0){
			flag=0;
		}
		for(int j=1;j<=3;j++){
			for(int k=1;k<=3;k++){
				if(b[j]==c[k]){
					if(j==1){
						a[i].maxx=k;
					}
					if(j==2){
						a[i].mid=k;
					}
					if(j==3){
						a[i].minn=k;
					}
					if(b[2]==0&&b[3]==0){
						a[i].mid=2;
						a[i].minn=3;
					}
				}
			}
		}
		a[i].x=b[1],a[i].y=b[2],a[i].z=b[3];
	}
	sort(a+1,a+1+n,cmp1);
	for(int i=1;i<=n;i++){
		if(f[a[i].maxx]<n/2){
			summ=summ+a[i].x;
			f[a[i].maxx]++;
		}
		else if(f[a[i].mid]<n/2){
			summ=summ+a[i].y;
			f[a[i].mid]++;
		}
		else{
			summ=summ+a[i].z;
			f[a[i].minn]++;
		}
	}
	cout<<summ<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ma=INT_MIN;
		cin>>n;
		if(n>=30){
			fun();
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					cin>>u[i][j];
				}
			}
			memset(f,0,sizeof(f));
			dfs(1,1,0);
			cout<<ma<<endl;
		}
	}
	return 0;
}
