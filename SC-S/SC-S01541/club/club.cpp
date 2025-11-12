#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,l[4];//l人数
long long ans;
struct cat{
	int x,y,z,t;
}a[N];
bool operator<(cat xx,cat yy){
	return xx.t<yy.t;
}
priority_queue<cat> k;
priority_queue<int> q[4];//反悔数组(最多有一个社团会出现反悔贪心)
int sr;//输入
char c;
int read(){
	sr=0;
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9'){
		sr=sr*10+c-'0';
		c=getchar();
	}
	return sr;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		while(!k.empty())k.pop();
		for(int i=1;i<=3;i++){
			l[i]=0;
			while(!q[i].empty())
				q[i].pop();
		}
		for(int i=1;i<=n;i++){
			a[i].x=read();
			a[i].y=read();
			a[i].z=read();
			a[i].t=max(a[i].x,max(a[i].y,a[i].z));
			k.push(a[i]);
		}
		while(!k.empty()){
			int x=0;
			cat miao=k.top();
			k.pop();
			if(miao.x==miao.t)x=1;
			else if(miao.y==miao.t)x=2;
			else x=3;
			int v=max((x!=1)*miao.x,max((x!=2)*miao.y,(x!=3)*miao.z));
			if(l[x]<n/2){
				ans+=miao.t;
				l[x]++;
				q[x].push(v-miao.t);
			}
			else{
				if(miao.t+q[x].top()>v){
					ans+=miao.t+q[x].top();
					q[x].pop();
					q[x].push(v-miao.t);
				}
				else ans+=v;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
