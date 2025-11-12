#include<bits/stdc++.h>
using namespace std;
struct node{
	int first,second;
}v[1145141];
int a[1145141],vis[1145141],cnt,pushi;
bool cmp(node x,node y){
	return (x.second-x.first)<(y.second-y.first);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int t=a[i];
			for(int k=i+1;k<=j;k++){
				t^=a[k];
			}
			if(t==k)v[pushi].first=i,v[pushi++].second=j;
		}
	}
	sort(v,v+pushi,cmp);
	int ii=0;
	while(true){
		bool flag=0;
		for(int i=v[ii].first;i<=v[ii].second;i++){
			if(vis[i]){
				flag=1;
				break;
			}
		}
		if(!flag){
			for(int i=v[i].first;i<=v[i].second;i++)vis[i]=1;
			cnt++;
		}
		else{
			break;
		}
		ii++;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
