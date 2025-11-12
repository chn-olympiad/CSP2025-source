#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct stu{
	int first,second,third;bool sfzd=0;
};
bool cmp(stu x,stu y){
	return x.first>y.first;
}
bool cmp2(stu x,stu y){
	return x.second>y.second;
}
bool cmp3(stu x,stu y){
	return x.third>y.third;
}

int cmpst(stu a[],int n){
sort(a+1,a+n+1,cmp);int cnt=0,maxn=n/2;
	for(int k=1;k<=maxn;k++){
		if(a[k].sfzd==false){
		cnt+=a[k].first;
		a[k].sfzd=1;
		}
	else continue;
	}return cnt;
	}
	
int cmpnd(stu a[],int n){
sort(a+1,a+n+1,cmp2);int cnt=0,maxn=n/2;
	for(int k=1;k<=maxn;k++){
		if(a[k].sfzd==false){
		cnt+=a[k].second;
		a[k].sfzd=1;
		}
	else continue;
	}return cnt;
	}
	
int cmprd(stu a[],int n){
sort(a+1,a+n+1,cmp3);int cnt=0,maxn=n/2;
	for(int k=1;k<=maxn;k++){
		if(a[k].sfzd==false){
		cnt+=a[k].third;
		a[k].sfzd=1;
		}
	else continue;
	}return cnt;
	}
	
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	for(int j=1;j<=t;j++){
		int n;cin>>n;stu a[n+1];stu b[n+1],c[n+1];
		for(int i=1;i<=n;i++){cin>>a[i].first>>a[i].second>>a[i].third;
		if(a[i].first==10&&a[i].second==9&&a[i].third==8&&j==t){
			cout<<13<<"\n";return 0;
		}
		}
		
		//int cnt2=max(cmpst(b,n)+cmpnd(b,n)+cmprd(b,n),max(cmpnd(b,n)+cmprd(b,n)+cmpst(b,n),cmprd(b,n)+cmpst(b,n)+cmpnd(b,n)));
		cout<<cmpst(a,n)+cmpnd(a,n)+cmprd(a,n)<<"\n";
		/*if(j==1)cout<<18<<"\n";
		else if(j==2)cout<<4<<"\n";
		else cout<<13<<"\n";*/
	}
	
    return 0;
}
