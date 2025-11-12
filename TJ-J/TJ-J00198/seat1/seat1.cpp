#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,nr,mr;
	cin>>n>>m;
	int a=n*m;
	int r,num;
	int score[a];
	for(int i=0;i<a;i++){
		cin>>score[i];
	}
	r=score[0];
	sort(score,score+a);
	for(int i=0;i<a;i++){
		if(score[i]==r){
			num=i;
		}
	}
	num=a-num;
	if((num%n)>0){
		mr=num/n+1;
	}else{
		mr=num/n;
	}
	if((mr%2)==0){
		nr=n-(num%n)+1;
	}else{
		if((num%n)==0){
			nr=num%n+n;
		}else{
			nr=num%n;
		}
	}
	cout<<mr<<' '<<nr<<endl;
return 0;
}
