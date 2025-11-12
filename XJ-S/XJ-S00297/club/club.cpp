#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n;
struct node{
	int a1,a2,a3;
}a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int ans=0,maxn=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		for(int j=1;j<=n;j++){
			int c[5];
			int lst=ans,f=0;
			for(int i=1;i<=n;i++){
				if(c[1]>=n/2&&c[2]>=n/2&&c[3]>=n/2)break;
				else if(c[1]>=n/2){
					ans+=max(a[i].a2,a[i].a3);
					if(ans-a[i].a2==lst)f=2;
					if(ans-a[i].a3==lst)f=3;
					c[f]++;
				}
				else if(c[2]>=n/2){
					ans+=max(a[i].a1,a[i].a3);
					if(ans-a[i].a1==lst)f=1;
					if(ans-a[i].a3==lst)f=3;
					c[f]++;
				}
				else if(c[3]>=n/2){
					ans+=max(a[i].a1,a[i].a2);
					if(ans-a[i].a1==lst)f=1;
					if(ans-a[i].a2==lst)f=2;
					c[f]++;
				}
				else {
					ans+=max(a[i].a1,max(a[i].a2,a[i].a3));
					if(ans-a[i].a1==lst)f=1;
					if(ans-a[i].a2==lst)f=2;
					if(ans-a[i].a3==lst)f=3;
					c[f]++;
				}
			}
			maxn=max(maxn,ans);
			ans=0,f=0,lst=0;
			memset(c,0,sizeof(c));
		}
		
		/*
		int c1,c2,c3;
		for(int i=1;i<=n;i++){
			ans+=a[i].a1;
			c1++;
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				ans+=a[j].a2;
				c2++;
				for(int k=1;k<=n;k++){
					if(k==i||k==j)continue;
					ans+=a[k].a3;
					c3++;
					maxn=max(maxn,ans);
					ans-=a[k].a3;
				}
				ans-=a[j].a2;
			}
			ans-=a[i].a1;
		}
		cout<<maxn;
		*/
		cout<<maxn<<'\n';
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
