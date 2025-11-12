#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
const int N=1e5+5;
inline int rd(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int t,n,a[N][4];
int st1[N<<1],st2[N<<1],st3[N<<1],top1,top2,top3,ans;
void solve(int *st,int top,int m){
	sort(st+1,st+top+1);
	for(re int i=1;i<=m;i++)ans-=st[i];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=rd();
	while(t--){
		vector<int>v[4];
		top1=top2=top3=ans=0;
		n=rd();
		for(re int i=1;i<=n;i++){
			a[i][1]=rd(),a[i][2]=rd(),a[i][3]=rd();
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])v[1].push_back(i),ans+=a[i][1],st1[++top1]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])v[2].push_back(i),ans+=a[i][2],st2[++top2]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
			else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2])v[3].push_back(i),ans+=a[i][3],st3[++top3]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
		}
		if(v[1].size()<=n/2&&v[2].size()<=n/2&&v[3].size()<=n/2){
			printf("%d\n",ans);
			continue;
		}
		if(v[1].size()>n/2)solve(st1,top1,v[1].size()-n/2);
		if(v[2].size()>n/2)solve(st2,top2,v[2].size()-n/2);
		if(v[3].size()>n/2)solve(st3,top3,v[3].size()-n/2);
		printf("%d\n",ans);
	}
	return 0;
}
