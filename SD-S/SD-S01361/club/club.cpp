#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>


using namespace std;

const int N=1e5+5,INF=0x3f3f3f3f;

int t;
int a1[N],a2[N],a3[N];
long long  int ans;
int maxn[N];//每个人在3个组里的max 
int idx[N];//最大值所处的组数


int find(int cmp,int x,int nn){
//求>k的组，在这》k的组里求除maxn[i]以外的max，与mxn做差，找差的min
 int cha[N];
 int idxx=0;
 
for(int i=1;i<=nn;i++){
//	int chacha=0;
	if(idx[i]==x){
//		if(1!=idx[i])chacha=max(chacha,a1[i]);
//		
//		if(2!=idx[i])chacha=max(chacha,a2[i]);
//			
//		if(3!=idx[i])chacha=max(chacha,a3[i]);
//		cha[idxx]=chacha;
			if(1!=idx[i]){
		    if(cha[idxx]>0)cha[idxx]=min(cha[idxx],maxn[i]-a1[i]);
		    else
			cha[idxx]=min(INF,maxn[i]-a1[i]);
				}
			if(2!=idx[i]){	
			if(cha[idxx]>0)cha[idxx]=min(cha[idxx],maxn[i]-a2[i]);
		    else
			cha[idxx]=min(INF,maxn[i]-a2[i]);
			}
			if(3!=idx[i]){
			if(cha[idxx]>0)cha[idxx]=min(cha[idxx],maxn[i]-a3[i]);
		    else
			cha[idxx]=min(INF,maxn[i]-a3[i]);	}
	}
	idxx++;
}

    sort(cha,cha+idxx);
    int res=0;
for(int i=0;i<cmp;i++){
	res+=cha[i];
}
return res;
}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
    	memset(idx,0,sizeof idx);
    		memset(maxn,0,sizeof maxn);
		int m1=0,m2=0,m3=0; 
    	memset(a1,0,sizeof a1);
    		memset(a2,0,sizeof a2);
    			memset(a3,0,sizeof a3);
    	 ans=0;
    	int n;
    	
    	cin>>n;
		int k=n/2;//每个组里最多n/2个人
    	int g=0;//组里人数最多是多少 
    	
    	for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			maxn[i]=max(a1[i],a2[i]);
			maxn[i]=max(maxn[i],a3[i]);
			ans+=maxn[i];//理想状态下的ans 
			if(maxn[i]==a1[i]){
				idx[i]=1;
				m1++;}
			else if(maxn[i]==a2[i]){
				idx[i]=2;
				m2++;}
			else{
				idx[i]=3;
			    m3++;}
		}
		
	if(m1<=k&&m2<=k&&m3<=k){
	cout<<ans<<'\n';
	continue;}
	
	else{
		int mm=0;
		int max123=max(m3,max(m1,m2));
		int m=max123-k;//
		if(max123==m1) mm=1;
		else if(max123==m2)mm=2;
		else mm=3;//mm为》k的那组 
		ans-=find(m,mm,n);
		cout<<ans<<'\n';
}

}
	return 0;
	//-std=c++14 -O2
}

