#include <bits/stdc++.h>
using namespace std;
int t,n,a[111111][4],ak[111111][4],aas[4],ans,ab[111111][4],iid,noww[111111];
int mx(int a,int b,int c){
	if(max(max(a,b),c)==a) return 1;
	if(max(max(a,b),c)==b) return 2;
	if(max(max(a,b),c)==c) return 3;
}
int mn(int a,int b,int c){
	if(min(min(a,b),c)==a) return 1;
	if(min(min(a,b),c)==b) return 2;
	if(min(min(a,b),c)==c) return 3;	
}
int sss(int i,int j){
	if(i==j) return 0;
	return a[i][noww[j]]+a[j][ab[j][2]]-a[i][noww[i]]-a[j][noww[j]];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		iid=ans=aas[1]=aas[2]=aas[3]=0;
		for(int i=1;i<=n;i++){
			int ooo;
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			ab[i][1]=mx(a[i][1],a[i][2],a[i][3]);
			ab[i][3]=mn(a[i][1],a[i][2],a[i][3]);
			ab[i][2]=6-ab[i][3]-ab[i][1];
			if(aas[ab[i][1]]==n/2){
				ooo=ab[i][2];
				iid=ab[i][1];
			}else ooo=ab[i][1];
			noww[i]=ooo;
			ak[++aas[ooo]][ooo]=i;
			ans+=a[i][ooo];
		} 
		if(iid==0){
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(noww[i]==ab[i][1]) continue;
			int l=i;
			for(int k=1;k<=aas[iid];k++){
				int j=ak[k][iid];
				if(sss(i,l)<sss(i,j)){
					l=j;
				}
			}
			if(l!=i){
				ans+=sss(i,l);
				ak[noww[l]][iid]=i;
				ak[aas[noww[i]]--][noww[i]]=0;
				ak[++aas[ab[l][2]]][ab[l][2]]=l;
				noww[i]=noww[l];
				noww[l]=ab[l][2];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
