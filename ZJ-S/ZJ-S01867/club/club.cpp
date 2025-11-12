#include<bits/stdc++.h>
using namespace std;
int n,x,y,z,ans,T;
int b[3];
struct sss{
	int val,pos;
}a[1000010];
bool cmp(sss a,sss b){
	return a.val>b.val;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		b[0]=b[1]=b[2]=0,ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&x,&y,&z);
			ans+=max(x,max(y,z));
			if(x>=y&&y>=z) a[i].pos=0,a[i].val=x-y;
			else if(x>=z&&z>=y) a[i].pos=0,a[i].val=x-z;
			else if(y>=z&&z>=x) a[i].pos=1,a[i].val=y-z;
			else if(y>=x&&x>=z) a[i].pos=1,a[i].val=y-x;
			else if(z>=x&&x>=y) a[i].pos=2,a[i].val=z-x;
			else a[i].pos=2,a[i].val=z-y;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(b[a[i].pos]==n/2) ans-=a[i].val;
			else b[a[i].pos]++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
