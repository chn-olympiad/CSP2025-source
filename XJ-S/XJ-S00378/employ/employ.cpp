#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int book[N]={0};
bool ren[N]={false};
int n,m;
#define ll long long
ll ans;
char exam[N];
int yl[N];
void bfs(int st){
	if(st==n){
		int ner=0,t=0;
//		for(int i=1;i<=n;i++){
//				cout<<book[i]<<' ';
//			}
//			cout<<endl;
		for(int i=1;i<=n;i++){
			if(yl[book[i]]<=ner || exam[i]=='0'){
				ner++;
			}else{
				t++;
			}
		}
		if(t>=m){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!ren[i]){
			ren[i]=true;
			book[st+1]=i;
			bfs(st+1);
			ren[i]=false;
			book[st+1]=0;
		}
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>exam[i];
	}
	for(int i=1;i<=n;i++){
		cin>>yl[i];
	}
	ans=0;
	bfs(0);
	cout<<ans;
	return 0;
}
