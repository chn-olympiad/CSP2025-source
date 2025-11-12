#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,c[N],va[N],vb[N];
string a[N],b[N];
bool check(string x,string y,int j,int i){
	for(int k=0;k<c[i];k++,j++)
		if(x[j]!=a[i][k]||y[j]!=b[i][k])
			return false;
	return true;
}
int find_a(int u){
	for(int i=0;i<c[u];i++)
		if(a[u][i]=='b') return i;
}
int find_b(int u){
	for(int i=0;i<c[u];i++)
		if(b[u][i]=='b') return i;
}
int find(string s,int len){
	for(int i=0;i<len;i++)
		if(s[i]=='b') return i;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		c[i]=a[i].size();
	}
	if(n<=100&&q<=100){
		while(q--){
			string x,y;
			cin>>x>>y;
			if(x.size()!=y.size()){
				printf("0\n");
				continue;
			}
			int len=x.size(),l,r;
			for(int i=0;i<len;i++)
				if(x[i]!=y[i]){
					l=i;break;
				}
			for(int i=len-1;i>=0;i--)
				if(x[i]!=y[i]){
					r=i;break;
				}
			
			int ans=0;
			for(int i=1;i<=n;i++){
				if(c[i]<r-l+1||c[i]>len) continue;
				if(c[i]==r-l+1){
					if(check(x,y,l,i))
						ans++;
				}
				else{
					for(int j=max(0,r-c[i]+1);j<=l&&j+c[i]-1<len;j++)
						if(check(x,y,j,i)) ans++;
				}
			}
			printf("%d\n",ans);
		}
	}
	else{
		for(int i=1;i<=n;i++)
			va[i]=find_a(i),vb[i]=find_b(i);
		while(q--){
			string x,y;
			cin>>x>>y;
			if(x.size()!=y.size()){
				printf("0\n");
				continue;
			}
			int len=x.size(),vx=find(x,len),vy=find(y,len);
			int ans=0;
			for(int i=1;i<=n;i++){
				if(vy-vx==vb[i]-va[i]&&va[i]<=vx&&c[i]-vb[i]<=len-vy)
					ans++;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
