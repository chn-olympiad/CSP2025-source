#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
bool cmp(int a,int b){
	return a>b;
}
int a[N][5],cnt[N]/*第i个人一开始选择cnt[i]号部门*/,cntt[N]/*第i个部门的人数*/,qwq[5][N]/*该部门的第几个人是i*/;
void init(){
	memset(cnt,0,sizeof cnt);
	memset(cntt,0,sizeof cntt);
	memset(qwq,0,sizeof qwq);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool flag=0;
		init();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			int maxn=-11451419,pos=0;
			for(int j=1;j<=3;j++){
				if(a[i][j]>maxn){
					maxn=a[i][j];
					pos=j;
				}
			}
			cnt[i]=pos;
			if(maxn==a[i][1]) qwq[1][++cntt[1]]=i;
			else if(maxn==a[i][2]) qwq[2][++cntt[2]]=i;
			else qwq[3][++cntt[3]]=i;
		}
		for(int i=1;i<=3;i++){
			if(cntt[i]>n/2){
				flag=1;
				break;
			}
		}
		long long sum=0;
		for(int i=1;i<=n;i++) sum+=max(a[i][1],max(a[i][2],a[i][3]));
		if(!flag) cout<<sum<<"\n";
		else{
			/*
			for(int i=1;i<=n;i++){
				cout<<"1 to 2:"<<a[i][2]-a[i][1]<<"  "<<"2 to 1:"<<a[i][1]-a[i][2]<<"\n";
				cout<<"2 to 3:"<<a[i][3]-a[i][2]<<"  "<<"3 to 2:"<<a[i][2]-a[i][3]<<"\n";
				cout<<"1 to 3:"<<a[i][3]-a[i][1]<<"  "<<"3 to 1:"<<a[i][1]-a[i][3]<<"\n\n";
				cout<<"best is:"<<cnt[i]<<"\n\n";
			}
			*/
			//如果这个部门的人数已经大于n/2，则此时需要换走cntt[i]-n/2个人，把那些 换走（换到其他两个部门之一）之后收益差最小的那些人 换走。 
			if(cntt[1]>n/2){
				int qaq[N],wyh=0;
				memset(qaq,-0x3f3f3f3f,sizeof qaq);
				for(int i=1;i<=cntt[1];i++){
					qaq[++wyh]=max(a[qwq[1][i]][2]-a[qwq[1][i]][1],a[qwq[1][i]][3]-a[qwq[1][i]][1]);
				}
				sort(qaq+1,qaq+wyh+1,cmp);
				for(int i=1;i<=cntt[1]-n/2;i++){
					sum+=qaq[i];
				}
				cout<<sum<<"\n";
			}else if(cntt[2]>n/2){
				int qaq[N],wyh=0;
				memset(qaq,-0x3f3f3f3f,sizeof qaq);
				for(int i=1;i<=cntt[2];i++){
					qaq[++wyh]=max(a[qwq[2][i]][1]-a[qwq[2][i]][2],a[qwq[2][i]][3]-a[qwq[2][i]][2]);
				}
				sort(qaq+1,qaq+wyh+1,cmp);
				for(int i=1;i<=cntt[2]-n/2;i++){
					sum+=qaq[i];
				}
				cout<<sum<<"\n";
			}else{
				int qaq[N],wyh=0;
				memset(qaq,-0x3f3f3f3f,sizeof qaq);
				for(int i=1;i<=cntt[3];i++){
					qaq[++wyh]=max(a[qwq[3][i]][2]-a[qwq[3][i]][3],a[qwq[3][i]][1]-a[qwq[3][i]][3]);
				}
				sort(qaq+1,qaq+wyh+1,cmp);
				for(int i=1;i<=cntt[3]-n/2;i++){
					sum+=qaq[i];
				}
				cout<<sum<<"\n";
			}
		}
	}
	return 0;
}
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/
