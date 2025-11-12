//唐一齐 SN-S00129 西安市交大附中浐灞右岸学校
#include <bits/stdc++.h>
using namespace std;
int t,n;
pair<int,int> happy[4];//first 代表人数，second 代表开心度 
struct s{
	int q1,q2,q3;
}a[100100];
void special1();
void special2();
bool cmp1(s x,s y);
bool cmp2(s x,s y);
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		bool x = true,y = true;
		for(int i = 1;i<=n;i++){
			scanf("%d%d%d",&a[i].q1,&a[i].q2,&a[i].q3);
			if(a[i].q2 != 0 || a[i].q3 != 0){
				x = false;
				y = false;
			}
			if(a[i].q3 != 0)y = false;
		}
		memset(happy,0,sizeof(happy));
		if(x)special1();
		else special2();
	}
	return 0;
}
void special1(){
	sort(a+1,a+1+n,cmp1);
	int ans = 0;
	for(int i = 1;i<=n/2;i++)ans+=a[i].q1;
	cout<<ans<<'\n';
}
void special2(){
	sort(a+1,a+n+1,cmp2);
	int ans = 0;
	for(int i = 1;i<=n;i++){
		if(max(a[i].q1,a[i].q2) == q1)
			if(happy[1].first+1<=n/2){
				happy[1].first++;
				happy[1].second+=a[i].q1;
			}
			else {
				happy[2].second+=a[i].q2;
				happy[2].first++;
			}
		else
			if(happy[2].first+1<=n/2){
				happy[2].first++;
				happy[2].second+=a[i].q2;
			}
			else {
				happy[1].second+=a[i].q1;
				happy[1].first++;
			}
	}
	cout<<happy[1].second+happy[2].second;
}
bool cmp1(s x,s y){
	return x.q1>y.q1;
}
bool cmp1(s x,s y){
	return max(x.q2,x.q1)>max(y.q1,y.q2);
}
