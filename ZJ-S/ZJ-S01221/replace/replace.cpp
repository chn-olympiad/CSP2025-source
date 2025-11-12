#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

int n,q;
string s1[N],s2[N];
void SOLVE(){
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
//		cout<<t1.size()<<" "<<t2.size()<<"\n";
		if(t1.size()!=t2.size()){puts("0");continue;}
		
		int sum=0;
		for(int i=1;i<=n;i++){
//			printf("%d:",i);
			for(int j=0;j<t1.size()-s1[i].size()+1;j++){
				
				bool flag=1;
				
				int l=j,r=j+s1[i].size()-1;
				for(int p=0;p<t1.size();p++){
					if(p<l || p>r){if(t1[p]!=t2[p]){flag=0;break;}}
					else if(s2[i][p-l]!=t2[p] || s1[i][p-l]!=t1[p]){flag=0;break;}
				}
				sum+=flag;
				
			}
//				printf("%d\n",sum);		
		}
		printf("%d\n",sum);
	}
	return ;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int Test_time=1;
//	scanf("%d",&Test_time);
	while(Test_time--)SOLVE();
	return 0;
}
/*
*/
