#include<bits/stdc++.h>
using namespace std;
int t,n;
struct PI{
	int aa,ab,ac;
	bool operator < (const &PI l)const{
	    return aa>l.aa;
	}
}b[114514];
struct PI1{
	int aa,ab;
	bool operator < (const &PI1 l)const{
	    return aa>l.aa;
	}
}b1[114514];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	cin>>t;
	for(int opo=1;opo<=t;opo++){
		cin>>n;
		bool fa=1,fb=1,fc=1;
		for(int i=1;i<=n;i++){
			cin>>b[i].aa>>b[i].ab>>b[i].ac;
			if(b[i].ab!=0||b[i].ac!=0) fa=0;
			if(b[i].ac!=0) fb=0;
		}
		if(fa){
			long long ans;
			sort(a+2,a+n+1);
			for(int j=1;j<=n;j++){
				ans+=b[i].aa;
			}
			return ans;
		}
	}
	
	return 0;
} 