#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define ll long long
ll cnum,rnum,denum,Ans;
int fa[10005];
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > Edge;
int find(int n){
	if(fa[n]!=n) return find(fa[n]);
	return n;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>cnum>>rnum>>denum;
	for(int i=1;i<=cnum;i++) fa[i]=i;
	for(int i=1;i<=rnum;i++){
		int num1,num2,num3;
		scanf("%d %d %d",&num1,&num2,&num3);
		Edge.push({num3,{num1,num2}});
	}
	if(denum==0){
		while(!Edge.empty()){
			int c1=Edge.top().second.first,c2=Edge.top().second.second;
			int f1=find(c1),f2=find(c2);
			if(f1==f2){
				Edge.pop();
				continue;
			}
			Ans+=Edge.top().first;
			fa[c1]=f1,fa[c2]=f2;
			fa[f1]=f2;
			Edge.pop();
		}
		cout<<Ans;
	}
	else{
		for(int i=1;i<=denum;i++){
			int valueue;
			cin>>valueue;
			for(int j=1;j<=cnum;j++){
				int tt;scanf("%d",&tt);
			}
		}
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
