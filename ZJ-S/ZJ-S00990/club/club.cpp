#include<bits/stdc++.h>
using namespace std;

struct ark{
	long long df,rr,ieo,qzk,kr;
} aapa[100005];

bool cmp(ark a,ark b){
	return a.df>b.df;
}

long long T,n,cnt=0,fi[3]={},pd=0,pd2=0;

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>T;
	while(T--){
		cnt=0;
		cin>>n;	
		for(int i=0;i<n;i++){
			cin>>aapa[i].ieo>>aapa[i].qzk>>aapa[i].kr;
			aapa[i].rr=i;
			aapa[i].df=max(abs(aapa[i].ieo-aapa[i].qzk),max(abs(aapa[i].qzk-aapa[i].kr),abs(aapa[i].ieo-aapa[i].kr)));
		}
		sort(aapa,aapa+n,cmp);
		
		int l=n/2;
		fi[0]=l;
		fi[1]=l;
		fi[2]=l;
		
		for(int i=0;i<n;i++){
			int maxx=max(aapa[i].ieo,max(aapa[i].qzk,aapa[i].kr));
			if(maxx==aapa[i].ieo) pd=1;
			else if(maxx==aapa[i].qzk) pd=2;
			else pd=3;
			if(pd==1){
				if(aapa[i].qzk>=aapa[i].kr) pd2=2;
				else pd2=3;
			}
			if(pd==2){
				if(aapa[i].ieo>=aapa[i].kr) pd2=1;
				else pd2=3;
			}
			if(pd==3){
				if(aapa[i].qzk>=aapa[i].ieo) pd2=2;
				else pd2=1;
			}
			if(fi[pd-1]){
				fi[pd-1]--;
				if(pd==1) cnt+=aapa[i].ieo;
				if(pd==2) cnt+=aapa[i].qzk;
				if(pd==3) cnt+=aapa[i].kr;
			}else if(fi[pd2-1]){
				fi[pd2-1]--;
				if(pd2==1) cnt+=aapa[i].ieo;
				if(pd2==2) cnt+=aapa[i].qzk;
				if(pd2==3) cnt+=aapa[i].kr;
			}else{
				if(pd==1 && pd2==2 || pd==2 && pd2==1){
					fi[2]--;
					cnt+=aapa[i].kr;
				}else if(pd==2 && pd2==3 || pd==3 && pd2==2){
					fi[0]--;
					cnt+=aapa[i].ieo;
				}else if(pd==1 && pd2==3 || pd==3 && pd2==1){
					fi[1]--;
					cnt+=aapa[i].qzk;
				}
			}
		}
		cout<<cnt<<endl;
	}
	
	return 0;
}
