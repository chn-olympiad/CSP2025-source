#include<bits/stdc++.h>
using namespace std;
const int maxn=100100;
struct member
{
	long long cl1,cl2,cl3,cl4,cl5,cl6;
}a[maxn];
long long n,upt,res1=0,res2=0,res3=0,res=0,T;
bool cmp1(member x,member y)
{
	return x.cl1+y.cl4>x.cl4+y.cl1;
}
bool cmp2(member x,member y)
{
	return x.cl2+y.cl5>x.cl5+y.cl2;
}
bool cmp3(member x,member y)
{
	return x.cl3+y.cl6>x.cl6+y.cl3;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		res1=0,res2=0,res3=0,res=0;
		cin >> n;
		upt=n/2;
		for(int i=1;i<=n;i++){
			cin >> a[i].cl1 >> a[i].cl2 >> a[i].cl3;
			a[i].cl4=max(a[i].cl2,a[i].cl3);
			a[i].cl5=max(a[i].cl1,a[i].cl3);
			a[i].cl6=max(a[i].cl1,a[i].cl2);
		}
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=upt;i++){
			res1+=a[i].cl1;
		}
		for(int i=upt+1;i<=n;i++){
			res1+=a[i].cl4;
		}
		sort(a+1,a+1+n,cmp2);
		for(int i=1;i<=upt;i++){
			res2+=a[i].cl2;
		}
		for(int i=upt+1;i<=n;i++){
			res2+=a[i].cl5;
		}
		sort(a+1,a+1+n,cmp3);
		for(int i=1;i<=upt;i++){
			res3+=a[i].cl3;
		}
		for(int i=upt+1;i<=n;i++){
			res3+=a[i].cl6;
		}
		res=max(res1,res2);
		res=max(res,res3);
		cout << res << "\n";
	}
	return 0;
}
