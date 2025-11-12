#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
   	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> v(n*m+1);
	int q=0;
	for(int i=1;i<=n*m;i++){
        cin>>v[i];
        if(i==1){
        q=v[i];
    }
	}
	 sort(v.begin()+1,v.end(),cmp);
	 int seat[n+1][m+1];
	 int lie=1;
	 for(int j=1;j<=n*m;){
        if(lie%2==0){
            for(int i=n;i>=1;i--){
                seat[lie][i]=v[j];
                j++;
            }
        }
        else{
            for(int i=1;i<=n;i++){
                seat[lie][i]=v[j];
                j++;
            }
        }
        lie++;
	 }
	 for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(seat[i][j]==q){
               cout<<i<<" "<<j;
                return 0;
           }
        }
	 }
	return 0;
}
