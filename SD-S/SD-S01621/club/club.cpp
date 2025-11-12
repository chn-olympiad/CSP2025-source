#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
ll rd(){
	char c=getchar();
	ll rt=0;
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		rt=rt*10+c-'0';
		c=getchar();
	}
	return rt;
}
ll t,n;
int a[100005][4];
int bl(int dq,int q,int w,int e){
	cout<<dq<<" ";
	int rt=0;
	if(dq==n){
		if(q<n/2)rt=a[dq][1];
		if(w<n/2)rt=max(rt,a[dq][2]);
		if(e<n/2)rt=max(rt,a[dq][3]);
		return rt;
	}
	if(q<n/2)rt=a[dq][1]+bl(dq+1,q+1,w,e);
	if(w<n/2)rt=max(rt,a[dq][2]+bl(dq+1,q,w+1,e));
	if(e<n/2)rt=max(rt,a[dq][3]+bl(dq+1,q,w,e+1));
	return rt;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=rd();
	while(t--){
		int tb[100005]={},dp[100005];
		bool tsxza=1;
		n=rd();
		for(int i=0;i<=n;i++)a[i][1]=0,a[i][2]=0,a[i][3]=0;
		for(int i=1;i<=n;i++){
			a[i][1]=rd(),a[i][2]=rd(),a[i][3]=rd();
			if(a[i][2]||a[i][3])tsxza=0; 
			if(tsxza)tb[i]=a[i][1];
		}
		if(tsxza){
			ll ans=0;
			sort(tb+1,tb+1+n);
			for(int i=n;i>n/2;i--)ans+=tb[i];
			cout<<ans<<endl;
			continue;
		}
		cout<<bl(1,0,0,0)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


	天灵灵地灵灵，我的代码不爆零 



-------------------------------------------------------------------------
																		|
																		|
       _																|
      / ~																|
     /   ~																|
    / 	/     `\														|
	~  /`\     )\														|
	 ~-   `\  / |														|
	  _  ---`\ /														|
	|_|  ---- `\														|
	            `\														|
																		|
																		|
																		|
																		|
																		|
																		|
																		|
																		|
-------------------------------------------------------------------------

orz orz orz 让我拿二等奖吧，555 
*/
