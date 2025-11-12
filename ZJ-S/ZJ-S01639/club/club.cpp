#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005][3],v,fn,sn,tn,f[100005],s[100005],t[100005];
map<int,int> mp;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while( isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
struct zdy{
	int x,f,s,id;
	bool operator<(const zdy &B)const{return x<B.x;}
}fts[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		fn=0,sn=0,tn=0,v=0;
		for(int i=1;i<=n;i++){
			a[i][0]=read(),a[i][1]=read(),a[i][2]=read();
			int x=max(a[i][0],max(a[i][1],a[i][2])),xx;
			for(int j=0;j<3;j++)
				if(x==a[i][j]){
					xx=j;
					break;
				}
			int y=-10000,yy;
			for(int j=0;j<3;j++){
				if(j!=xx)
					if(a[i][j]>y) yy=j,y=a[i][j];
			}
			int z,zz;
			for(int j=0;j<3;j++)
				if(j!=xx&&j!=yy) z=a[i][j],zz=j;
			if(xx==0) f[++fn]=i,v+=a[i][0];
			if(xx==1) s[++sn]=i,v+=a[i][1];
			if(xx==2) t[++tn]=i,v+=a[i][2];
			fts[i]=(zdy){x-y,xx,yy,i};
		}
//		printf("%d\n",v);
		sort(fts+1,fts+1+n);
		for(int i=1;i<=n;i++) mp[fts[i].id]=i;
//		for(int i=1;i<=n;i++) printf("\\\\\%d\n",mp[i]);
		if(fn>n/2){
			vector<int> vv;
			for(int i=1;i<=fn;i++)
				vv.push_back(mp[f[i]]);
			sort(vv.begin(),vv.end());
			for(int i=0,j=1;i<vv.size();i++,j++){
				if(j>fn-n/2) break;
				zdy x=fts[vv[i]];
				v-=x.x;
			}
		}
		if(sn>n/2){
//			printf("!!2\n");
			vector<int> vv;
			for(int i=1;i<=sn;i++)
				vv.push_back(mp[s[i]]);
			sort(vv.begin(),vv.end());
//			for(int i=0;i<vv.size();i++) printf("\\%d\n %d\n",vv[i],s[i]);
			for(int i=0,j=1;i<vv.size();i++,j++){
				if(j>sn-n/2) break;
				zdy x=fts[vv[i]];
//				printf("!!!%d\n",vv[i],x.x);
				v-=x.x;
			}
		}
		if(tn>n/2){
			vector<int> vv;
			for(int i=1;i<=tn;i++)
				vv.push_back(mp[t[i]]);
			sort(vv.begin(),vv.end());
			for(int i=0,j=1;i<vv.size();i++,j++){
				if(j>tn-n/2) break;
				zdy x=fts[vv[i]];
				v-=x.x;
			}
		}
		printf("%d\n",v);
	}
	return 0;
}
//15:46
