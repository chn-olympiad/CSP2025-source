#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int T,n,ans,ans2,aa,bb,cc;
struct edge{
	int a,b,c,v;
}f[N];
void dfs(int s,int aa,int bb,int cc,int x){
	if(x>n){
		ans=max(ans,s);
		return ;
	}if(aa+1<=n/2){
		dfs(s+f[x].a,aa+1,bb,cc,x+1);
	}if(bb+1<=n/2){
		dfs(s+f[x].b,aa,bb+1,cc,x+1);
	}if(cc+1<=n/2){
		dfs(s+f[x].c,aa,bb,cc+1,x+1);
	}
}bool cmp(edge x,edge y){
	return max(x.a,x.b)>max(y.a,y.b);
}

int main(){

freopen("club.in","r",stdin);
freopen("club.out","w",stdout);

cin>>T;
while(T--){
	bool flag=1,flag2=1;
	ans=ans2=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>f[i].a>>f[i].b>>f[i].c;
		f[i].v=0;
		if(f[i].b!=0 || f[i].c!=0){
			flag=0;
		}if(f[i].c!=0){
			flag2=0;
		}
	}if(flag){
		sort(f+1,f+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=f[i].a;
		}cout<<ans<<endl;
		continue;
	}if(flag2){
		sort(f+1,f+n+1,cmp);
		for(int i=1,j=1,k=1;i<=n/2;i++){
			if(j<=n/2 && f[i].a>f[i].b){
				ans+=f[i].a;
				j++;
			}else if(k<=n/2 && f[i].b>f[i].a){
				ans+=f[i].b;
				k++;
			}
		}
	}dfs(0,0,0,0,1);
	cout<<ans<<endl;
}

return 0;
}
