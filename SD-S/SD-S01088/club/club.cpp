#include <bits/stdc++.h>
using namespace std;
int a[100100][4],flag[5];
struct node{
	int pl,num,ser;
}b[100100];
bool cmp(node x,node y){
	return x.ser>y.ser;
}
bool cmp2(int x,int y){
	return a[x]>a[y];
}
void init(){
	int n,ans=0;
	cin>>n;
	int n2=n/2;
	for(int i=1;i<=n;i++){
		int maxx=-1,fl;
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			if(a[i][j]>maxx){
				maxx=a[i][j];
				fl=j;
			}
		}
		sort(a[i]+1,a[i]+4,cmp2);
		flag[fl]++;
		b[i].pl=i;
		b[i].num=maxx;
		b[i].ser=a[i][1]-a[i][2];
	}
	sort(b+1,b+1+n,cmp);
	for(int j=1;j<=3;j++){
		if(flag[j]>n2){
			for(int i=n2+1;i<=flag[j];i++){
				ans-=b[i].ser;
			}
			break ;
		}
	}
	for(int i=1;i<=n;i++){
		ans+=b[i].num;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t>0){
		t--;
		memset(a,0,sizeof(a));
		memset(flag,0,sizeof(flag));
		memset(b,0,sizeof(b));
		init();
	}
	return 0;
}
