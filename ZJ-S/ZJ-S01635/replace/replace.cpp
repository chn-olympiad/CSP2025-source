#include<bits/stdc++.h>
using namespace std;
int n,T,i,j,la,lb,s,t,w,m[1000001],f[1000001];
char c1[1001][1001],c2[1001][1001],a[1000001],b[1000001],x[1000001];
bool replace(int t,int w){
	bool flag;
	for(int i=1;i<=la;i++) x[i]=a[i];
	for(int i=1;i<=n;i++){
		if(m[i]==t){
			flag=1;
			for(int j=1;j<=t;j++)
				if(x[j]!=c1[i][j])flag=0;
			if(flag&&!f[i]){
				f[i]=1;
				for(int j=1;j<=t;j++)
					x[j]=c2[i][j];
			}
		}
		if(m[i]==w-t){
			flag=1;
			for(int j=t+1;j<=w;j++)
				if(x[j]!=c1[i][j-t])flag=0;
			if(flag&&!f[i]){
				f[i]=1;
				for(int j=t+1;j<=w;j++)
					x[j]=c2[i][j-t];
			}
		}
		if(m[i]==la-w){
			flag=1;
			for(int j=w+1;j<=la;j++)
				if(x[j]!=c1[i][j-w])flag=0;
			if(flag&&!f[i]){
				f[i]=1;
				for(int j=w+1;j<=la;j++)
					x[j]=c2[i][j-w];
			}
		}
		flag=1;
		for(int j=1;j<=la;j++)
			if(x[j]!=b[j])flag=0;
		if(flag)return 1;
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>T;
	for(i=1;i<=n;i++){
		cin>>c1[i]+1>>c2[i]+1;
		m[i]=strlen(c1[i]+1);
	}
	while(T--){
		cin>>a+1>>b+1;la=strlen(a+1);lb=strlen(b+1);
		if(la!=lb)cout<<0<<endl;
		else{
			s=0;
			for(t=0;t<la;t++)
				for(w=la;w>t;w--){
					for(i=1;i<=n;i++)f[i]=0;
					if(replace(t,w))s++;
				}
			cout<<s<<endl;
		}
	}
	return 0;
}
