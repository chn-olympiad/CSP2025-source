#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int T,n,a[N],b[N],c[N],cha[N],chb[N],chc[N];
bool cmp1(int x,int y){
	return a[x]-max(b[x],c[x])>a[y]-max(b[y],c[y]);
}
bool cmp2(int x,int y){
	return b[x]-max(c[x],a[x])>b[y]-max(c[y],a[y]);
}
bool cmp3(int x,int y){
	return c[x]-max(a[x],b[x])>c[y]-max(a[y],b[y]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int ans=0,tot1=0,tot2=0,tot3=0,cnts1=0,cnts2=0,cnts3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=max(b[i],c[i])) cha[++tot1]=i,cnts1+=a[i];
			else if(b[i]>=max(c[i],a[i])) chb[++tot2]=i,cnts2+=b[i];
			else if(c[i]>=max(a[i],b[i])) chc[++tot3]=i,cnts3+=c[i];
		}
		//cout<<cnts1<<cnts2<<cnts3<<" ";
		if(tot1>n/2){
			ans+=cnts2+cnts3; 
			sort(cha+1,cha+tot1+1,cmp1);
			for(int i=1;i<=n/2;i++) ans+=a[cha[i]];
			for(int i=n/2+1;i<=tot1;i++) ans+=max(b[cha[i]],c[cha[i]]);
		}
		else if(tot2>n/2){
			ans+=cnts3+cnts1; 
			sort(chb+1,chb+tot2+1,cmp2);
			for(int i=1;i<=n/2;i++) ans+=b[chb[i]];
			for(int i=n/2+1;i<=tot2;i++) ans+=max(c[chb[i]],a[chb[i]]);
		}
		else if(tot3>n/2){
			ans+=cnts1+cnts2; 
			sort(chc+1,chc+tot3+1,cmp3);
			for(int i=1;i<=n/2;i++) ans+=c[chc[i]];
			for(int i=n/2+1;i<=tot3;i++) ans+=max(a[chc[i]],b[chc[i]]);
		}
		else ans=cnts1+cnts2+cnts3;
		cout<<ans<<"\n";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
