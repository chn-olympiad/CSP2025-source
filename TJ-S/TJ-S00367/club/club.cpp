#include <bits/stdc++.h>
using namespace std;

struct val{
	int a,b,id;
};

int interest[4][100005];
val value[100005];
int n,i;
int cnt[4],m;

bool cmpX(int _a,int _b){return interest[_a][i]>interest[_b][i];}
bool cmpY(int _a,int _b){return _a>_b;}
bool cmpC(int _a,int _b){return cnt[_a]>cnt[_b];}
bool cmpV(val _a,val _b){return _a.a>_b.a;}
bool group(val _a,val _b){
	if(_a.id==m) return 0;
	else if(_b.id==m) return 1;
	return _a.id<_b.id;
} //GROUP BY FIRST-CLASS ID


void solve(){
	cin>>n;
	for(i=0;i<n;i++){
		cin>>interest[1][i]>>interest[2][i]>>interest[3][i];
		int x[3] = {1, 2, 3}, y[3] = { interest[1][i], interest[2][i], interest[3][i] };
		sort(x,x+3,cmpX);
		sort(y,y+3,cmpY);
		value[i].a=y[0];
		value[i].b=y[1];
		value[i].id=x[0];
		cnt[x[0]]++;
	}
	int ml[3]={1,2,3};
	sort(ml,ml+3,cmpC);
	m=ml[1];
	sort(value,value+n,group);
	sort(value,value+cnt[m],cmpV);
	int sum=0;
	for(i=0;i<n/2;i++)sum+=value[i].a;
	for(;i<cnt[m];i++)sum+=value[i].b;
	for(;i<n;i++)sum+=value[i].a;
	cout<<sum<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
