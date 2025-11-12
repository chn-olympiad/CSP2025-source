#include <bits/stdc++.h>
using namespace std;
struct node{
	int b;
	int x;
	int y;
}a[500005];
int n,m;
int ans[500005];
vector<node>vec[2000005];
bool cmp1(node a,node b){
	return a.x<b.x;
}
bool cmp2(node a,node b){
	return a.y<b.y;
}
map<int,int>mp;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int b1=s1.find('b');
		int b2=s2.find('b');
		a[i].b=b1-b2;
		if(a[i].b<0){
			a[i].b+=2000000;
		}
		a[i].x=b1+1;
		a[i].y=s1.size()-a[i].x;
	}
	for(int i=n+1;i<=n+m;i++){
		string s1,s2;
		cin>>s1>>s2;
		int b1=s1.find('b');
		int b2=s2.find('b');
		a[i].b=b1-b2;
		if(a[i].b<0){
			a[i].b+=2000000;
		}
		a[i].x=b1+1;
		a[i].y=s1.size()-a[i].x;
	}
	for(int i=1;i<=n;i++){
//		cout<<"b"<<a[i].b<<endl;
		vec[a[i].b].push_back(a[i]);
	}
	for(int i=n+1;i<=n+m;i++){
		int it=a[i].b;
//		cout<<"23423423423"<<endl;
//		cout<<"it"<<it<<endl;
		for(int j=0;j<vec[it].size();j++){
//			cout<<"it"<<it<<endl;
//			cout<<"vec[it].size"<<vec[it].size()<<endl;
			if(a[i].x>=vec[it][j].x&&a[i].y>=vec[it][j].y){
				ans[i]++;
			}
		}
	}
	for(int i=n+1;i<=n+m;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
/*
2 3
baa
aab
aaaaab
aaabaa
aaaaaaaab
aaaaaabaa
aab
baa
aba
baa
*/
