#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
}r[100000];
int in[500001];
int xorr(long long a,long long b){
	int l;
	long long s=0;
	bool u[20]={},v[20]={},o[20]={};
	for(int i=19;i>=0;i--){
		if(a>=pow(2,i)){
			u[i]=1;
			a-=pow(2,i);
		}
		if(a==0) break;
	}
	for(int i=19;i>=0;i--){
		if(b>=pow(2,i)){
			v[i]=1;
			b-=pow(2,i);
		}
		if(b==0) break;
	}
	for(int i=0;i<=19;i++){
		if(u[i]==0){
			if(v[i]==0) o[i]=0;
			else o[i]=1;
		}
		if(u[i]==1){
			if(v[i]==0) o[i]=1;
			else o[i]=0;
		}
	}
	for(int i=0;i<=19;i++) if(o[i]==1) s+=pow(2,i);
	return s;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long k;
	int n,t=0,g;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>in[i];
	for(int i=1;i<=n;i++)
	for(int j=i;j<=n;j++){
		if(i==j&&in[i]==k){
			t++;
			r[t].x=i;
			r[t].y=j;
			break;
			break;
		}
		g=in[i];
		for(int l=i+1;l<=j;l++){
			g=xorr(g,in[l]);
		}
		if(g==k&&i!=j){
			t++;
			r[t].x=i;
			r[t].y=j;
			break;
			break;
		}
	}
	cout<<t<<endl;
	for(int i=1;i<=t;i++){
		cout<<r[i].x<<" "<<r[i].y<<endl;
	}
	return 0;
}
