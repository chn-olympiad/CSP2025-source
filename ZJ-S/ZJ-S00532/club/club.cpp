#include<bits/stdc++.h>
using namespace std;
struct Node{
	int x,id;
}a[10];
bool cmp(const Node& u,const Node& v){
	return u.x>v.x;
}
struct Node2{
	int se,id;
};
bool cmp2(const Node2& u,const Node2& v){
	return u.se<v.se;
}
vector<Node2> vec[10];
int getint(){
	char ch=getchar();
	int res=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T,n;
	T=getint();
	while(T--){
		n=getint();
		for(int i=1;i<=3;i++) vec[i].clear();
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[j].x=getint(); a[j].id=j;
			}
			sort(a+1,a+4,cmp);
			ans+=a[1].x;
			vec[a[1].id].push_back(Node2{a[1].x-a[2].x,i});
		}
		for(int i=1;i<=3;i++){
			if(vec[i].size()>n/2){
				sort(vec[i].begin(),vec[i].end(),cmp2);
				for(int j=0;j<vec[i].size()-n/2;j++) ans-=vec[i][j].se;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}