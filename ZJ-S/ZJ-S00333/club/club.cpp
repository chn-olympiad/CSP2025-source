#include<bits/stdc++.h>
using namespace std;
#define int long long
#define p_ putchar(' ')
#define pn putchar('\n')
void write(int x){
	if(x<0){
		putchar('-');
		write(-x);
		return ;
	}
	if(x>=10){
		write(x/10);
	}
	putchar(x%10+'0');
}
int read(){
	int w=1,s=0;
	char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-')ch=getchar();
	if(ch=='-'){
		w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return w*s;
}
int n,num[5];
struct qwq{
	int s,x;
}a[100005][5];
bool cmp(qwq X,qwq Y){
	return X.s>Y.s;
}
int calc(int i){
	return a[i][2].s-a[i][1].s;
}
priority_queue<int>q[5];
void solve(){
	for(int i=1;i<=3;i++)num[i]=0;
	for(int i=1;i<=3;i++)
	while(!q[i].empty())q[i].pop();
	n=read();
	for(int i=1;i<=n;i++){
		int t1=read(),t2=read(),t3=read();
		a[i][1]=(qwq){t1,1};
		a[i][2]=(qwq){t2,2};
		a[i][3]=(qwq){t3,3};
		sort(a[i]+1,a[i]+1+3,cmp);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		q[a[i][1].x].push(calc(i));
		num[a[i][1].x]++;
		if(num[a[i][1].x]<=n/2){
			ans+=a[i][1].s;
		}
		else {
			ans+=a[i][1].s+q[a[i][1].x].top();
			q[a[i][1].x].pop();
			num[a[i][1].x]--;
		}
	}
	write(ans);pn;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		solve();
	}
}

