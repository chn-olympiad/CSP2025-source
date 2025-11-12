#include<bits/stdc++.h>
using namespace std;
int n,m,s,c=1,r=0;bool jo;
struct node{
	int num,sum;
}a[110];
bool cmp(node x,node y){
	return x.sum>y.sum;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;i++){
		cin>>a[i].sum;
		a[i].num=i;
	}
	sort(a+1,a+s+1,cmp);
	for(int i=1;i<=s;i++){
		r++;
		if(r==n+1){
			if(jo==0){
				jo=1;
				r=n,c++;
			}else{
				jo=1;
				r=1,c++;
			}
		}
		if(a[i].num==1){
			cout<<c<<" "<<r;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}