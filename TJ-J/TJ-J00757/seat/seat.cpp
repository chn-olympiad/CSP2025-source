#include <bits/stdc++.h>
using namespace std;
int peo[1000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int nn,mm;
	cin>>nn>>mm;
	for(int i=1;i<=(nn*mm);i++){
		cin>>peo[i];
	}
	int ming=peo[1];
	int mings=0;
	sort(peo+1,peo+1+(nn*mm),cmp);
	for(int i=1;i<=(nn*mm);i++){
		if(peo[i]==ming) mings=i;
	}
	cout<<ceil(1.0*mings/nn)<<" ";
	if(int(ceil(1.0*mings/nn))%2==1){
		if(mings%nn){
			cout<<(mings%nn);
		}else{
			cout<<nn;
		}
		
	}else{
		if(mings%nn){
			cout<<(nn+1-mings%nn);
		}else{
			cout<<1;
		}
	}
	return 0;
}
