#include<bits/stdc++.h>
using namespace std;
int n,m,a,b[101],tt,g,sum,x[101];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	int q=n;
	int t=a;
	while(t!=0){
		x[q]=t%10;
		t/=10;
		q--;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		if(x[i]==0){
			cout<<0;
			return 0;
		}
		if(tt<=b[i]){
			if(x[i]==1){
				g++;
			}else{
				tt++;
			}
		}else{
			tt++;
		}
		if(g>=m) sum++;
	}
	cout<<sum;
	return 0;
}