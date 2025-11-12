#include<bits/stdc++.h>
using namespace std;
int n,T;
struct D{
	int v,idx,w;
}d[300005];
int s1,s2,s3;
int v;
int t1[5],t2[5],t3[5];
bool vis[100005][4];
//int stk[100005][4];
int ans,tans;
void add(int a,int i){
	if(a==1)s1+=d[i].v,vis[d[i].idx][1]=1,t1[d[i].w]++;
	else if(a==2)s2+=d[i].v,vis[d[i].idx][2]=1,t2[d[i].w]++;
	else if(a==3)s3+=d[i].v,vis[d[i].idx][3]=1,t3[d[i].w]++;
//	if (i==2)cout<<d[i].idx<<" "<<vis[d[i].idx][1]<<vis[d[i].idx][2]<<vis[d[i].idx][3]<<" ";
}
bool check(int a,int i){
	if(a==1)return t1[d[i].w]<v;
	else if(a==2)return t2[d[i].w]<v;
	else if(a==3)return t3[d[i].w]<v;
}
bool cmp(D a,D b){return a.v>b.v;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int o=1;o<=T;o++){
		cin>>n;
		v=n/2;
		int tr=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>d[++tr].v;
				d[tr].idx=i;
				d[tr].w=j;
			}
		}
		sort(d+1,d+n*3+1,cmp);
//		for(int i=1;i<=n*3;i++)cout<<d[i].v<<" ";
		s1=0,s2=0,s3=0;
		memset(t1,0,sizeof(t1));
		memset(t2,0,sizeof(t2));
		memset(t3,0,sizeof(t3));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n*3;i++){
//			cout<<vis[d[i].idx][1]<<vis[d[i].idx][2]<<vis[d[i].idx][3]<<"\n";
			if(vis[d[i].idx][1]&&vis[d[i].idx][2]&&vis[d[i].idx][3])continue;
			else if(vis[d[i].idx][1]&&vis[d[i].idx][2]){
				if(check(3,i))add(3,i);
			}
			else if(vis[d[i].idx][1]&&vis[d[i].idx][3]){
				if(check(2,i))add(2,i);
			}
			else if(vis[d[i].idx][2]&&vis[d[i].idx][3]){
				if(check(1,i))add(1,i);
			}
			else if(vis[d[i].idx][3]){
				if(s1>=s2){
					if(check(1,i))add(1,i);
					else if(check(2,i))add(2,i);
				}
				else{
					if(check(2,i))add(2,i);
					else if(check(1,i))add(1,i);
				}
			}
			else if(vis[d[i].idx][2]){
				if(s1>=s3){
					if(check(1,i))add(1,i);
					else if(check(3,i))add(3,i);
				}
				else{
					if(check(3,i))add(3,i);
					else if(check(1,i))add(1,i);
				}
			}
			else if(vis[d[i].idx][1]){
				if(s3>=s2){
					if(check(3,i))add(3,i);
					else if(check(2,i))add(2,i);
				}
				else{
					if(check(2,i))add(2,i);
					else if(check(3,i))add(3,i);
				}
			}
			else{
				if(s1>=s2){
					if(s1>=s3){
						if(check(1,i))add(1,i);
						else if(s2>=s3){
							if(check(2,i))add(2,i);
							else if(check(3,i))add(3,i);
						}
						else if(check(3,i))add(3,i);
						else if(check(2,i))add(2,i);
					}
					else{
						if(check(3,i))add(3,i);
						else if(check(1,i))add(1,i);
						else if(check(2,i))add(2,i);
					}
				}
				else{
					if(s1<s3){
						if(s2>=s3){
							if(check(2,i))add(2,i);
							else if(check(3,i))add(3,i);
						}
						else if(check(3,i))add(3,i);
						else if(check(2,i))add(2,i);
						else if(check(1,i))add(1,i);
					}
					else{
						if(check(2,i))add(2,i);
						else if(check(1,i))add(1,i);
						else if(check(3,i))add(3,i);
					}
				}
			}
		}
		ans=max(s1,max(s2,s3));
		cout<<ans;
		cout<<"\n";
	}
	return 0;
}
