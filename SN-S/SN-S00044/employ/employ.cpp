#include<bits/stdc++.h>
using namespace std;
long long a,s,f[100005],l_l[100005],p;
long long da; 
string d;
void ll(long long c,int l,int t){
	if(c==a-p){
		if(t>=s)da++;
		return;
	}
	for(int z=1; z<=a; z++){
		if(l_l[z]==0){
			l_l[z]=1;
			if(f[z]>l){
				if(d[c]=='0')ll(c+1,l+1,t);
				else ll(c+1,0,t+1);
			}
			l_l[z]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>a>>s;
	cin>>d;
	for(int z=1; z<=a; z++){
		cin>>f[z];
		if(f[z]==0)p++;
	}
	ll(0,0,0);
	cout<<da;
	return 0;
}
/*
3 2
101
1 1 2
*/
