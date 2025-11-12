#include<bits/stdc++.h>
using namespace std;
int n,m;
int grade[105];
int rnum;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int len = n*m;
	for(int i = 1;i <= len;i++){
		cin>>grade[i];
	}
	rnum = grade[1];
	sort(grade+1,grade+1+len,cmp);
	int seat;
	for(int i = 1;i <= len;i++){
		if(grade[i] == rnum){
			seat = i;
			break;
		}
	}
	int straight = seat/n;
	int line = seat%n;
	if(seat%n != 0){
		straight++;
	}
	if(straight%2 == 0){
		line = n-line+1;
	}
	if(line == 0){
		line = n;
	}
	cout<<straight<<" "<<line;
	return 0;
}
