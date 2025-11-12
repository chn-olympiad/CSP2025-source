#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct road{
	int from,to,value;
}a[1000010];
bool cmp(road a,road b){
	return a.value<b.value;
}
vector<int> ad[100010];
int id[10010];
void change(int a,int b){
	for(int i=0;i<ad[a].size();i++){
		id[ad[a][i]]=b;
		ad[b].push_back(ad[a][i]);
	}
}
int read(){
	int x=0;
	char c;
	while(1){
		c=getchar();
		if('0'<=c&&c<='9')break;
	}
	x=c-'0';
	while(1){
		c=getchar();
		if(!('0'<=c&&c<='9'))break;
		x=x*10+c-'0';
	}
	return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		id[i]=i;
		ad[i].push_back(i);
	}
	for(int i=1;i<=m;i++){
		a[i].from=read();
		a[i].to=read();
		a[i].value=read();
	}
	for(int i=1;i<=k;i++){
		int x;
		for(int j=0;j<=n;j++)x=read();
	}
	sort(a+1,a+m+1,cmp);
	long long ans=0;
	for(int i=1;i<=m;i++){
		if(id[a[i].from]==id[a[i].to])continue;
		ans+=a[i].value;
		if(ad[id[a[i].from]].size()<ad[id[a[i].to]].size()){
			change(id[a[i].from],id[a[i].to]);
		}else{
			change(id[a[i].to],id[a[i].from]);
		}
		//c();
	}
	cout<<ans;
	return 0;
}