#include<bits/stdc++.h>
#define LANH using
#define AK namespace
#define CSPS std
LANH AK CSPS;
typedef long long ll;
int n,q;
map<string,string>mp;
string tmp,tmp2,tmp3,tmp4;
int l,sum;
int sll,rr;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>tmp>>tmp2;
		mp[tmp]=tmp2;
	}
	while(q--){
		cin>>tmp>>tmp4;
		sum=0;
		l=tmp.size();
		sll=l;
		rr=0;
		if(l!=tmp4.size()){
			puts("0");
			continue;
		}
		for(int i=0;i<l;i++){
			if(tmp[i]!=tmp4[i]){
				sll=min(sll,i);
				rr=max(rr,i);
			}
		}
		for(int i=0;i<l;i++){
			tmp2="";
			tmp3="";
			for(int j=i;j<l;j++){
				tmp2+=tmp[j];
				tmp3+=tmp4[j];
				if(mp[tmp2]==tmp3&&i<=sll&&rr<=j){
					sum++;
				}
			}
		}
		cout<<sum<<'\n';
	}
	return 0;

}

