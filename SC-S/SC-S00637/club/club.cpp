#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int ret=0,op=1;char in=getchar();
	while(!isdigit(in)){if(in=='-'){op=-1;}in=getchar();}
	while(isdigit(in)){ret=(ret<<3)+(ret<<1)+(in^48);in=getchar();}
	return ret*op;
}
int timc,lent,val[100010][10];
int opt[100010];
int dp[100010][3];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	timc=read();
	for(int t=1;t<=timc;t+=1){
		lent=read();
		int mx=0,p=0,q=0,r=0;
	    for(int i=1;i<=lent;i+=1){
			val[i][0]=read();
			val[i][1]=read();
			val[i][2]=read();
			if(val[i][0]>val[i][1]){
				if(val[i][0]>val[i][2]){
					p+=1;mx+=val[i][0];
					opt[i]=0;
				}else {
					r+=1;mx+=val[i][2];
					opt[i]=2;
				}
			}else{
				if(val[i][1]<val[i][2]){
					r+=1;mx+=val[i][2];
					opt[i]=2;
				}else {
					q+=1;mx+=val[i][1];
					opt[i]=1;
				}
			}
		}
		int ov=3,ot=0;
		if(p>lent/2)ov=0,ot=p-lent/2;
		if(q>lent/2)ov=1,ot=q-lent/2;
		if(r>lent/2)ov=2,ot=r-lent/2;
		if(ov!=3){
			map<int,int> mp;
			for(int i=1;i<=lent;i+=1){
				if(opt[i]==ov){
					int tmp=0;
					if(ov!=0)tmp=max(tmp,val[i][0]);
					if(ov!=1)tmp=max(tmp,val[i][1]);
					if(ov!=2)tmp=max(tmp,val[i][2]);
					mp[val[i][ov]-tmp]+=1;
				}
			}
			for(auto i=mp.begin();i!=mp.end();i++){
				if(ot<=0)break;
				if((*i).second>=ot){
					mx-=ot*(*i).first;
					break;
				}else {
					ot-=(*i).second;
					mx-=(*i).second*(*i).first;
				}
			}
		}
		printf("%lld\n",mx);
	}
	return 0;
}