#include<bits/stdc++.h>
using namespace std;
struct pcl{
	int x,id;
}a[100005][5];
int n,c[5];
int mx=1;
long long ans;
int g[5][100005];
bool cmp(pcl i,pcl j){
	return i.x>j.x;
}
bool cp(int i,int j){
	return a[i][2].x-a[i][1].x>a[j][2].x-a[j][1].x;
}
void work(){
	cin>>n;
	c[1]=c[2]=c[3]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++) scanf("%d",&a[i][j].x),a[i][j].id=j;
		sort(a[i]+1,a[i]+3+1,cmp);
		g[a[i][1].id][++c[a[i][1].id]]=i;
	}
	mx=1;
	for(int i=2;i<=3;i++){
		if(c[i]>c[mx]) mx=i;
	}
	if(c[mx]>n/2){
		sort(g[mx]+1,g[mx]+c[mx]+1,cp);
		for(int i=1;i<=c[mx]-n/2;i++){
			swap(a[g[mx][i]][1],a[g[mx][i]][2]);
		}
	}
	ans=0;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=c[i];j++){
			ans+=a[g[i][j]][1].x;
		}
	}
	cout<<ans<<"\n";
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		work();
	}
	return 0;
}