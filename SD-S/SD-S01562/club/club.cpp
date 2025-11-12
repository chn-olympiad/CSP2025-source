#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int s[100005][5];
int cnt1,cnt2,cnt3;
struct node{
	int id,v;
};
node a[100005],b[100005],c[100005];
bool cmp(node x,node y){
	return x.v<y.v;
}
int sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		cnt1=cnt2=cnt3=0;
		sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&s[i][1],&s[i][2],&s[i][3]);
			if(s[i][1]>=s[i][2]&&s[i][1]>=s[i][3]){
				a[++cnt1].id=i;
				sum+=s[i][1];
				a[cnt1].v=min(s[i][1]-s[i][2],s[i][1]-s[i][3]);
			}
			else if(s[i][2]>=s[i][3]&&s[i][2]>=s[i][1]){
				b[++cnt2].id=i;
				sum+=s[i][2];
				b[cnt2].v=min(s[i][2]-s[i][1],s[i][2]-s[i][3]);
			}
			else if(s[i][3]>=s[i][1]&&s[i][3]>=s[i][2]){
				c[++cnt3].id=i;
				sum+=s[i][3];
				c[cnt3].v=min(s[i][3]-s[i][1],s[i][3]-s[i][2]);
			}
		}
//		cout<<cnt1<<cnt2<<cnt3;
		if(cnt1>n/2){
			sort(a+1,a+cnt1+1,cmp);
			for(int i=1;i<=cnt1-n/2;++i){
				sum-=a[i].v;
			}
		}if(cnt2>n/2){
			sort(b+1,b+cnt2+1,cmp);
			for(int i=1;i<=cnt2-n/2;++i){
				sum-=b[i].v;
//				cout<<"a"<<b[i].v<<endl;
			}
		}if(cnt3>n/2){
			sort(c+1,c+cnt3+1,cmp);
			for(int i=1;i<=cnt3-n/2;++i){
				sum-=c[i].v;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
} 
