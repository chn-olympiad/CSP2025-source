#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
const int N=510;
int n,m;
int s[N],c[N],id[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%1d",&s[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]),id[i]=i;
	sort(c+1,c+n+1);
	int ans=0;
	do{
		//give up
		int gvu=0;
		for(int i=1;i<=n;i++){
			if(gvu>=c[id[i]]){
				//c_i·ÅÆú 
				gvu++;
			}else{
				if(s[i]==0) gvu++;
			} 
		}
		if(n-gvu>=m){
			ans++;
//		for(int i=1;i<=n;i++){
//			cout<<id[i]<<" "<<c[id[i]]<<"---";
//		}
//		cout<<endl;
		}
	}while(next_permutation(id+1,id+n+1));
	cout<<ans;
	return 0;
}

