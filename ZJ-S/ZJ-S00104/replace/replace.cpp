#include<bits/stdc++.h>
using namespace std;
int n,m,k,l,r,s;
char w[5000005],z[5000005];
string x,y,a[20005],b[20005];
int main(){
	freopen("replace1.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	while(m--){
		cin>>x>>y;
		int t=x.size();
		l=r=-1,k=0,s=0;
		for(int i=0;i<t;i++){
			if(x[i]!=y[i]&&l==-1)l=i;
			if(x[i]!=y[i])r=i;
		}for(int i=l;i<=r;i++)w[k]=x[i],z[k]=y[i],k++;
		for(int i=1;i<=n;i++){
			if(a[i].size()<strlen(w))continue;
			int v=a[i].find(w);
			if(v==-1)continue;
			v=b[i].find(z);
			if(v==-1)continue;
			s++;
		}cout<<s<<endl;
	}return 0;
}