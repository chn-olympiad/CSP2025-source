#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

inline int Rd(){
	int x=0,f=1; char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^'0');
		c=getchar();
	}
	return x*f;
}

int T,n,cnt[4],ans;
struct node{
	int num[4],max1,max2;
	friend bool operator < (node A,node B){
		return A.num[A.max1]-A.num[A.max2] > B.num[B.max1]-B.num[B.max2];
	}
}a[100005];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=Rd();
	while (T--){
		cnt[1]=cnt[2]=cnt[3]=0; ans=0;
		n=Rd();
		for (int i=1;i<=n;i++){
			a[i].num[1]=Rd();
			a[i].num[2]=Rd();
			a[i].num[3]=Rd();
			int maxx=0,k1=0;
			for (int j=1;j<=3;j++){
				if (maxx<a[i].num[j]){
					maxx=a[i].num[j];
					k1=j;
				}
			}
			int minn=2100000000,k2=0;
			for (int j=1;j<=3;j++){
				if (minn>a[i].num[j]){
					minn=a[i].num[j];
					k2=j;
				}
			}
			a[i].max1=k1;
			a[i].max2=6-k1-k2;
		}
		sort(a+1,a+n+1);
//		for (int i=1;i<=n;i++){
//			cerr<<a[i].num[1]<<" "<<a[i].num[2]<<" "<<a[i].num[3]<<endl;
//		}
		for (int i=1;i<=n;i++){
			if (cnt[a[i].max1]>=(n>>1)){
				cnt[a[i].max2]++;
				ans=ans+a[i].num[a[i].max2];
			}
			else{
				cnt[a[i].max1]++;
				ans=ans+a[i].num[a[i].max1];
			}
		}
		printf("%d\n",ans);
	} 
	
	return 0;
}
