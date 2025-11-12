#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
int cnt[3];
struct node{
	int a,b,c,maxx,minn;
	int delta;
}s[100010];
bool cmp(node a,node b){
	if(a.maxx!=b.maxx) return a.maxx>b.maxx;
	return a.minn>b.minn;
}
int getind(int i,int t){
	if(s[i].a==t) return 0;
	if(s[i].b==t) return 1;
	if(s[i].c==t) return 2;
	else return 3;
}
void work(){
	int n;
		priority_queue<int,vector<int>,greater<int> > q1,q2,q3;
		scanf("%d",&n);
		cnt[0]=0;
		cnt[1]=0;
		cnt[2]=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
			int st[3];
			st[0]=s[i].a;
			st[1]=s[i].b;
			st[2]=s[i].c;
			sort(st,st+3);
			s[i].delta=st[2]-st[1];
			s[i].maxx=st[2];
			s[i].minn=st[1];
			//cout<<st[2]<<' '<<st[1]<<' '<<s[i].delta<<endl;
		}
		sort(s+1,s+1+n,cmp);
		int ans=0;
		for(int i=1;i<=n;i++){
			int maxx=s[i].maxx;
			int mid=s[i].minn;
			int ind=getind(i,maxx);
			//cout<<s[i].maxx<<' '<<ind<<endl;
			if(cnt[ind]<n/2){
				if(ind==0) q1.push(s[i].delta);
				else if(ind==1) q2.push(s[i].delta);
				else if(ind==2) q3.push(s[i].delta);
				ans+=maxx;
				cnt[ind]++;
			}
			else{
				int top;
				if(ind==0){
					top=q1.top();
				} 
				else if(ind==1){
					top=q2.top();
				}
				else if(ind==2){
					top=q3.top();
				}
				//cout<<top<<' '<<s[i].delta<<endl;
				if(s[i].delta>top){
					ans=ans+s[i].maxx-top;
					if(ind==0){
						q1.pop();
						q1.push(s[i].delta);
					} 
					else if(ind==1){
						q2.pop();
						q2.push(s[i].delta);
					}
					else if(ind==2){
						q3.pop();
						q3.push(s[i].delta);
					}
				}
				else ans+=s[i].minn;
			}
		}
		printf("%d\n",ans);
		return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		work();
	}
	return 0;
}
