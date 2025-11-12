#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;
const int N=1e6+7;
int n,q;
int a[N],b[N],x,y;
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int j=0,cnt1=0,cnt2=0;
		while(s1[j]!='b'){
			cnt1++;
			j++;
		}
		j=0;
		while(s2[j]!='b'){
			cnt2++;
			j++;
		}
		b[i]=abs((s1.size()-cnt1-1)-(s2.size()-cnt2-1));
		a[i]=abs(cnt1-cnt2);	
	} 
	while(q--){
		cin>>s1>>s2;
		int j=0,cnt1=0,cnt2=0,ans=0;
		while(s1[j]!='b'){
			cnt1++;
			j++;
		}
		j=0;
		while(s2[j]!='b'){
			cnt2++;
			j++;
		}
		y=abs((s1.size()-cnt1-1)-(s2.size()-cnt2-1));
		x=abs(cnt1-cnt2);
		for(int i=1;i<=n;i++){
			if(x%a[i]==0){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
