#include<iostream>
#include<algorithm>
using namespace std;
struct p{
	int a,b,c;
}s[100005];
bool cmp(p x,p y){
	return x.a>x.b;
}
long long ans=0,n;
void dfs(int x,string ss,int cnt1,int cnt2,int cnt3){
	if(x==n+1){
		long long sum=0;
		for(int i=0;i<ss.length();i++){
			if(ss[i]=='1') sum+=s[i+1].a;
			else if(ss[i]=='2') sum+=s[i+1].b;
			else sum+=s[i+1].c;
		}
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(i==1&&cnt1<n/2) dfs(x+1,ss+'1',cnt1+1,cnt2,cnt3);
		else if(i==2&&cnt2<n/2) dfs(x+1,ss+'2',cnt1,cnt2+1,cnt3);
		else if(cnt3<n/2) dfs(x+1,ss+'3',cnt1,cnt2,cnt3+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ans=-1;
		cin>>n;
		bool flag=0;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].b!=0||s[i].c!=0) flag=1;
		}
		if(flag==0){
			sort(s+1,s+1+n,cmp);
			long long sum=0;
			for(int i=1;i<=n/2;i++) sum+=s[i].a;
			cout<<sum<<endl;
		}else{
			dfs(1,"",0,0,0);
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
请问T1不会做还有救吗？ 
*/
