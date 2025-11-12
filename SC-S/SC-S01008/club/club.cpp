#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
inline int read();
int a[100005][5];
std::vector<int> b;
std::vector<int> c[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		int n=read();
		b.clear();
		c[0].clear();
		c[1].clear();
		c[2].clear();
		int ans=0;
		for(int i=1;i<=n;i++){
			a[i][1]=read();
			a[i][2]=read();
			a[i][3]=read();
			if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
				a[i][0]=3;
				c[2].push_back(i);
				a[i][4]=std::max(a[i][1],a[i][2]);
				ans+=a[i][3];
			}else if(a[i][1]>=a[i][3]&&a[i][1]>=a[i][2]){
				a[i][0]=1;
				c[0].push_back(i);
				ans+=a[i][1];
				a[i][4]=std::max(a[i][3],a[i][2]);
			}else{
				a[i][0]=2;
				c[1].push_back(i);
				ans+=a[i][2];
				a[i][4]=std::max(a[i][1],a[i][3]);
			}
		}
		int mx=ans;
		int cntt[3]={0,0,0};
		for(int i=1;i<=n;i++){
			cntt[a[i][0]-1]++;
		}
		int cho=0;
		int mxx=std::max(cntt[0],std::max(cntt[1],cntt[2]));
		if(mxx==cntt[0]){
			cho=1;
		}else if(mxx==cntt[1]){
			cho=2;
		}else{
			cho=3;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i][0]==cho){
				cnt++;
				b.push_back(a[i][cho]-a[i][4]);
			}
		}
		std::sort(b.begin(),b.end());
		for(int i=1;i<=cnt-n/2;i++){
			mx-=b[i-1];
		}
		printf("%d\n",mx);
	}
	return 0;
}
inline int read(){
	int f=1,x=0;
	char temp=getchar();
	while(temp>'9'||temp<'0'){
		(temp=='-')?(f=-1):0;
		temp=getchar();
	}
	while('0'<=temp&&temp<='9'){
		x=(x<<3)+(x<<1)+(temp^'0');
		temp=getchar();
	}
	return f*x;
}