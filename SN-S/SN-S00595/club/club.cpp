#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
struct Node{
	int f;
	int num;
}q1[N],q2[N],q3[N];
int t,n,a[N][9],ans,rec[N];
bool vis[N];
bool cmp(Node a,Node b){
	return a.f>b.f;
}
int main(){
	freopen(club.in,"r",stdin);
	freopen(club.out,"w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		ans=0;
		memset(vis,false,sizeof(vis));
		memset(rec,0,sizeof(rec));
		//memset(group,0,sizeof(group));
		for(int i=1;i<=n;i++){
			q1[i].f=a[i][1];
			q1[i].num=i;
		}
		for(int i=1;i<=n;i++){
			q2[i].f=a[i][2];
			q2[i].num=i;
		}
		for(int i=1;i<=n;i++){
			q3[i].f=a[i][3];
			q3[i].num=i;
		}
		sort(q1+1,q1+n+1,cmp);
		sort(q2+1,q2+n+1,cmp);
		sort(q3+1,q3+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=q1[i].f;
			vis[q1[i].num]=true;
			rec[q1[i].num]=q1[i].f;
			//group[q1[i].num]=1;
		}
		cout<<ans<<endl;
		//peo1=n/2;
		for(int i=1;i<=n/2;i++){
			if(vis[q2[i].num]){
				if(q2[i].f>rec[q2[i].num]){
					ans-=rec[q2[i].num];
					ans+=q2[i].f;
					rec[q2[i].num]=q2[i].f;
					//group[q2[i].num]=2;
					//peo1--;
					//peo2++;
				}
			}
			else ans+=q2[i].f;
		}
		cout<<ans<<endl;
		for(int i=1;i<=n/2;i++){
			if(vis[q3[i].num]){
				if(q3[i].f>rec[q3[i].num]){
					ans-=rec[q3[i].num];
					ans+=q3[i].f;
					rec[q3[i].num]=q3[i].f;
					//if(group[q3[i].num]==1){
						//peo1--;
						//peo3++;
					//}
					//else{
						//peo2--;
						//peo3++;
					//}
				}
			}
			else ans+=q3[i].f;
		}
		cout<<ans<<endl;
	}
	return 0;
}
