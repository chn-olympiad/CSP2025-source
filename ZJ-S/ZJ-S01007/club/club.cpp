#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z,cha1,cha2;
}a[100050];
struct nodee{
	int num,id;
}q[4];
int t,n,ans,cnt[4],cha[4],i2;
bool cmp(node x,node y){
	if(x.cha1==y.cha1){
		return x.cha2>y.cha2;
	}
	return x.cha1>y.cha1;
}
bool cmp2(nodee x,nodee y){
	return x.num>y.num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		memset(a,0,sizeof(a));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			cha[1]=a[i].x;
			cha[2]=a[i].y;
			cha[3]=a[i].z;
			sort(cha+1,cha+4);
			a[i].cha1=cha[3]-cha[2];
			a[i].cha2=cha[2]-cha[1];
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			i2=0;
			q[1].num=a[i].x;
			q[2].num=a[i].y;
			q[3].num=a[i].z;
			q[1].id=1;
			q[2].id=2;
			q[3].id=3;
			sort(q+1,q+4,cmp2);
			while(++i2){
				if(cnt[q[i2].id]==n/2)
					continue;
				else{
					cnt[q[i2].id]++;
					ans+=q[i2].num;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
}
