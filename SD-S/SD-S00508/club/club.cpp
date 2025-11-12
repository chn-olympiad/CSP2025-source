#include <bits/stdc++.h>
#define fir first
#define sec second
#define INF 1e18
#define int long long
using namespace std;
const int MAXN=1e5+10;
const int mod=13331;
int t,n;
struct NUM{
	int num,id;
};
struct PP{
	NUM p[5];
	int pos=1;
}a[MAXN];
int read(){
	int f=1,num=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<1)+(num<<3)+c-'0';c=getchar();}
	return f*num;
}
void write(int x){
	if(x<0){putchar('-');x=(x^(~0))+1;}
	if(x>9)write(x/10);putchar(x%10+'0');
}

bool cmp(NUM x,NUM y){
	if(x.num==y.num)return x.id<y.id;
	return x.num>y.num;
}
bool cmpf(int x,int y){
	return a[x].p[a[x].pos].num-a[x].p[a[x].pos+1].num>a[y].p[a[y].pos].num-a[y].p[a[y].pos+1].num;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		vector<int>f;
		vector<int>s;
		vector<int>t;
		while(!f.empty())f.pop_back();
		while(!s.empty())s.pop_back();
		while(!t.empty())t.pop_back();
		n=read();
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i].p[j].id=j;
				a[i].p[j].num=read();
			}
			sort(a[i].p+1,a[i].p+4,cmp);
			ans+=a[i].p[1].num;
		}
		for(int i=1;i<=n;i++){
			if(a[i].p[1].id==1){
				f.push_back(i);
			}
			if(a[i].p[1].id==2){
				s.push_back(i);
			}
			if(a[i].p[1].id==3){
				t.push_back(i);
			}
		}
		sort(f.begin(),f.end(),cmpf);
		sort(s.begin(),s.end(),cmpf);
		sort(t.begin(),t.end(),cmpf);
		if((int)f.size()>n/2){
			int k=f.size()-n/2;
			while(k--){
				int u=f[k+n/2];
				ans-=a[u].p[a[u].pos].num-a[u].p[a[u].pos+1].num;
			}
		}
		else if((int)s.size()>n/2){
			int k=s.size()-n/2;
			while(k--){
				int u=s[k+n/2];
				ans-=a[u].p[a[u].pos].num-a[u].p[a[u].pos+1].num;
			}
			
		}
		else if((int)t.size()>n/2){
			int k=t.size()-n/2;
			while(k--){
				int u=t[k+n/2];
				ans-=a[u].p[a[u].pos].num-a[u].p[a[u].pos+1].num;
			}
			
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
