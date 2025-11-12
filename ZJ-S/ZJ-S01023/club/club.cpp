#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	int f=1;x=0;char s=getchar();
	while (s<'0'||s>'9'){if (s=='-'){f=-f;}s=getchar();}
	while (s>='0'&&s<='9'){x=(x<<1)+(x<<3)+s-'0';s=getchar();}
	x*=f;
}
const int MAXN=1e5+5;
int T,n;
int t[MAXN][3];
int f[205][205][205];
bool flagA,flagB;
bool cmp(int x,int y){
	return x>y;
}

void workA(){
	int a[MAXN];
	for (int i=1;i<=n;i++){
		a[i]=t[i][0];
	}
	sort(a+1,a+n+1,cmp);
	int ans=0;
	for (int i=1;i<=n/2;i++) ans+=a[i];
	printf("%d\n",ans);
	return;
}
struct node{
	int x,y;
};
bool cmp2(node a,node b){
	return a.x-a.y>b.x-b.y;
}
void workB(){
	node a[MAXN];
	for (int i=1;i<=n;i++){
		a[i].x=t[i][0];a[i].y=t[i][1];
	}
	sort(a+1,a+n+1,cmp2);
	int ans=0;
	for (int i=1;i<=n/2;i++)ans+=a[i].x;
	for (int i=n/2+1;i<=n;i++) ans+=a[i].y;
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T);
	while (T--){
		read(n);
		flagA=true;
		flagB=true;
		for (int i=1;i<=n;i++){
			read(t[i][0]);read(t[i][1]);read(t[i][2]);
			if (t[i][1]) flagA=false;
			if (t[i][2]) flagA=flagB=false;
		}
		if (flagA){
			workA();
			continue;
		}
		else if (flagB){
			workB();
			continue;
		}
		memset(f,0,sizeof(f));
		for (int i=1;i<=n;i++){
			for (int a=min(i,n/2);a>=0;a--){
				for (int b=min(i-a,n/2);b>=0;b--){
					int c=i-a-b;
					if (c>n/2) continue;
					if (a) f[a][b][c]=max(f[a][b][c],f[a-1][b][c]+t[i][0]);
					if (b) f[a][b][c]=max(f[a][b][c],f[a][b-1][c]+t[i][1]);
					if (c) f[a][b][c]=max(f[a][b][c],f[a][b][c-1]+t[i][2]);
				}
			}
		}
		int maxx=0;
		for (int a=0;a<=n/2;a++){
			for (int b=0;b<=min(n/2,n-a);b++){
				int c=n-a-b;
				if (c>n/2) continue;
				maxx=max(maxx,f[a][b][c]);
			}
		}
		printf("%d\n",maxx);
	}
	return 0;
}

