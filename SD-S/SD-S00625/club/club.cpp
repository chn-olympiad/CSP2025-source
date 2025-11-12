#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t;
int n;
struct node{
	int a,b,c;
	int ch;
	int cha;
};
node a[N];
int cho[4];
int q[N];
int cnt;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		memset(cho,0,sizeof(cho));
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			ans+=max(a[i].a,max(a[i].b,a[i].c));
			if(a[i].a>a[i].b&&a[i].a>a[i].c) cho[1]++,a[i].ch=1,a[i].cha=a[i].a-max(a[i].b,a[i].c);
			else if(a[i].b>a[i].a&&a[i].b>a[i].c) cho[2]++,a[i].ch=2,a[i].cha=a[i].b-max(a[i].a,a[i].c);
			else cho[3]++,a[i].ch=3,a[i].cha=a[i].c-max(a[i].a,a[i].b);
		}
		cnt=0;
		int p=-1;
		int duo=-1;
		for(int i=1;i<=3;i++){
			if(cho[i]>(n/2)){
				p=i;
				duo=cho[i]-(n/2);
				break;
			} 
		}
		if(p==-1){
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			if(a[i].ch==p){
				q[++cnt]=a[i].cha;
			}
		}
//		cout<<duo<<'\n';
		sort(q+1,q+cnt+1,cmp);
		for(int i=1;i<=duo;i++) ans-=q[i];
		cout<<ans<<'\n';
	}
	return 0;
}

