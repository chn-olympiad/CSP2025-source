#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=1e5+5;
int q(int a,int b,int c){
	if(a>b){
		if(b>=c)return b;
		else{
			if(a>c)return c;
			else return a;
		}
	}
	else if(a==b)return a;
	else{
		if(a>=c)return a;
		else{
			if(b>c)return c;
			else return b;
		}
	}
}
struct S{
	int f,t,w;
};
bool cmp(S a,S b){
	return a.w>b.w;
}
vector<S>p;
int n;
void solve(){
	cin>>n;
	p.clear();
	int sum=0;
	for(int i=1;i<=n;i++){
		int a[4];
		cin>>a[1]>>a[2]>>a[3];
		int mn=q(a[1],a[2],a[3]),no,yes;
		a[1]-=mn,a[2]-=mn,a[3]-=mn;
		sum+=mn;
		if(a[1]==0)no=1;
		else if(a[2]==0)no=2;
		else no=3;
		if(a[1]>0)yes=1;
		else if(a[2]>0)yes=2;
		else if(a[3]>0)yes=3;
		else continue;
		p.push_back({no,yes,a[yes]});
	}
	sort(p.begin(),p.end(),cmp);
	int cnt1=0,cnt2=0,cnt3=0;
	for(S e:p){
		int t=e.t,f=e.f,w=e.w;
		if(w==0)break;
		if(t==1&&cnt1<n/2)sum+=w,cnt1++;
		if(t==2&&cnt2<n/2)sum+=w,cnt2++;
		if(t==3&&cnt3<n/2)sum+=w,cnt3++;
	}
	cout<<sum<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
