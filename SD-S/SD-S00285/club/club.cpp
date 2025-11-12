#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' or ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0' and ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int t,n,a1,a2,a3,zdx[4],zdd,da;
struct jgt{
	int zd,cd,c,ii;
}x[100009];
bool cmp2(jgt u,jgt v){
	return zdx[u.ii]==zdx[v.ii]?u.c>v.c:zdx[u.ii]>zdx[v.ii];
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		da=zdx[1]=zdx[2]=zdx[3]=0;
		for(int i=1;i<=n;i++){
			a1=read();a2=read();a3=read();
			if(a1>=a2 and a1>=a3){
				x[i].zd=a1;zdx[1]++;x[i].ii=1;
				x[i].cd=max(a2,a3);
			}
			else if(a2>=a1 and a2>=a3){
				x[i].zd=a2;zdx[2]++;x[i].ii=2;
				x[i].cd=max(a1,a3);
			}
			else{
				x[i].zd=a3;zdx[3]++;x[i].ii=3;
				x[i].cd=max(a1,a2);
			}
			x[i].c=x[i].zd-x[i].cd;
			da+=x[i].zd;
		}
		zdd=max(zdx[1],max(zdx[2],zdx[3]));
		if(zdd>n/2){
			sort(x+1,x+n+1,cmp2);
			for(int i=n/2+1;i<=zdd;i++)da-=(x[i].c);
		}
		cout<<da<<"\n";
	}
	return 0;
}

