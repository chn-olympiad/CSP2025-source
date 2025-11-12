#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int maxn=100000+10;
int t,n,ans=-1,sum=0,sum1=0,sum2=0,ans1=0,ans2=0,ans3=0,ans4=-1,pop[maxn],po=0;
struct node{
	int a,b,c;
}p[maxn];
bool cmp(node x,node y){
	return x.a>y.a;
}
bool cmp1(node x,node y){
	return x.c>y.c;
}
bool cmp2(node x,node y){
	return x.b>y.b;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		memset(pop,0,sizeof(pop));
		po=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>p[i].a;
			pop[++po]=p[i].a;
			cin>>p[i].b;
			pop[++po]=p[i].b;
			cin>>p[i].c;
			pop[++po]=p[i].c;
			if(p[i].b==0&&p[i].c==0) sum++;
			else if(p[i].a==0&&p[i].b==0) sum1++;
			else if(p[i].a==0&&p[i].c==0) sum2++;
		} 
		if(n==2){
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i==j) continue;
					ans=max(ans,(pop[i]+pop[j+3]));
				}
			}
			cout<<ans<<endl;
		} 
		else if(sum==n){
			sort(p+1,p+n+1,cmp);
			for(int i=1;i<=n/2;i++) ans1+=p[i].a;
			cout<<ans1<<endl;
		}
		else if(sum1==n){
			sort(p+1,p+n+1,cmp1);
			for(int i=1;i<=n/2;i++) ans2+=p[i].c;
			cout<<ans2<<endl;
		}
		else if(sum2==n){
			sort(p+1,p+n+1,cmp2);
			for(int i=1;i<=n/2;i++) ans3+=p[i].b;
			cout<<ans3<<endl;
		}
		else if(n==4){
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for(int k=1;k<=3;k++){
						for(int p=1;p<=3;p++){
							if((i==j&&j==k)||(i==j&&i==k)||(i==j&&i==p)||(j==k&&k==p)) continue;
							ans4=max((pop[i]+pop[j+3]+pop[k+6]+pop[p+9]),ans4);
						}
					}
				}
			}
			cout<<ans4<<endl;
		}
	}
	return 0;
}