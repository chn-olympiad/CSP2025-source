//王岚清 SN-S00487 西安高新第一中学
#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[505];
int di[505];
int np[505];
int cntrf,cntac;
int ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		if(x=='0'){
			di[i]=0;
		}else{
			di[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		np[i]=i;
	}
	do{
		for(int i=1;i<=n;i++){
			if(di[i]==0){
				cntrf++;
				continue;
			}
			if(cntrf<c[np[i]]){
				cntac++;
			}else{
				cntrf++;
				continue;
			}
		}
		if(cntac>=m){
			ans++;
		}
		cntrf=0;
		cntac=0;
	}while(next_permutation(np+1,np+1+n));
	cout<<ans;
	return 0;
}
