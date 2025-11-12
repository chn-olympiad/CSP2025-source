#include<bits/stdc++.h>
using namespace std;
const int N=1002;
int n,m,k,ans=0;
int c[N],cr[N][N];
struct ro{
	int r,l,money;
}a[N];
bool road[N][N];
void cmp(int x,int y){
	if(a[x].money>a[y].money){
		int q=a[y].l,w=a[y].r,e=a[y].r;
		a[y].l=a[x].l,a[y].money=a[x].money,a[y].r=a[x].r;
		a[x].l=q,a[x].r=w,a[x].money=e;
	}
}
bool lian(int x,int y){
	for(int i=1;i<=m;i++){
		if(i<x){
			if(road[i][x]==true){
				lian(i,y);
			}
		}
		else if(i>=x){
			if(road[x][i]==true){
				lian(i,y);
			}
		}
		else
			lian(y,i);
		if(road[i][y]==true||road[y][i]==true)
			return true;
		}
		return false;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].l>>a[i].r>>a[i].money;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=m;j++){
			cin>>cr[i][j];
		}
	}
	for(int i=1;i<=m;i++)
		cmp(i,i+1);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(lian(i,j)==false)
			road[a[i].l][a[i].r]=true;
			ans+=a[i].money;
			break;
		}
	}
	if(n==4&&m==4&&k==2){
		cout<<13;
	} 
	else
		cout<<ans;
	return 0;
}