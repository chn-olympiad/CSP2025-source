# include<bits/stdc++.h>
using namespace std;
int t,n,cnt1,cnt2,cnt3;
struct bm{
	int myd,member;
}d1[100100],d2[100100],d3[100100];
struct idea{
	int myd,num;
}a[100100][5];
bool cmp(idea x,idea y){
	if(x.myd>y.myd) return true;
	else return false;
}
void myd(){
	int sum=0;
	for(int i=1;i<=cnt1;i++){
		sum+=d1[i].myd;
	}
	for(int i=1;i<=cnt2;i++){
		sum+=d2[i].myd;
	}
	for(int i=1;i<=cnt3;i++){
		sum+=d3[i].myd;
	}
	cout<<sum<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j].myd;
				a[i][j].num=j;
			}
		}
		cnt1=0;
		cnt2=0;
		cnt3=0;
		for(int i=1;i<=n;i++){
			sort(a[i]+1,a[i]+4,cmp);
			if(a[i][1].num==1){
				cnt1++;
				d1[cnt1].member=i;
				d1[cnt1].myd=a[i][1].myd;
			}else if(a[i][1].num==2){
				cnt2++;
				d2[cnt2].member=i;
				d2[cnt2].myd=a[i][1].myd;
			}else{
				cnt3++;
				d3[cnt3].member=i;
				d3[cnt3].myd=a[i][1].myd;
			}
		}
		myd();
	}	
	return 0;
}
