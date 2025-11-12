#include<bits/stdc++.h>
using namespace std;
struct fak{
	int grade;
	string name;
	int hang,lie;
};
bool cmp(fak a,fak b){
	return a.grade>b.grade;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	fak stu[200];
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>stu[i].grade;
		stu[i].name="else";
	}
	stu[0].name="R";
	sort(stu,stu+n*m,cmp);
	int t=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				stu[t].hang=j,stu[t].lie=i;
				t++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				stu[t].hang=j,stu[t].lie=i;
				t++;
			}
		}
	}
	for(int i=0;i<n*m;i++){
		if(stu[i].name=="R"){
			cout<<stu[i].lie<<' '<<stu[i].hang;
			return 0;
		}
	}
	return 0;
}