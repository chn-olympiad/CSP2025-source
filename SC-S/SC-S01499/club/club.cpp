#include<bits/stdc++.h>
using namespace std;

const int N=1e4+7;

int in(){
	int k=0,t=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')t=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*t;
}

void out(int x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)return putchar(x+'0'),void(0);
	out(x/10),putchar(x%10+'0');
}

struct node{
	int x,y,z;
}a[N];

int n,cnt1,cnt2,cnt3;

//priority_queue<pair<int,int> > q1,q2,q3;

int ans=0;
void dfs(int x,int y,int z,int sum,int dep){
	//cout<<sum<<" "<<dep<<endl;
	if(dep>n){
		ans=max(sum,ans);
		return;
	}
	if(x<n/2)dfs(x+1,y,z,sum+a[dep].x,dep+1);
	if(y<n/2)dfs(x,y+1,z,sum+a[dep].y,dep+1);
	if(z<n/2)dfs(x,y,z+1,sum+a[dep].z,dep+1);
}

int pp1,pp2;
priority_queue<pair<int,int> > q1,q2;
priority_queue<int> q;
bool cmp(node a,node b){
	if(a.x==b.x)return a.y>b.y;
	return a.x>b.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=in();
	while(t--){
		ans=0;
		cnt1=0,cnt2=0,cnt3=0;
		pp1=0;pp2=0;
		n=in();
		for(int i=1;i<=n;i++){
			a[i].x=in();
			a[i].y=in();
			a[i].z=in();
			if(!a[i].y)pp1++;
			if(!a[i].z)pp2++;
			q.push(a[i].x);
		}
		sort(a+1,a+n+1,cmp);
		if(n<=10){
			dfs(0,0,0,0,1);	
			out(ans);
			putchar('\n');
		}
		if(pp2==n&&pp1==n){
			for(int i=1;i<=n/2;i++){
				ans+=q.top();
				q.pop();
			}
			out(ans);
			putchar('\n');
		}else if(pp2==n){
			for(int i=1;i<=n;i++){
				if(cnt1<n/2){
					if(a[i].x>a[i].y)q1.push({-a[i].x,i}),cnt1++;
					else{
						if(cnt2<n/2)q2.push({-a[i].y,i}),cnt2++;
					}
				}else{
					int tt=q1.top().second;
					if(a[tt].x+a[i].y<a[tt].y+a[i].x){
						q1.pop();
						q1.push({-a[i].x,i});
						q2.push({-a[tt].y,tt});
						cnt2++;
					}else{
						q2.push({-a[i].y,i});
						cnt2++;
					}
				}
			}
			while(!q1.empty()){
				int tt=q1.top().first;
				ans-=tt;
				q1.pop();
			}
			while(!q2.empty()){
				int tt=q2.top().first;
				ans-=tt;
				q2.pop();
			}
			out(ans);
			putchar('\n');
		}
		
	}

	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*


*/