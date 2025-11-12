#include <bits/stdc++.h>
using namespace std;
int a[105][105];
struct studentt{
	int sco;
	int bh;//编号  
}stu[10005];
int cmp(studentt x,studentt y){
	return x.sco>y.sco;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int rs=n*m;
	int rpm=0;//人数   R的排名 
	for(int i=0;i<rs;i++){
		cin>>stu[i].sco;
		stu[i].bh=i+1;
	}
	sort(stu,stu+rs,cmp);
	for(int i=0;i<rs;i++){
		if(stu[i].bh==1){
			rpm=i+1; 
		}
	}
	int l=0;
	if(rpm%n==0){
		l=rpm/n;
	}else{
		l=rpm/n;
		l++;
	}
	int h=0;
	if(l%2==0){
		h=(n-(rpm-((l-1)*n)))+1;
	}else{
		h=rpm-((l-1)*n);
	}
//	cout<<"rpm:"<<rpm<<"  l:"<<l<<"   h:"<<h<<"+++++++++"<<m<<endl;
	cout<<l<<" "<<h; 
	return 0;
} 
