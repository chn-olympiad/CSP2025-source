#include<bits/stdc++.h>
using namespace std;
int n,m;
int marks[110];
int _Mark;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>_Mark;
	marks[0]=_Mark;
	for(int i=1;i<n*m;i++)
		cin>>marks[i];
	sort(marks,marks+n*m,cmp);
	int id;
	for(int i=0;i<n*m;i++){
		if(marks[i]==_Mark){
			id=i+1;
		}
	}
	if((id/n)%2==0){
		cout<<(id+n-1)/n<<' '<<(id%m);
	}else{
		cout<<(id+n-1)/n<<' '<<(m-id%m);
	}
	return 0;
}
