//邓友康 SN-S00693 西安高新第一中学 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Point{
	int a,b,c;
}p[N];
int n;
Point s1[N],s2[N],s3[N];
long long cnt1,cnt2,cnt3,ans;
bool cmp1(Point x,Point y){
	int cha1=x.a-max(x.b,x.c);
	int cha2=y.a-max(y.b,y.c);
	return cha1>cha2;
}
bool cmp2(Point x,Point y){
	int cha1=x.b-max(x.a,x.c);
	int cha2=y.b-max(y.a,y.c);
	return cha1>cha2;
}
bool cmp3(Point x,Point y){
	int cha1=x.c-max(x.a,x.b);
	int cha2=y.c-max(y.a,y.b);
	return cha1>cha2;
}
void solve(){
	cnt1=cnt2=cnt3=0;
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].a>>p[i].b>>p[i].c;
	for(int i=1;i<=n;i++){
		int maxn=max(p[i].a,p[i].b);
		maxn=max(maxn,p[i].c);
		if(p[i].a==maxn)
			s1[++cnt1]=p[i];
		else if(p[i].b==maxn)
			s2[++cnt2]=p[i];
		else
			s3[++cnt3]=p[i];
		ans+=maxn;
	}
//	for(int i=1;i<=n;i++)
//		cout<<p[i].a<<" "<<p[i].b<<" "<<p[i].c<<"\n";
//	cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<" "<<n<<"\n";
	if(cnt1>n/2){
		sort(s1+1,s1+cnt1+1,cmp1);
		for(int i=n/2+1;i<=cnt1;i++){
			ans-=s1[i].a-max(s1[i].b,s1[i].c);
		}
	}
	else if(cnt2>n/2){
//		cout<<"asd";
		sort(s2+1,s2+cnt2+1,cmp2);
		for(int i=n/2+1;i<=cnt2;i++){
			ans-=s2[i].b-max(s2[i].a,s2[i].c);
		}
	}
	else if(cnt3>n/2){
		sort(s3+1,s3+cnt3+1,cmp3);
		for(int i=n/2+1;i<=cnt3;i++)
			ans-=s3[i].c-max(s3[i].a,s3[i].b);
	}
	cout<<ans<<"\n";
}
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/
