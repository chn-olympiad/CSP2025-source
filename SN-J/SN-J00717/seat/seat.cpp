#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int id,lie,hang;
	int b[110];
	cin>>n>>m;
	int stu_num=n*m;
	int a[110];
	for(int i=1;i<=stu_num;i++){
		cin>>a[i];
	}
	int a_r=a[1];
	sort(a+1,a+stu_num+1);
	int count=1;
	for(int i=stu_num;i>=1;i--){
		b[count]=a[i];
		count++;  
	}
	for(int i=1;i<=stu_num;i++){
		if(b[i]==a_r)   id=i;
	}
	if((id%n)!=0){
		lie=id/n+1;
	}
	else    lie=id/n;
	int mi=id-(lie-1)*n;
	if(lie%2==0){
		hang=n-mi+1;
	}
	else{
		hang=mi;
	}
	cout<<lie<<' '<<hang;
	return 0;
} 
