#include <bits/stdc++.h>
using namespace std;
struct good{
	string t1,t2;
}huan[100005];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>huan[i].t1 >>huan[i].t2 ;
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int sum=0;
		int m=t1.size()-1;
		for(int i=0;i<=m;i++){
			for(int j=1;j<=n;j++){
				bool l=0;
				string f=t1;
				for(int k=0;k<=huan[j].t1 .size()-1;k++){
					if(huan[j].t1 [k]!=t1[i+k]){
					
						l=1;
						break;
					}
					f[i+k]=huan[j].t2 [k];
				}
				if(l)continue;
				if(f==t2)sum++;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}

/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/