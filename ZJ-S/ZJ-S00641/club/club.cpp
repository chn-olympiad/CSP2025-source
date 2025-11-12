#include <bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int x,y,z;
}a[100005];
bool cmpA(node l,node r){
	return l.x>r.x;
}
bool cmpB(node l,node r){
	if(l.x==r.x){
		return l.y>r.y;
	}else{
		return l.x>r.x;
	}
}
bool cmpC(node l,node r){
	if(l.y==r.y){
		return l.x>r.x;
	}else{
		return l.y>r.y;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		bool fA=1,fB=1;
		memset(a,0,sizeof a);
		cin>>n;
		int sx=0,sy=0,sz=0,sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].z!=0) fA=0,fB=0;
			if(a[i].y!=0) fA=0;
			if((a[i].x>a[i].y)&&(a[i].x>a[i].z)) sx++;
			else if((a[i].y>a[i].x)&&(a[i].y>a[i].z)) sy++;
			else sz++;
		}
		if(fA){
			sort(a+1,a+n+1,cmpA);
			for(int i=1;i<=n/2;i++){
				sum+=a[i].x;
			}
			cout<<sum<<endl;
			continue;
		}
		if(sx<=n/2&&sy<=n/2&&sz<=n/2){
			for(int i=1;i<=n;i++){
				sum+=max(a[i].x,max(a[i].y,a[i].z));
			}
			cout<<sum<<endl;
		}else{
			int sum1=0,sum2=0;
			sort(a+1,a+n+1,cmpB);
			for(int i=1;i<=n/2;i++){
				sum1+=a[i].x;
			}
			for(int i=n/2+1;i<=n;i++){
				sum1+=a[i].y;
			}
			sort(a+1,a+n+1,cmpC);
			for(int i=1;i<=n/2;i++){
				sum2+=a[i].y;
			}
			for(int i=n/2+1;i<=n;i++){
				sum2+=a[i].x;
			}
			cout<<max(sum1,sum2)<<endl;
		}
	}
	return 0;
}