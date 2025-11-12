#include<bits/stdc++.h>
using namespace std;
int t,n,maxr,a[100005][4],ans,x,y,z,cnt=-1;
void dfs(int pe,int bm){
	//cout<<pe<<" "<<bm<<" "<<x<<" "<<y<<" "<<z<<"\n";
	if(bm==1)x++;
	else if(bm==2)y++;
	else z++;
	//cout<<x<<" "<<y<<" "<<z;
	ans+=a[pe][bm];
	if(pe==n){
		cnt=max(ans,cnt);
		ans-=a[pe][bm];
		if(bm==1)x--;
		else if(bm==2)y--;
		else z--;
		return;
	}
	for(int q=1;q<=3;q++){
		if(q==1&&x+1>maxr)continue;
		if(q==2&&y+1>maxr)continue;
		if(q==3&&z+1>maxr)continue;
		dfs(pe+1,q);
	}
	ans-=a[pe][bm];
	if(bm==1)x--;
	else if(bm==2)y--;
	else z--;
}
int main(){
	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		x=0;y=0;z=0;
		cnt=-1;
		cin>>n;
		maxr=n/2;
		for(int j=1;j<=n;j++)cin>>a[j][1]>>a[j][2]>>a[j][3];
		for(int j=1;j<=3;j++)dfs(1,j);
		cout<<cnt<<"\n";
	}
}