#include<iostream>
#include<algorithm>
using namespace std;
struct club{
	long long a1,a2,a3;
};
club c[100010];
bool cmp(const club &a,const club &b){
	return a.a1+a.a2+a.a3<b.a1+b.a2+b.a3;
}
struct Ans{
	long long x,y;
};
Ans ans[5];
bool cmp1(const Ans &a,const Ans &b){
	return a.x>b.x;
}
int n2[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	long long n;
	cin>>t;
	while(t--){
		cin>>n;
		for(long long i=0;i<n;i++){
			cin>>c[i].a1>>c[i].a2>>c[i].a3;
		}
		sort(c,c+n,cmp);
		long long tot=0,j=1;
		for(long long i=0;i<n;i++){
			ans[1].x=c[i].a1;
			ans[1].y=1;
			ans[2].x=c[i].a2;
			ans[2].y=2;
			ans[3].x=c[i].a3;
			ans[3].y=3;
			sort(ans+1,ans+4,cmp1);
			if(n2[ans[j].y]>=n/2) j++;
			tot+=ans[j].x;
			n2[ans[j].y]++;
		}
		cout<<tot<<endl;
		for(long long i=0;i<5;i++){
			n2[i]=0;
		}
	}
	return 0;
}
