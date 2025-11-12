#include<bits/stdc++.h>
using namespace std;
int n,q,cnt,g,h,w,e,ans;
string s[200005],c[200005],x,y;
vector<string> v[2005],d[2005];
bool p;
/*void add1(string m,int k){
	int l=m.length(),now=0;
	for(int i=0;i<l;i++){
		if(!nex[now][m[i]-'a']) nex[now][m[i]-'a']=++cnt;
		now=nex[now][m[i]-'a'];
	}
	nex[now][m[i]-'a']=
}*/
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	if(n<=1000){
		for(int i=1;i<=n;i++) {
			cin>>s[i]>>c[i];
			v[s[i].length()].push_back(s[i]);
			d[s[i].length()].push_back(c[i]);
		}
		while(q--){
			ans=0;
			w=-1,e=-1;
			cin>>x>>y;
			g=x.length();
			h=y.length();
			if(g!=h){
				printf("0\n");
				continue;
			}
			for(int i=0;i<g;i++) {
				if(x[i]!=y[i]){
					if(w==-1) w=i;
					e=i;
				}
			}
			for(int i=0;i<=w;i++)
			for(int j=e;j<g;j++){
				for(int k=0;k<v[j-i+1].size();k++){
					p=1;
					for(int ll=0;ll<j-i+1;ll++) {
						if(x[i+ll]!=v[j-i+1][k][ll]){
							p=0;
							break;
						}
					}
					if(!p) continue;
					for(int ll=0;ll<j-i+1;ll++) {
						if(y[i+ll]!=d[j-i+1][k][ll]){
							p=0;
							break;
						}
					}
					if(!p) continue;
					ans++;
				}
			}
			printf("%d\n",ans);
		}
	}
	else{
		while(q--){
			printf("0\n");
		}
	}
	return 0;
}