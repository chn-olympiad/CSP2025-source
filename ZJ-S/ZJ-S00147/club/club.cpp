#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N];
struct rec{
	int x,y,z;
}s[N];
int sortt(rec l,rec r){
	return l.z>r.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(s,0,sizeof(s));
		int n,sum=0,ret=0;
		int xx=0,yy=0,zz=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			int f[5]={0,a[i],b[i],c[i]};
			sort(f+1,f+4);
			if(f[3]==a[i])xx++;
			if(f[3]==b[i])yy++;
			if(f[3]==c[i])zz++;
		}
		for(int i=1;i<=n;i++){
			int f[5]={0,a[i],b[i],c[i]};
			sort(f+1,f+4);
			if(xx>n/2&&f[3]==a[i]){
				s[++ret].x=f[3];
				s[ret].y=f[2];
				s[ret].z=f[3]-f[2];
			}
			else if(yy>n/2&&f[3]==b[i]){
				s[++ret].x=f[3];
				s[ret].y=f[2];
				s[ret].z=f[3]-f[2];
			}
			else if(zz>n/2&&f[3]==c[i]){
				s[++ret].x=f[3];
				s[ret].y=f[2];
				s[ret].z=f[3]-f[2];
			}
			else{
				sum+=f[3];
			}
		}
		sort(s+1,s+1+ret,sortt);
		for(int i=1;i<=n/2;i++){
			sum+=s[i].x;
		}
		for(int i=n/2+1;i<=ret;i++){
			sum+=s[i].y;
		}
		cout<<sum<<"\n";
	}
	return 0;
}
