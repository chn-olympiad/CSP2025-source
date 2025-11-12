#include<bits/stdc++.h>
using namespace std;
int score[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1,num;
	cin>>n>>m>>a1;
	score[1]=a1;
	for(int i=2;i<=n*m;i++){
		cin>>score[i];
	}
	sort(score,score+n*m+1);
	for(int i=n*m,j=1;i>=1;i--,j++){
		if(score[i]==a1) num=j;
	}
	//cout<<num<<endl;
	
	int hang=num%n,lie=num/n;
	if(hang==0) lie--,hang=n;
	if(lie%2==0) cout<<lie+1<<' '<<hang;
	else cout<<lie+1<<' '<<n-hang+1;
	return 0;
}
