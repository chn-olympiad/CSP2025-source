#include<bits/stdc++.h> 
using namespace std;
struct node{
	int num,oo;
}mm[100001][3];
long long t,n,mem[100001][3],vv[100001][3],ans,l,z;
bool cmp(node a,node b){
	return a.num>b.num;
}
void cho(long long aa,long long bb,long long cc){
	mm[l][0].num = aa;
	mm[l][0].oo = 0;
	mm[l][1].num = bb;
	mm[l][1].oo = 1;
	mm[l][2].num = cc;
	mm[l][2].oo = 2;
	sort(mm[l],mm[l]+3,cmp);
	if(vv[z][mm[l][0].oo]<n/2){
		vv[z][mm[l][0].oo]++;
		ans+=mm[l][0].num;
	}else if(vv[z][mm[l][1].oo]<n/2){
		vv[z][mm[l][1].oo]++;
		ans+=mm[l][1].num;
	}else if(vv[z][mm[l][2].oo]<n/2){
		vv[z][mm[l][2].oo]++;
		ans+=mm[l][2].num;
	}
	l++;
}
int main (){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >>t;
	for(;z<t;z++){
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> mem[i][0] >> mem[i][1] >> mem[i][2];
		}
		for(int i=0;i<n;i++){
			cho(mem[i][0],mem[i][1],mem[i][2]);
		}cout << ans << endl;
		l = 0;
		ans = 0;
		for(int i=0;i<100001;i++){
			vv[i][0] = 0;
			vv[i][1] = 0;
			vv[i][2] = 0;
			mm[i][0].num = 0;
			mm[i][1].num = 0;
			mm[i][2].num = 0;
			mm[i][0].oo = 0;
			mm[i][1].oo = 0;
			mm[i][2].oo = 0;
		}
	}
	return 0;
}
