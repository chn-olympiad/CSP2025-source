#include<bits/stdc++.h>
#define int long long
using namespace std;
inline void read(int &x){
	x=0;char v=getchar();int f=1;
	while(v<'0'||v>'9'){
		if(v=='-') f=-1;
		v=getchar();
	}
	while(v>='0'&&v<='9'){
		x=(x<<1)+(x<<3)+(v&15);
		v=getchar(); 
	}
	x*=f;
}
const int N = 100010;
int T;
struct node{
	int a,b,c;
}aa[N];
int n;
int w[N];
int ans=0;
void dfs(int dep,int a,int b,int c){
		if(a>(n/2)||b>(n/2)||c>(n/2)) return;
	if(dep==n+1&&(a<=(n/2))&&(b<=(n/2))&&(c<=(n/2))&&(a+b+c)==n){
		int sum=0;
		for(int i=1;i<dep;i++){
//			cout<<w[i]<<' ';
			if(w[i]==1) sum+=aa[i].a;
			if(w[i]==2) sum+=aa[i].b;
			if(w[i]==3) sum+=aa[i].c;
		}
//		cout<<endl;
		ans=max(ans,sum);
		return;
	}
	w[dep]=1;
	dfs(dep+1,a+1,b,c);
	w[dep]=2;
	dfs(dep+1,a,b+1,c);
	w[dep]=3;
	dfs(dep+1,a,b,c+1);
	return;
}
int cmp1(node x,node y){
	return x.a>y.a;
}
int cmp2(node x,node y){
	return x.b>y.b;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	read(T);
	while(T--){
		read(n);
		ans=0;
		for(int i=1;i<=n;i++) read(aa[i].a),read(aa[i].b),read(aa[i].c);
		if(n>30){
			sort(aa+1,aa+1+n,cmp1);
			int sum=0,num=0;
			for(int i=1;i<=n;i++){
				if(i<=(n/2)) sum+=aa[i].a; 
				else sum+=aa[i].b;
			}
			sort(aa+1,aa+1+n,cmp2);
			for(int i=1;i<=n;i++){
				if(i<=(n/2)) num+=aa[i].b; 
				else num+=aa[i].a;
			}
			printf("%lld\n",max(sum,num));
			continue;
		}
		dfs(1,0,0,0);
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}