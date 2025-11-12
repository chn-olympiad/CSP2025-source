#include<bits/stdc++.h>
using namespace std;
int t,vel[5],n;
long long ans;
struct node{int x,i;};
bool cmp(node a,node b){return a.x>b.x;}
struct node1{
	node f[5];
	int cha;
}a[100005];
bool cmp1(node1 a,node1 b){return a.cha>b.cha;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i].f[j].x);
				a[i].f[j].i=j;
			}
			sort(a[i].f+1,a[i].f+1+3,cmp);
			a[i].cha=a[i].f[1].x-a[i].f[2].x;
		}
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=n;i++){
			if(vel[a[i].f[1].i]>=n/2){
				vel[a[i].f[2].i]++;
				ans+=a[i].f[2].x;
			}else{
				vel[a[i].f[1].i]++;
				ans+=a[i].f[1].x;
			}
		}
		for(int i=1;i<=3;i++)vel[i]=0;
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
