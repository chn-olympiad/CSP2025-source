#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct stu{
	int m,b;//满意度,编号 
}a[N][3];
struct mx{
	int c,num;
}maxn[N];
int x[3];
bool cmp(stu x, stu y){
	return x.m>y.m;
} 
bool cmp2(mx x, mx y){
	return x.c>y.c;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			maxn[i].c=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j].m;
				maxn[i].num=i;
				a[i][j].b=j;
			}
			sort(a[i]+1,a[i]+1+n,cmp);
			maxn[i].c=a[i][1].m-a[i][2].m+a[i][2].m-a[i][3].m+a[i][1].m-a[i][3].m;
		} 
		sort(maxn+1,maxn+1+n,cmp2);
		for(int i=1;i<=n;i++){
			int k=maxn[i].num;
			for(int j=1;j<=3;j++){
				if(x[a[k][j].b]<n/2){
					ans+=a[k][j].m;
					x[a[k][j].b]++;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}