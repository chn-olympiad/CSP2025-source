#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int inf=0x3f3f3f3f;
const int MAXN=1e5+2;

struct node{
	int c=-1;
	int v[3];
} a[MAXN];

int T;
int n;
vector<int> rec[3];
int rl[3];
int ans=0;

int ese1(int x){
	if (x==0){
		return 1;
	}
	else{
		return 0;
	}
}

int ese2(int x){
	if (x==2){
		return 1;
	}
	else{
		return 2;
	}
}

int tail(int x){
	return rec[x][rl[x]-1];
}
void push(int x,int v){
	rec[x].push_back(v);
	rl[x]++;
	a[v].c=x;
}

int get(int i,int x){
	if (rl[x]>n/2){
		return -inf;
	}
	else{
		return a[i].v[x];
	}
}

int jian(int i,int x){
	return max(get(i,ese1(x)),get(i,ese2(x)))-a[i].v[x];
}

bool cmp0(int x,int y){
	if (jian(x,0)==jian(y,0)){
		return a[x].v[0]>a[y].v[0];
	}
	return jian(x,0)<jian(y,0);
}
bool cmp1(int x,int y){
	if (jian(x,1)==jian(y,1)){
		return a[x].v[1]>a[y].v[1];
	}
	return jian(x,1)<jian(y,1);
}
bool cmp2(int x,int y){
	if (jian(x,2)==jian(y,2)){
		return a[x].v[2]>a[y].v[2];
	}
	return jian(x,2)<jian(y,2);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while (T--){
		for (int i=0;i<3;i++){
			rec[i].clear();
		}
		memset(rl,0,sizeof(rl));
		ans=0;
		cin >> n;
		for (int i=0;i<n;i++){
			scanf("%d%d%d",&a[i].v[0],&a[i].v[1],&a[i].v[2]);
			if (a[i].v[0]>a[i].v[1] && a[i].v[0]>a[i].v[2]){
				a[i].c=0;
				push(0,i);
			}
			else if (a[i].v[1]>a[i].v[2]){
				a[i].c=1;
				push(1,i);
			}
			else{
				a[i].c=2;
				push(2,i);
			}
		}
		
		for (int i=0;i<3;i++){
			if (rl[i]>n/2){
				if (i==0){
					sort(rec[i].begin(),rec[i].end(),cmp0);
				}
				else if (i==1){
					sort(rec[i].begin(),rec[i].end(),cmp1);
				}
				else{
					sort(rec[i].begin(),rec[i].end(),cmp2);
				}
			}
			while (rl[i]>n/2){
				int now=tail(i);
				if (a[now].v[ese1(i)]>a[now].v[ese2(i)] && rl[ese1(i)]<n/2){
					push(ese1(i),tail(i));
				}
				else{
					push(ese2(i),tail(i));
				}
				rl[i]--;
			}
		}
		
		for (int i=0;i<3;i++){
			for (int j=0;j<rl[i];j++){
				ans+=a[rec[i][j]].v[i];
			}
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
