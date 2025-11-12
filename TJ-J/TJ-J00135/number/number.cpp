#include<bits/stdc++.h>
using namespace std;
int geshu,sz[10];
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	geshu=a.size();
	for(int b=0;b<geshu;b++){
		if(a[b]=='1')
			sz[1]++;
		else if(a[b]=='2')
			sz[2]++;
		else if(a[b]=='3')
			sz[3]++;
		else if(a[b]=='4')
			sz[4]++;
		else if(a[b]=='5')
			sz[5]++;
		else if(a[b]=='6')
			sz[6]++;
		else if(a[b]=='7')
			sz[7]++;
		else if(a[b]=='8')
			sz[8]++;
		else if(a[b]=='9')
			sz[9]++;
		else if(a[b]=='0')
			sz[0]++;
	}
	for(int b=0;b<geshu;b++){
		if(sz[9]>0){
			cout<<9;
			sz[9]--;
		}else if(sz[8]>0){
			cout<<8;
			sz[8]--;
		}else if(sz[7]>0){
			cout<<7;
			sz[7]--;
		}else if(sz[6]>0){
			cout<<6;
			sz[6]--;
		}else if(sz[5]>0){
			cout<<5;
			sz[5]--;
		}else if(sz[4]>0){
			cout<<4;
			sz[4]--;
		}else if(sz[3]>0){
			cout<<3;
			sz[3]--;
		}else if(sz[2]>0){
			cout<<2;
			sz[2]--;
		}else if(sz[1]>0){
			cout<<1;
			sz[1]--;
		}else if(sz[0]>0){
			cout<<0;
			sz[0]--;
	}
	}
	return 0;
}
