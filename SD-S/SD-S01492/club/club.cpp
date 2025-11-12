#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int a[100005][3],kui[100005],maxid[100005];
priority_queue<int> hp1,hp2,hp0;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		int n=read();
		for(int i=1;i<=n;i++){
			a[i][0]=read();
			a[i][1]=read();
			a[i][2]=read();
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				maxid[i]=0;
				kui[i]=max(a[i][1],a[i][2])-a[i][0];
			}
			if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				maxid[i]=1;
				kui[i]=max(a[i][0],a[i][2])-a[i][1];
			}
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][0]){
				maxid[i]=2;
				kui[i]=max(a[i][1],a[i][0])-a[i][2];
			}
		}
		int ans=0,cn1=0,cn2=0,cn0=0,max_n=n/2;
		for(int i=1;i<=n;i++){
			ans+=a[i][maxid[i]];
			if(maxid[i]==0){
				cn0++;
				hp0.push(kui[i]);
				if(cn0>max_n){
					ans+=hp0.top();
					hp0.pop();
					cn0--;
				}
			} 
			if(maxid[i]==1){
				cn1++;
				hp1.push(kui[i]);
				if(cn1>max_n){
					ans+=hp1.top();
					hp1.pop();
					cn1--;
				}
			} 
			if(maxid[i]==2){
				cn2++;
				hp2.push(kui[i]);
				if(cn2>max_n){
					ans+=hp2.top();
					hp2.pop();
					cn2--;
				}
			} 
		}
		cout<<ans<<'\n';
		while(!hp0.empty()) hp0.pop();
		while(!hp1.empty()) hp1.pop();
		while(!hp2.empty()) hp2.pop();
	} 
	return 0;
}
