#include<bits/stdc++.h>
using namespace std;
long long n,m,mn,nm,ans[300000],num;
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>num;
	ans[0]=num;
	for(int i=1;i<n*m;i++){
		cin>>ans[i];
	}
	sort(ans,ans+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(ans[i]==num){
			mn=i;
			break;
		}
	}
	mn++;
	for(int i=0;i<1000000;i++){
		if(mn>m){
			mn-=m;
			nm++;
		}else{
			break;
		}
	} 
	
	if((nm+1)%2==0){
		cout<<nm+1<<" "<<m-mn+1;
	}else{
		cout<<nm+1<<" "<<mn;
	}
	return 0;
}
