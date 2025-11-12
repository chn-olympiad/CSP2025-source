#include<bits/stdc++.h>
using namespace std;
int t,n,tong[5],ans=0,c1[100005],c2[100005];
struct node{
	int x,id;
}a[100005][5];
struct node1{
	int x1,id,id1;
}ch[100005];
bool cmp(node1 x,node1 y){
	return x.x1<y.x1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;ans=0;
		memset(tong,0,sizeof(tong));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
			scanf("%d",&a[i][j].x),a[i][j].id=j;
			if(a[i][1].x<a[i][2].x){
				swap(a[i][1].x,a[i][2].x);
				swap(a[i][1].id,a[i][2].id);
			}
			if(a[i][2].x<a[i][3].x){
				swap(a[i][2].x,a[i][3].x);
				swap(a[i][2].id,a[i][3].id);
			}
			if(a[i][1].x<a[i][2].x){
				swap(a[i][1].x,a[i][2].x);
				swap(a[i][1].id,a[i][2].id);
			}
			ch[i].x1=a[i][1].x-a[i][2].x;
			ch[i].id1=a[i][2].id;
			ch[i].id=a[i][1].id;
		}
		sort(ch+1,ch+n+1,cmp);
		for(int i=1;i<=n;i++)
		tong[a[i][1].id]++,ans+=a[i][1].x;
		int v=1;
		while(tong[1]>n/2){
			if(ch[v].id==1&&ch[v].id1!=1){
				tong[1]--;tong[ch[v].id1]++;
				ans-=ch[v].x1;
			}
			v++;
		}
		while(tong[2]>n/2){
			if(ch[v].id==2&&ch[v].id1!=2){
				tong[2]--;tong[ch[v].id1]++;
				ans-=ch[v].x1;
			}
			v++;
		}
		while(tong[3]>n/2){
			if(ch[v].id==3&&ch[v].id1!=3){
				tong[3]--;tong[ch[v].id1]++;
				ans-=ch[v].x1;
			}
			v++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
