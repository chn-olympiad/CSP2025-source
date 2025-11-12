#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	int a;
	cin>>a;
	int cheng[105];
	cheng[0]=a;
	for(int i=1;i<n*m;i++){
		cin>>cheng[i];
	}
	sort(cheng,cheng+n*m);
	int nnn=1,mmm=1;
	int nm=1;
	for(int i=0;i<n*m;i++){
		if(cheng[i]==a){
			break;
		}nnn+=nm;
		if(nnn>n){
			++mmm;
			nnn=n;
			nm=-1;
		}else if(nnn<1){
			nm=1;
			++mmm;
			nnn+=nm;
		}
	}cout<<nnn<<' '<<mmm;
	return 0;
}
