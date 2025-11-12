#include<bits/stdc++.h>
using namespace std;
struct stud{
	int nm,sc;
	bool operator <(stud w)const{
		return w.sc<sc;
	}
};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	vector<stud> stu(n*m);
	for(int i=0;i<n*m;i++){
		cin>>stu[i].sc;
		stu[i].nm=i;
	}
	sort(stu.begin(),stu.end());
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(!stu[cnt++].nm){
				cout<<i<<' '<<(i&1?j:n-j+1);
				return 0;
			}
} 
