#include<bits/stdc++.h>
using namespace std;
struct in{
	int z,x,c;
}a[1000044],s[200044];
bool ppp(in a,in s){
	return a.c<s.c;
}
int fa[20044],d[14];
bool pd[14];
int find(int q){
	return fa[q]==q?q:fa[q]=find(fa[q]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int z,x,c;
	cin>>z>>x>>c;
	int zc=z+c;
	for(int i=1;i<=zc;i++){
		fa[i]=i;
	}
	for(int i=1;i<=x;i++){
		cin>>a[i].z>>a[i].x>>a[i].c;
	}
	sort(a+1,a+1+x,ppp);
	int sl=0;
	long long ans=LLONG_MAX,res=0;
	for(int i=1;i<=x;i++){
		int q=find(a[i].z),w=find(a[i].x);
		if(q!=w){
			sl++;
			s[sl].z=a[i].z;s[sl].x=a[i].x;s[sl].c=a[i].c;
			res+=a[i].c;
			fa[q]=w;
			if(sl==z-1)break;
		}
	}
	ans=res;
	for(int i=1;i<=c;i++){
		cin>>d[i];
		for(int j=1;j<=z;j++){
			sl++;
			s[sl].z=z+i;s[sl].x=j;
			cin>>s[sl].c;
		}
	}
	sort(s+1,s+1+sl,ppp);
	int cc=pow(2,c),sll,xy;
	for(int i=1;i<cc;i++){
		res=0;sll=0;xy=z-1;
		for(int j=1;j<=zc;j++){
			fa[j]=j;
		}
		for(int j=0;j<c;j++){
			if(((i>>j)&1))pd[j+1]=1,res+=d[j+1],xy++;
			else pd[j+1]=0;
		}
		for(int j=1;j<=sl;j++){
			if(s[j].z>z&&pd[s[j].z-z]==0){
				continue;
			}
			int q=find(s[j].z),w=find(s[j].x);
			if(q!=w){
				res+=s[j].c;
				fa[q]=w;
				sll++;
				if(sll==xy)break;
			}
		}
		if(res<ans)ans=res;
	}
	cout<<ans;
	return 0;
}
