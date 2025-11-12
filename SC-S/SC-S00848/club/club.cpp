#include<bits/stdc++.h>
#define int long long
using namespace std;
int t;
int n;
int ans=0;
struct p{
	int num,id,ki;
}a[300010];
bool cmp(p x,p y){
	return x.num>y.num; 
}
int K[5];
bool vis[100010];
p b[10010];p c[10010];
void baosou1(int id,int sum,int A,int B,int C){
	if(A>n/2||B>n/2||C>n/2){
		return;
	}
	if(id==n){
		ans=max(ans,sum);
		return;
	}
	baosou1(id+1,sum+a[id+1].num,A+1,B,C);
	baosou1(id+1,sum+b[id+1].num,A,B+1,C);
	baosou1(id+1,sum+c[id+1].num,A,B,C+1);
}
void baosou2(int id,int sum,int A,int B){
	if(A>n/2||B>n/2){
		return;
	}
	if(id==n){
		ans=max(ans,sum);
		return;
	}
	baosou2(id+1,sum+b[id+1].num,A+1,B);
	baosou2(id+1,sum+c[id+1].num,A,B+1);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int T=1;T<=t;T++){
		cin>>n;
		ans=0;
		if(n<=15){
			for(int i=1;i<=n;i++){
				cin>>a[i].num>>b[i].num>>c[i].num;
			}
			baosou1(0,0,0,0,0);
			cout<<ans<<"\n";
			continue;
		}
		int cnt=0;
		bool flA=1,flB=1;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			a[++cnt].num=x;a[cnt].id=i;a[cnt].ki=1;
			a[++cnt].num=y;a[cnt].id=i;a[cnt].ki=2;
			a[++cnt].num=z;a[cnt].id=i;a[cnt].ki=3;
			if(z!=0){
				flA=0;flB=0;
			}
			if(y!=0){
				flA=0;
			}
		}
		if(flA==1){
			sort(a+1,a+cnt+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].num;
			}
			cout<<ans;
			continue;
		}
		else{
			sort(a+1,a+cnt+1,cmp);
			K[1]=n/2;K[2]=n/2;K[3]=n/2;
			for(int i=1;i<=cnt;i++){
				if(K[a[i].ki]>0&&vis[a[i].id]==0){
					ans+=a[i].num;
					vis[a[i].id]=1;
					K[a[i].ki]--;
				}
			}
			cout<<ans<<"\n";
			if(T!=t){
				for(int i=1;i<=100005;i++){
					vis[i]=0;
				}
			}
		}
	}
	return 0;
} 