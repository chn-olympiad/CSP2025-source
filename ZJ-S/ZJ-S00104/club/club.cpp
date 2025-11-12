#include<bits/stdc++.h>
using namespace std;
int T,n,s,v[5],a[100005][5];
struct node{
	int s,x,y;	
}t[100005];
bool cmp(node x,node y){
	return a[x.s][x.x]+a[y.s][y.y]>a[y.s][y.x]+a[x.s][x.y];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;s=0;
		memset(v,0,sizeof(v));
		v[0]=INT_MAX;
		for(int i=1;i<=n;i++){
			t[i]={i,0,0};
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int o=max(a[i][1],max(a[i][2],a[i][3]));
			int p=min(a[i][1],min(a[i][2],a[i][3]));
			int q=a[i][1]+a[i][2]+a[i][3]-o-p;
			for(int j=1;j<=3;j++){
				if(a[i][j]==o&&v[j]<v[t[i].x])v[j]++,v[t[i].x]--,t[i].x=j;
				if(a[i][j]==q&&v[j]<v[t[i].y])t[i].y=j;
			}
		}stable_sort(t+1,t+n+1,cmp);
		memset(v,0,sizeof(v));
		for(int i=1;i<=n;i++){
			if(v[t[i].x]<n/2)v[t[i].x]++,s+=a[t[i].s][t[i].x];
			else v[t[i].y]++,s+=a[t[i].s][t[i].y];
		}cout<<s<<endl;
	}return 0;
}
