#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
int a[maxn],b[maxn],c[maxn],ans[maxn];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;
		cin>>m;
		for(int j=1;j<=m;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		int l1=0,l2=0,s1=0,s2=0;
		sort(a+1,a+m+1,cmp);
		sort(b+1,b+m+1,cmp);
		for(int j=1;j<=m;j++){
			if(a[j]>b[j]&&s1<m/2){
				s1++;
				l1+=a[j];
			}
			else if(s1==m/2){
				s1++;
				l1+=a[j];
			}
			if(b[j]>=a[j]&&s2<m/2){
				s2++;
				l2+=b[j];
			}
			else if(s2==m/2){
				s2++;
				l2+=b[j];
			}
		}
		ans[i]=l1+l2;
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
