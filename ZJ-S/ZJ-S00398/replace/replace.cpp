#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,qi[3000][3000],anss[N],l=0;
string a[N],b[N];
void f(string x,string y){
	int ans=0,st=9999999,en=0;
	for(int i=0;i<x.size();i++){
		if(x[i]!=y[i]) st=min(st,i),en=max(en,i);
	}
	for(int i=1;i<=n;i++){
		if(a[i].size()<=en-st) continue;
		int u=0;
		for(int j=0;j<x.size();j++){
			while(x[j]!=a[i][u]&&u>=0) u=qi[i][u];
			//cout<<u<<endl;
			if(u>=a[i].size()-1){
				bool uu=0;
				
				if(j<en||j-a[i].size()+1>st) uu=1;
				//else cout<<"eee"<<' '<<i<<endl;
				for(int q=j-a[i].size()+1;q<=j;q++){
					if(b[i][q-j+a[i].size()-1]!=y[q]||a[i][q-j+a[i].size()-1]!=x[q]){
						uu=1;
					}
				}
				if(uu==0) ans++;
				u=0;
			}
			u++;
		}
	}
	anss[++l]=ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		qi[i][0]=-1;
		for(int j=1;j<a[i].size();j++){
			int u=qi[i][j-1];
			while(a[i][j]!=a[i][u+1]&&u>=0) u=qi[i][u];
			qi[i][j]=u+1;
			if(a[i][j]!=a[i][u+1]) qi[i][j]--;
		}
	}	
	while(q--){
		string x,y;
		cin>>x>>y;
		f(x,y);
	}
	for(int i=1;i<=l;i++) printf("%d\n",anss[i]);
	return 0;
}
//s-00398
