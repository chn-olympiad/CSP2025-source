#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int pre_xor[N],dad[N];//cha fen
vector<int> vec[N];
pair<int,int> p[N];
int cmp(pair<int,int> a,pair<int,int> b){
	return a.second<b.second;
}
void bing(int x,int y){
	dad[y]=dad[x];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	for(int i=1;i<N;i++){
		dad[i]=i;
	}
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		pre_xor[i]=pre_xor[i-1]^x;
		vec[pre_xor[i]].push_back(i);
	}
	int cnt=1;
	for(int i=0;i<n;i++){
		int x=pre_xor[i]^k,now=0,len=vec[x].size();
		//printf("%d:%d\n",i,x);
		if(len>0){
			while(vec[x][now]<=i&&now<len){
				now++;
			}
		}
		if(now<len){
			//printf("%d %d\n",i+1,vec[x][now]);
			p[cnt]=make_pair(i+1,vec[x][now]);
			cnt++;
		}
	}
	sort(p+1,p+cnt,cmp);
	int must=p[1].second;
	for(int i=2;i<cnt;i++){
		//printf("%d %d\n",p[i-1].second,p[i].second);
		if(must>=p[i].first){
			bing(i-1,i);
		}else{
			must=p[i].second;
		}
	}
	sort(dad+1,dad+cnt);
	int last=-1,ans=0;
	for(int i=1;i<cnt;i++){
	//	printf("%d\n",dad[i]);
		if(dad[i]!=last){
			last=dad[i];
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
