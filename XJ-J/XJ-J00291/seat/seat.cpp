#include<bits/stdc++.h>
using namespace std;
#define long long ll
int big_nuM=0,n,m,xe,fi,lieshu,hangshu;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>xe;
		if(i==1) fi=xe;
		else if(xe>fi) big_nuM++;
	}
	lieshu=(big_nuM/n)+1;
	hangshu=big_nuM+1-n*(lieshu-1);
	if(lieshu%2==0) hangshu=n-hangshu+1;
	cout<<lieshu<<" "<<hangshu;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
