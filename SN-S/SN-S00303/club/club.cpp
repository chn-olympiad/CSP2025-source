#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,q,ans;
struct eee{
	int a,b,c,hc;
}g[100006];
int club[3];
int highclub(int x,int y,int z){
	if(x > y&&x > z)return 1;
	if(y > x&&y > z)return 2;
	if(z > x&&z > y)return 3;
}
bool cmp(eee x,eee y){
	if(x.a > y.a) return 1;
	else if(x.a==y.a){
		if(x.b > y.b) return 1;
		else if(x.b==y.b) return x.c>y.c;
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> q;
	while(q--){
		ans=0,club[0]=club[1]=club[2]=0;
		cin >> n;
		int cl=n/2;
		for(int i=1;i<=n;i++){
			cin>>g[i].a>>g[i].b>>g[i].c;
			g[i].hc=highclub(g[i].a,g[i].b,g[i].c);
		}
		sort(g+1,g+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(g[i].hc==1&&club[0] < cl)
				club[0]++,ans+=g[i].a;
			else if(g[i].hc==2&&club[1] < cl)
				club[1]++,ans+=g[i].b;
			else if(g[i].hc==3&&club[2] < cl)
				club[2]++,ans+=g[i].c;
			else{
				if(g[i].hc==1){
					if(g[i].b>g[i].c&&club[1]<cl)
						club[1]++,ans+=g[i].b;
					else club[2]++,ans+=g[i].c;
				}
				if(g[i].hc==2){
					if(g[i].a>g[i].c&&club[0]<cl)
						club[0]++,ans+=g[i].a;
					else club[2]++,ans+=g[i].c;
				}
				if(g[i].hc==3){
					if(g[i].a>g[i].b&&club[0]<cl)
						club[0]++,ans+=g[i].a;
					else club[1]++,ans+=g[1].b;
				}
			}
		}
		cout << ans <<"\n";
	}
	return 0;
}

