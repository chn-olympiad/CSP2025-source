//Li Ruisi SN-S00368 Xi'an Tieyi High School
#include<bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define mod (998244353)
#define int long long
using namespace std;
inline int read(){
	int n=0,s=1;
	char x=0;
	while((x=getchar())<'0'||x>'9')
		if(x=='-')
			s=-1;
	while(x>='0'&&x<='9'){
		n=(n*10)+(x^48);
		x=getchar();
	}
	return n*s;
}
void write(int n,char x=0){
	if(n<0){
		putchar('-');
		n=-n;
	}
	if(n>=10)write(n/10);
	putchar('0'+n%10);
	if(x)putchar(x);
}
int a[100001][3];
void work(){
	int n=read();
	for(int i=1;i<=n;i++)a[i][0]=read(),a[i][1]=read(),a[i][2]=read();
	int x=0,y=0,z=0;
	priority_queue<int>que[3];
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i][0]>a[i][1]&&a[i][0]>a[i][2])x++,ans+=a[i][0],que[0].push(max(a[i][1],a[i][2])-a[i][0]);
		else if(a[i][1]>a[i][2])y++,ans+=a[i][1],que[1].push(max(a[i][0],a[i][2])-a[i][1]);
		else z++,ans+=a[i][2],que[2].push(max(a[i][1],a[i][0])-a[i][2]);
	}
	while(x>n/2)x--,ans+=que[0].top(),que[0].pop();
	while(y>n/2)y--,ans+=que[1].top(),que[1].pop();
	while(z>n/2)z--,ans+=que[2].top(),que[2].pop();
	write(ans,'\n');
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int aqx=read();
	while(aqx--)work();
	return 0;
}

