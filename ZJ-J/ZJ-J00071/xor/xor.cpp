#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],k,idq=0,gc,cnt=0,las=0;

struct qj{
	long long begin,end;
}lq[10000005];

bool cmp(qj x,qj y){
	if(x.end!=y.end) return x.end<y.end;
	else return x.begin<y.begin;
}
long long fxo(long long na,long long nb){
	int tca[30],tcb[30],tcc[40];
	memset(tca,0,sizeof tca);
	memset(tcb,0,sizeof tcb);
	int ida=0,idb=0,cs=0;
	long long ans=0;
	while(na!=0){
		tca[ida++]=na%2;
		na/=2;
	}
	while(nb!=0){
		tcb[idb++]=nb%2;
		nb/=2;
	}
	cs=max(ida,idb);
	for(int i=0;i<cs;i++){
		if(tca[i]==0||tcb[i]==0) tcc[i]=1;
		else tcc[i]=0;
		ans+=(pow(2,i)*tcc[i]);
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		gc=a[i];
		if(gc==k){
			lq[++idq].begin=i;
			lq[idq].end=i;
			continue;		
		}
		for(int j=i+1;j<=n;j++){			
			gc=fxo(gc,a[j]);			
			if(gc==k){
				lq[++idq].begin=i;
				lq[idq].end=j;
				break;
			}
		}
	}
	
	sort(lq+1,lq+idq+1,cmp);
	
//	for(int i=1;i<=idq;i++){
//		cout<<lq[i].begin<<" "<<lq[i].end<<endl;
//	}
	cnt++;
	las=1;
	for(int i=2;i<=idq;i++){
		if(lq[i].begin>lq[las].end){
			cnt++;
			las=i;
		}
	}
	cout<<cnt;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
