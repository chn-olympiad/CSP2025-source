//25pts
#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int n;
struct node{
	int x,y,z;
}a[100005];
int c[3];
bool f[3];
bool cmp(node x,node y){
	if(!f[0]&!f[1]&&!f[2])return max(x.x,max(x.y,x.z))>max(y.x,max(y.y,y.z));
	else if(!f[0]&&!f[1])return max(x.x,x.y)>max(y.x,y.y);
	else if(!f[0]&&!f[2])return max(x.x,x.z)>max(y.x,y.z);
	else if(!f[1]&&!f[2])return max(x.y,x.z)>max(y.y,y.z);
	else if(!f[0])return x.x>y.x;
	else if(!f[1])return x.y>y.y;
	else if(!f[2])return x.z>y.z;
}
int ans;
void run(int pos){
	if(!f[0]&!f[1]&&!f[2]){
		int t=max(a[pos].x,max(a[pos].y,a[pos].z));
		if(t==a[pos].x){
			++c[0];if(c[0]==n/2)f[0]=1,sort(a+pos+1,a+n+1,cmp);
		}else if(t==a[pos].y){
			++c[1];if(c[1]==n/2)f[1]=1,sort(a+pos+1,a+n+1,cmp);
		}else{
			++c[2];if(c[2]==n/2)f[2]=1,sort(a+pos+1,a+n+1,cmp);
		}
		ans+=t;
	}else if(!f[0]&&!f[1]){
		int t=max(a[pos].x,a[pos].y);
		if(t==a[pos].x){
			++c[0];if(c[0]==n/2)f[0]=1,sort(a+pos+1,a+n+1,cmp);
		}else if(t==a[pos].y){
			++c[1];if(c[1]==n/2)f[1]=1,sort(a+pos+1,a+n+1,cmp);
		}
		ans+=t;
	}else if(!f[0]&&!f[2]){
		int t=max(a[pos].x,a[pos].z);
		if(t==a[pos].x){
			++c[0];if(c[0]==n/2)f[0]=1,sort(a+pos+1,a+n+1,cmp);
		}else if(t==a[pos].z){
			++c[2];if(c[2]==n/2)f[2]=1,sort(a+pos+1,a+n+1,cmp);
		}
		ans+=t;
	}else if(!f[1]&&!f[2]){
		int t=max(a[pos].y,a[pos].z);
		if(t==a[pos].y){
			++c[1];if(c[1]==n/2)f[1]=1,sort(a+pos+1,a+n+1,cmp);
		}else if(t==a[pos].z){
			++c[2];if(c[2]==n/2)f[2]=1,sort(a+pos+1,a+n+1,cmp);
		}
		ans+=t;
	}else if(!f[0])++c[0],ans+=a[pos].x;
	else if(!f[1])++c[1],ans+=a[pos].y;
	else if(!f[2])++c[2],ans+=a[pos].z;
}
void dfs(int x,int sum,int t1,int t2,int t3){
	if(x==n+1){
		ans=max(ans,sum);
		return;
	}
	if(t1<(n>>1))dfs(x+1,sum+a[x].x,t1+1,t2,t3);
	if(t2<(n>>1))dfs(x+1,sum+a[x].y,t1,t2+1,t3);
	if(t3<(n>>1))dfs(x+1,sum+a[x].z,t1,t2,t3+1);
}
bool cmp1(node x,node y){
	return x.x>y.x;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		bool f1=1;
		for(int i=1;i<=n;++i){
			cin>>a[i].x>>a[i].y>>a[i].z;
			f1&=(!a[i].y&&!a[i].z);
		}
		ans=0;
		if(n<=10){
			dfs(1,0,0,0,0);
			cout<<ans<<'\n';
		}else if(f1){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=(n>>1);++i)ans+=a[i].x;
			cout<<ans<<'\n';
		}else{
			f[0]=f[1]=f[2]=c[0]=c[1]=c[2]=ans=0;
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n;++i)run(i);
			cout<<ans<<'\n';
		}
	}
	return 0;
}
/*
16:42 got 73 pts(finish T1,T2's wrong answer)
16:44 have no idea for T3 but BF can get maybe 10 pts?
17:02 delicious
17:02 found a mistake
17:16 deliuious
17:16 maybe found how to solve T3-B
17:37 BF
17:44 can't solve T3-B
17:44 I think ZHX has already AKed
17:59 finish T4 BF(n<=10)
17:59 all:25+48+25+8=106
18:17 check the file and freopen
18:18 all right
*/

/*
rp++

I can't get more score.
I can't make it.
Only hope -J 400

If T1 AC,I will get 181pts and maybe 1=
but

Hope CCF's data is water.

End here
*/
