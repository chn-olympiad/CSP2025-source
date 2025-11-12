#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();
	int x,y=1;
	if(c=='-')y=-1;
	c=getchar();
	while(c>='0'&&c<='9'){
	   x=x*10+c-'0';
	   c=getchar();
	}
	return x*y;
}
struct node{
	int ans,id;
};
int t,n,a[100005][4];
node k1[100005],k2[100005],k3[100005];
int l1,l2,l3,rl1,rl2,rl3;
int ans;
bool cmp1(node u,node v){
	int u2=max(a[u.id][2],a[u.id][3]);
	int v2=max(a[v.id][2],a[v.id][3]);
	return (u.ans-u2)<(v.ans-v2);
}
bool cmp2(node u,node v){
	int u2=max(a[u.id][1],a[u.id][3]);
	int v2=max(a[v.id][1],a[v.id][3]);
	return (u.ans-u2)<(v.ans-v2);
}
bool cmp3(node u,node v){
	int u2=max(a[u.id][2],a[u.id][1]);
	int v2=max(a[v.id][2],a[v.id][1]);
	return (u.ans-u2)<(v.ans-v2);
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
    	scanf("%lld",&n);
    	//for(int i=1;i<=l1;i++)k1[i].id=k1[i].ans=0;
    	//for(int i=1;i<=l2;i++)k2[i].id=k2[i].ans=0;
    	//for(int i=1;i<=l3;i++)k3[i].id=k3[i].ans=0;
    	l1=l2=l3=0;
    	rl1=rl2=rl3=0;
    	for(int i=1;i<=n;i++)for(int j=1;j<=3;j++)scanf("%lld",&a[i][j]);
    	for(int i=1;i<=n;i++){
    		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
    			k1[++l1].ans=a[i][1];
    			k1[l1].id=i;
			}else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				k2[++l2].ans=a[i][2];
				k2[l2].id=i;
			}else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
				k3[++l3].ans=a[i][3];
				k3[l3].id=i;
			}
		}
		sort(k1+1,k1+1+l1,cmp1);
		sort(k2+1,k2+1+l2,cmp2);
		sort(k3+1,k3+1+l3,cmp3);
		if(l1>n/2){
			rl1=l1;
			int i=1;
			while(l1>n/2){
				if(a[k1[i].id][2]>=a[k1[i].id][3])k2[++l2].ans=a[k1[i].id][2],k2[l2].id=k1[i].id;
				else k3[++l3].ans=a[k1[i].id][3],k3[l3].id=k1[i].id;
				i++;
				k1[i-1].ans=0;
				l1--;
			}
			l1=rl1;
		}
		if(l2>n/2){
			rl2=l2;
		    int i=1;
			while(l2>n/2){
				if(a[k2[i].id][1]>=a[k2[i].id][3])k1[++l1].ans=a[k2[i].id][1],k1[l1].id=k2[i].id;
				else k3[++l3].ans=a[k2[i].id][3],k3[l3].id=k2[i].id;
				i++;
				k2[i-1].ans=0;
				l2--;
			}
			l2=rl2;
		}
		if(l3>n/2){
			rl3=l3;
			int i=1;
			while(l3>n/2){
				if(a[k3[i].id][2]>=a[k3[i].id][1])k2[++l2].ans=a[k3[i].id][2],k2[l2].id=k3[i].id;
				else k1[++l1].ans=a[k3[i].id][1],k1[l1].id=k3[i].id;
				i++;
				k3[i-1].ans=0;
				l3--;
			}
			l3=rl3;
		}
		int i=1;
		for(i=1;i<=l1;i++){
			ans+=k1[i].ans;
		}
		for(i=1;i<=l2;i++){
			ans+=k2[i].ans;
		}
		for(i=1;i<=l3;i++){
			ans+=k3[i].ans;
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}

