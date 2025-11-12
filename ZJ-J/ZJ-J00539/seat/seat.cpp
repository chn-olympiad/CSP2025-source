#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001],rs;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	rs=n*m;
	for(int i=1;i<=rs;i++){
		cin>>a[i];
	}
	int cj=a[1];
	sort(a+1,a+rs+1,cmp);
	int h=0,l=1;
	for(int i=1;i<=rs;i++){
        if(l%2==1) h++;
        else h--;
        if(h==n+1&&l%2==1){h--;l++;}
        if(h==0&&l%2==0){h++;l++;}
        //printf("No.%d,cj:%d l:%d h:%d\n",i,a[i],l,h);
        if(a[i]==cj){
            cout<<l<<" "<<h;
            break;
        }
	}
	return 0;
}
