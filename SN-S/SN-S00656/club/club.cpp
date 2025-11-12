#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
bool Men;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}

const int N=200005;

struct node{
	int a,b,c;
}a[N];
int n;

void solve(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i].a=read(),a[i].b=read(),a[i].c=read();
	}
	int cnt1=0,cnt2=0,cnt3=0,maxx=n/2;
	priority_queue<int,vector<int>,greater<int>> q1; while(!q1.empty()) q1.pop();
	priority_queue<int,vector<int>,greater<int>> q2; while(!q2.empty()) q2.pop();
	priority_queue<int,vector<int>,greater<int>> q3; while(!q3.empty()) q3.pop();
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
			cnt1++;
			ans+=a[i].a;
			q1.push(min(a[i].a-a[i].b,a[i].a-a[i].c));
		}
		else if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
			cnt2++;
			ans+=a[i].b;
			q2.push(min(a[i].b-a[i].a,a[i].b-a[i].c));
		}
		else{
			cnt3++;
			ans+=a[i].c;
			q3.push(min(a[i].c-a[i].a,a[i].c-a[i].b));
		}
	}
	if(cnt1>maxx){
		while(cnt1>maxx){
			cnt1--;
			ans-=q1.top();q1.pop();
		}
	}
	else if(cnt2>maxx){
		while(cnt2>maxx){
			cnt2--;
			ans-=q2.top();q2.pop();
		}
	}
	else if(cnt3>maxx){
		while(cnt3>maxx){
			cnt3--;
			ans-=q3.top();q3.pop();
		}
	}
	cout<<ans<<endl;
	return;
}

bool Mbe;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("club5.in","r",stdin);
//	freopen("test.ans","w",stdout);
//	printf("%.8lfMB\n",(&Mbe-&Men)/1000000.0);
	int T=read();
	while(T--){
		solve();
	}
	return 0;
} 
