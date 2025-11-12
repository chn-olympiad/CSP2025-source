#include <bits/stdc++.h>
using namespace std;
int n;
struct node{
	int a,b,c;
}e[100005];
long long ans;
int d1[100005],d2[100005],d3[100005],flag[100005]; 
int dd1,dd2,dd3,dd4;
bool cmp1(int x,int y){
	return e[x].a-max(e[x].b,e[x].c)>e[y].a-max(e[y].b,e[y].c);
}
bool cmp2(int x,int y){
	return e[x].b-max(e[x].a,e[x].c)>e[y].b-max(e[y].a,e[y].c);
}
bool cmp3(int x,int y){
	return e[x].c-max(e[x].a,e[x].b)>e[y].c-max(e[y].a,e[y].b);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while (T--){
		ans=0,dd1=0,dd2=0,dd3=0,dd4=0;
		memset(flag,0,sizeof(flag));
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>e[i].a>>e[i].b>>e[i].c;
			if (e[i].a>=e[i].b && e[i].a>=e[i].c){
				d1[++dd1]=i;
			}
			else if (e[i].b>=e[i].a && e[i].b>=e[i].c){
				d2[++dd2]=i;
			}
			else if (e[i].c>=e[i].a && e[i].c>=e[i].b){
				d3[++dd3]=i;
			}
		}
		if (dd1>n/2){
			sort(d1+1,d1+1+dd1,cmp1);
			int cnt=0;
			for (int i=1;i<=dd1;i++){
				if (cnt>=n/2){
					break;
				}
				cnt++;
				ans+=e[d1[i]].a;
				flag[d1[i]]=1;
			}
			for (int i=1;i<=n;i++){
				if (!flag[i]){
					ans+=max(e[i].b,e[i].c);
				}
			}
		}
		else if (dd2>n/2){
			sort(d2+1,d2+1+dd2,cmp2);
			int cnt=0;
			for (int i=1;i<=dd2;i++){
				if (cnt>=n/2){
					break;
				}
				cnt++;
				ans+=e[d2[i]].b;
				flag[d2[i]]=1;
			}
			for (int i=1;i<=n;i++){
				if (!flag[i]){
					ans+=max(e[i].a,e[i].c);
				}
			}
		}
		else if (dd3>n/2){
			sort(d3+1,d3+1+dd3,cmp3);
			int cnt=0;
			for (int i=1;i<=dd3;i++){
				if (cnt>=n/2){
					break;
				}
				cnt++;
				ans+=e[d3[i]].c;
				flag[d3[i]]=1;
			}
			for (int i=1;i<=n;i++){
				if (!flag[i]){
					ans+=max(e[i].a,e[i].b);
				}
			}
		}
		else{
			for (int i=1;i<=n;i++){
				ans+=max(max(e[i].a,e[i].b),e[i].c);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
