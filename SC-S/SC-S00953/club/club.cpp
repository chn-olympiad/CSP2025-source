#include<bits/stdc++.h>
#define N 100005
//#define int long long
#define LL long long
#define PII pair<int,int>
using namespace std;

int t,n,m,g[N],siz[4],ans,c[N];//g[i]:第i个人现在在哪一组
struct input{
	int num,idx;//num:满意度 idx:对哪一组的
}a[N][4];
priority_queue<PII,vector<PII>,greater<PII> > q[4];

bool cmp(input c,input b){
	return c.num>b.num;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j].num);
				a[i][j].idx=j;
			}
			sort(a[i]+1,a[i]+4,cmp);
			ans+=a[i][1].num;
			
			c[i]=a[i][1].num-a[i][2].num;
			q[a[i][1].idx].push(make_pair(c[i],i));
			g[i]=a[i][1].idx;
			if(q[a[i][1].idx].size()>n/2){
				PII f=q[a[i][1].idx].top();
				q[a[i][1].idx].pop();
				int fi=f.first,se=f.second;
				ans-=fi;
				c[se]=a[se][2].num-a[se][3].num;
				q[a[se][2].idx].push(make_pair(c[se],se));
				g[se]=a[se][2].idx;
			}
		}
		while(q[1].size()){
			q[1].pop();
		}
		while(q[2].size()){
			q[2].pop();
		}
		while(q[3].size()){
			q[3].pop();
		}
		printf("%d\n",ans);
	}
	
//	printf("\n%.0lf",(double)clock());
	return 0;
}//知颖你太美