/*
xg333 CSP-S must win!!!
T1代码
I LOVE CCF 100 YEARS
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
int c_1_2[100001],c_1_3[100001],c_2_3[100001];
int _1[100001],_2[100001],_3[100001];
bool flag[100001];
struct node{
	int x,id;
}man[200005];
int cnt=0;
bool cmd(node x,node y){
	return x.x<y.x;
}
void solve(){
	memset(flag,0,sizeof(flag));
	cnt=0;
	int n;
	cin>>n;
	vector<int> b;
	vector<int> c;
	vector<int> a;
	for(int i=1;i<=n;i++){
		cin>>_1[i]>>_2[i]>>_3[i];
		c_1_2[i]=_1[i]-_2[i];
		c_1_3[i]=_1[i]-_3[i];
		c_2_3[i]=_2[i]-_3[i];
		man[++cnt].id=i;
		man[cnt].x=c_1_2[i];
		man[++cnt].id=i;
		man[cnt].x=c_1_3[i];
	}
	int num=0;
	sort(man+1,man+cnt+1,cmd);
	for(int i=1;i<=cnt;i++){
		if(num==n/2) break;
		if(flag[man[i].id]==0){
			num++;
			flag[man[i].id]=1;
			if(man[i].x==c_1_2[man[i].id]){
				b.push_back(man[i].id);
			}
			else{
				c.push_back(man[i].id);
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		if(flag[man[i].id]==0){
			if(_2[man[i].id]-_1[man[i].id]>_3[man[i].id]-_1[man[i].id]&&_2[man[i].id]-_1[man[i].id]>0){
				if(int(b.size())<n/2){
					b.push_back(man[i].id);
				}
				else if(int(c.size())<n/2&&_3[man[i].id]-_1[man[i].id]>0){
					c.push_back(man[i].id);
				}
				else{
					a.push_back(man[i].id);
				}
				flag[man[i].id]=1;
			}
			else if(_2[man[i].id]-_1[man[i].id]<_3[man[i].id]-_1[man[i].id]&&_3[man[i].id]-_1[man[i].id]>0){
				if(int(c.size())<n/2){
					c.push_back(man[i].id);
				}
				else if(int(b.size())<n/2&&_2[man[i].id]-_1[man[i].id]>0){
					b.push_back(man[i].id);
				}
				else{
					a.push_back(man[i].id);
				}
				flag[man[i].id]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(flag[i]==0){
			a.push_back(i);
			flag[i]=1;
		}
	}
	long long sum=0;
	for(const int &it:a){
		sum+=_1[it];
	}
	for(const int &it:b){
		sum+=_2[it];
	}
	for(const int &it:c){
		sum+=_3[it];
	}
	cout<<sum<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}