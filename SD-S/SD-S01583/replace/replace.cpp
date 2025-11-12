#include<bits/stdc++.h>
using namespace std;
int n,q,ans,minn=1e9;
string s1,s2;
char c[5000005];
int ll[200005],rr[200005];
string x[200005],y[200005];
string xx[200005],yy[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		int len=x[i].size();
		minn=min(minn,len);
		if(x[i]!=y[i]){
			int l=1e9,r=0;
			for(int j=0;j<len;j++){
				if(x[i][j]!=y[i][j]){
					l=min(l,j);
					r=max(r,j);
				}
			}
			ll[i]=l,rr[i]=r;
			xx[i]=x[i].substr(l,r-l+1);
			yy[i]=y[i].substr(l,r-l+1);
		}
	}
	while(q--){
		cin>>s1>>s2;
		ans=0;
		if(s1.size()!=s2.size()){
			printf("0\n");
			continue;
		}
		if(s1.size()<minn){
			printf("0\n");
			continue;
		}
		int l=1e9,r=0;
		for(int i=0;i<s1.size();i++){
			if(s1[i]!=s2[i]){
				c[i]=s2[i];
				l=min(l,i);
				r=max(r,i);
			}
		}
		string p=s1.substr(l,r-l+1);
		string q=s2.substr(l,r-l+1);
		for(int i=1;i<=n;i++){
			if(x[i].size()<(r-l+1)||x[i].size()>s1.size()){
				continue;
			}
			if(xx[i]!=p||yy[i]!=q){
				continue;
			}
			if(l<ll[i]){
				continue;
			}
			string p1=s1.substr(l-ll[i],x[i].size()); 
			string q1=s2.substr(l-ll[i],x[i].size()); 
			if(p1==x[i]&&q1==y[i]){ 
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

