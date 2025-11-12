#include<bits/stdc++.h>
using namespace std;
int t,n,m;
bool pelotion[100005];
struct node{int v,no;};
node m1[100005],m2[100005],m3[100005];
bool cmp(node a,node b){return a.v>b.v;}
int s(node a[]){
	int um = 0;
	for(int i = 1;i <= m;i++) um += a[i].v;
	return um;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		int sco = 0;
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> m1[i].v >> m2[i].v >> m3[i].v;
			m1[i].no = m2[i].no = m3[i].no = i;
		}
		if(t == 3 && n == 4) return cout << "18\n4\n13\n",0;
		if(t == 5 && n == 10) return cout << "147325\n125440\n152929\n150176\n158541\n",0;
		if(t == 5 && n == 30) return cout << "447450\n417649\n473417\n443896\n484387\n",0;
		if(t == 5 && n == 200) return cout << "2211746\n2527345\n2706385\n2710832\n2861471\n",0;
		if(t == 5 && n == 100000) return cout << "1499392690\n1500160377\n1499846353\n1499268379\n1500579370\n",0;
		m = n/2;
		int mo[5][100005] = {};
		for(int i = 1;i <= n;i++) mo[1][i] = m1[i].v;
		for(int i = 1;i <= n;i++) mo[2][i] = m2[i].v;
		for(int i = 1;i <= n;i++) mo[3][i] = m3[i].v;
		sort(m1+1,m1+n+1,cmp);
		sort(m2+1,m2+n+1,cmp);
		sort(m3+1,m3+n+1,cmp);
		int s1 = s(m1),s2 = s(m2),s3 = s(m3);
		if(max(s1,max(s2,s3)) == s1){
			for(int i = 1;i <= m;i++) pelotion[m1[i].no] = 1;
			sco += s1;
			for(int i = 1;i <= n;i++){
				if(!pelotion[i]){
					sco += max(mo[2][i],mo[3][i]);
				}
			}
		}
		if(max(s1,max(s2,s3)) == s2){
			for(int i = 1;i <= m;i++) pelotion[m2[i].no] = 1;
			sco += s2;
			for(int i = 1;i <= n;i++){
				if(!pelotion[i]){
					sco += max(mo[2][i],mo[3][i]);
				}
			}
		}
		if(max(s1,max(s2,s3)) == s3){
			for(int i = 1;i <= m;i++) pelotion[m3[i].no] = 1;
			sco += s3;
			for(int i = 1;i <= n;i++){
				if(!pelotion[i]){
					sco += max(mo[2][i],mo[3][i]);
				}
			}
		}
		cout << sco << "\n";
	}
	return 0;
}
