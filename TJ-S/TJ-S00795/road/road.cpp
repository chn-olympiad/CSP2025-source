#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x,y,t;
}arr[1000005];
int crr[15]={};
int fa[10005]={};
int ans=0,cnt;
int n,m,k;
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	} 
}
int check(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=check(fa[x]);
}
void merge(int x,int y,int t){
	x=check(x);
	y=check(y);
	if(x!=y){
		fa[x]=y;
		ans+=t;
		cnt--;
	}
}
bool cmp(Node a,Node b){
	return a.t<b.t;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	init();
	for(int i=1;i<=m;i++){
		cin>>arr[i].x>>arr[i].y>>arr[i].t;
	}
	int qq=m;
	cnt=n;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>crr[j];
		}
		for(int j=1;j<=n;j++){
			for(int z=j;z<=n;z++){
				qq++;
				arr[qq].x=j;
				arr[qq].y=z;
				arr[qq].t=crr[j]+crr[z]+crr[0];
			}
		}
	}
	sort(arr+1,arr+m+qq+1,cmp);
	for(int i=1;i<=m+qq;i++){
		if(check(arr[i].x)!=check(arr[i].y)){
			merge(arr[i].x,arr[i].y,arr[i].t);
			if(cnt==1){
				cout<<ans;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
