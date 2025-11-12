#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,ws;
	cin>>n>>m;
	int s[10005];
	for(int i = 0;i<n*m;i++){
		cin>>s[i];
	}
	int z = s[0];
	for(int a = 0;a<n*m;a++){
		for(int b = 0;b<n*m-1;b++){
			if(s[b]>s[b+1]){
				char h= s[b];
				s[b] = s[b+1];
				s[b+1] = h;	
			
			}
		}
	}
	for(int j = 0;j<n*m;j++){
		if(s[j]==z);int ws = j;
	}
	int x, y,cs;
	int jg;
	x = 1;
	y = 1;
	cs = 1;
	jg = 0;
	for(int xh = 0; jg=ws ; xh++){
		if(x == n){
			y++;
			jg++;
			cs = cs*-1;
		}
		if(x == 1){
			y++;
			jg++;
			cs = cs*-1;
		}
			else{
				jg++;
				x = x+cs;
			}
	}
	cout<<y<<" "<<x;			
	fclose(stdin);
	fclose(stdout);
	return 0 ;
}

