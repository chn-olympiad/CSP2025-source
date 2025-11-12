#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,q,a,m[N],d1[N],d2,sum;
string s1[N],s2[N],q1,q2;
bool check(int x,int y){
	for(int i=0;i<=x-1;i++){
		if(q1[i]!=q2[i]) return false;
	}
	for(int i=y;i<a;i++){
		if(q1[i]!=q2[i]) return false;
	}
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i],d1[i]=s1[i].size();
	while(q--){
		sum=0;
		cin>>q1>>q2;
		a=q1.size();
		for(int i=0;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				if(check(i,j)==false) continue;
				string t1,t2;
				for(int k=i;k<j;k++){
					t1+=q1[k];
					t2+=q2[k];
				}
				d2=t1.size();
				for(int k=1;k<=n;k++){
					if(t1==s1[k] and t2==s2[k] and d1[k]==d2) sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
