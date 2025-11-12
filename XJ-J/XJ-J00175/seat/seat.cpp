#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n=0,m=0;
    cin>>n>>m;
    int a=n*m;
    int s[a];
    int ss=0;
    cin>>ss;
    int dysl;
    for (int i;i=1;i<=a,i++){
    	cin>>s[i];
    	if(s[i]>ss){
    		dysl+=1;
		}
	}
	int hd=0,ld=0;
	hd=dysl/m;
	ld=dysl-hd;
	if(ld==0){
		ld+=1;
	}
	cout<<hd<<' '<<ld;
    return 0;

}
