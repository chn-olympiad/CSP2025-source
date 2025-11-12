#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T,n; 
struct L{
	int a,b,c;
}p[100005];
vector<int>x,y,z;
bool cx(int u,int v){
	return min(p[u].a - p[u].b,p[u].a - p[u].c) > min(p[v].a - p[v].b,p[v].a - p[v].c);
}
bool cy(int u,int v){
	return min(p[u].b - p[u].a,p[u].b - p[u].c) > min(p[v].b - p[v].a,p[v].b - p[v].c);
}
bool cz(int u,int v){
	return min(p[u].c - p[u].b,p[u].c - p[u].a) > min(p[v].c - p[v].b,p[v].c - p[v].a);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	cout << time(0) << "\n";
	scanf("%d",&T);
	while(T--){
		int ans = 0;
		scanf("%d",&n);
		x.clear();
		y.clear();
		z.clear();
		for(int i = 1;i<=n;i++)scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
		for(int i = 1;i<=n;i++){
			if(p[i].a > p[i].c){
				if(p[i].a > p[i].b)x.push_back(i);
				else y.push_back(i);
			}
			else{
				if(p[i].c > p[i].b)z.push_back(i);
				else y.push_back(i);
			}
		}
		int nl = x.size(),nm = y.size(),nn = z.size();
		if(nl > n/2){
			sort(x.begin(),x.end(),cx);
			while(nl > n/2){
				nl--;
				if(p[x[nl]].b > p[x[nl]].c)y.push_back(x[nl]);
				else z.push_back(x[nl]);
				x.pop_back();
			}
		}
		if(nm > n/2){
			sort(y.begin(),y.end(),cy);
			while(nm > n/2){
				nm--;
				if(p[y[nm]].a > p[x[nl]].c)x.push_back(y[nm]);
				else z.push_back(y[nm]);
				y.pop_back();
			}
		}
		if(nn > n/2){
			sort(z.begin(),z.end(),cz);
			while(nn > n/2){
				nn--;
				if(p[z[nn]].b > p[z[nn]].a)y.push_back(z[nn]);
				else x.push_back(z[nn]);
				z.pop_back();
			}
		}
		for(auto t : x)	ans += p[t].a;
		for(auto t : y)	ans += p[t].b;
		for(auto t : z) ans += p[t].c;
		printf("%d\n",ans);
	}//cout << time(0);
	return 0;
}

