#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int v[1000005],u[1000005],w[1000005],c1[10000005],ci[1000005][1000005];
int cy[1000005];
int a,b,c,d,e,f,g;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
cin>>n>>m>>k;
for(int i=1;i<=m;i++){
	cin>>u[i]>>v[i]>>w[i];
	if(a==0){
		a=w[i];
		b=i;
	}else if(a>w[i]){
		a=w[i];
		b=i;
		
		
	}else{
		cout<<"";
	}
}
for(int i=1;i<=n;i++){
	cin>>c1[i];
	for(int j=1;j<=w;j++){
		cin>>ci[i][j];
		if(a==0){
		a=ci[i][j];
		c=i;
		d=j;
	}else if(a>=ci[i][j]+c1[i]){
		a=ci[i][j];
		c=i;
		d=j;
		f=1;
		
	}else{
		cout<<"";
	}
	}
}

while(g++){
	if(g==n){
		break;
	}else{
		for(int i=1;i<=m;i++){
	
	if(a==0){
		a=w[i];
		b=i;
	}else if(a>w[i]){
		a=w[i];
		b=i;
		
		
	}else{
		cout<<"";
	}
}
for(int i=1;i<=n;i++){
	
	for(int j=1;j<=w;j++){
	
		if(a==0){
		a=ci[i][j];
		c=i;
		d=j;
	}else if(a>=ci[i][j]+c1[i]){
		a=ci[i][j];
		c=i;
		d=j;
		f=1;
		
	}else{
		cout<<"";
	}
	}
}
if(f==1){
	ci[c][d]=99999;
}else{
	g++;
	w[b]=99999;
}
		
	}
	
}
cout<<ans;

	fclose(stdin);
	fclose(stdout);
	return 0;
}