#include<bits/stdc++.h>
using namespace std;
struct mm{
	int co = 0;
	int ct = 0;
	int cth = 0;
	int j = 0;
	int b = 0;
};
mm a[100005];
int clubone,clubtwo,clubthree;
int n,cc,sum,top;
bool clubb(mm a,mm b){
	return a.j>b.j;
}
int bianhuanone(int s){
	for(int i=s;i<n;i++){
		a[i].co=-1;
	}
}
int bianhuantwo(int s){
	for(int i=s;i<n;i++){
		a[i].ct=-1;
	}
}
int bianhuanthree(int s){
	for(int i=s;i<n;i++){
		a[i].cth=-1;
	}
}
int gengxin(int s,int c){
	for(int i=s;i<n;i++){
		if(a[i].b==c){
			if(a[i].co>=a[i].ct&&a[i].co>=a[i].cth){
				a[i].j = a[i].co;
				a[i].b=1;
			}else if(a[i].ct>a[i].co&&a[i].ct>=a[i].cth){
				a[i].j = a[i].ct;
				a[i].b=2;
			}else{
				a[i].j = a[i].cth;
				a[i].b=3;
				
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>cc;
	for(int hh=0;hh<cc;hh++){
		cin>>n;
		clubone=0;
		clubtwo=0;
		clubthree=0;
		sum=0;
		top = n/2;
		for(int i=0;i<n;i++){
			cin>>a[i].co>>a[i].ct>>a[i].cth;
			if(a[i].co>=a[i].ct&&a[i].co>=a[i].cth){
				a[i].j = a[i].co;
				a[i].b=1;
			}else if(a[i].ct>a[i].co&&a[i].ct>=a[i].cth){
				a[i].j = a[i].ct;
				a[i].b=2;
			}else{
				a[i].j = a[i].cth;
				a[i].b=3;
			}
		}
		sort(a,a+n,clubb);
		for(int i=0;i<n;i++){
			if(clubone==top){
				bianhuanone(i);
				gengxin(i,1);
			}
			if(clubtwo==top){
				bianhuantwo(i);
				gengxin(i,2);
			}
			if(clubthree==top){
				bianhuanthree(i);
				gengxin(i,3);
			}
			if(a[i].b==1){
				sum+=a[i].j;
				clubone++;
			}else if(a[i].b==2){
				sum+=a[i].j;
				clubtwo++;
			}else if(a[i].b==3){
				sum+=a[i].j;
				clubthree++;
			} 
		}
		cout<<sum<<endl;
	}
	return 0;
}
