#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
struct f{
	int g1,g2,g3;//对第一二三个社团的满意度 
}s[N];//第i个人对每个社团的满意程度 
int cmp(int a,int b){
	if(a>b){
		return a;
	}
	else{
		return b;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		int p1=0,p2=0,p3=0;//当前社团人数 
		int hmax = n/2;//最大人数 
		int ans=0; 
		int gnow;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].g1>>s[i].g2>>s[i].g3;
			gnow=cmp(cmp(s[i].g1,s[i].g2),cmp(s[i].g2,s[i].g3));
			//判断当前社团人数是否在范围内
			if(p1<=hmax && s[i].g1==gnow){
				ans += gnow;
				p1++;
			}
			if(p2<=hmax && s[i].g2==gnow){
				ans += gnow;
				p2++;
			}
			if(p3<=hmax && s[i].g3==gnow){
				ans += gnow;
				p3++;
			}				
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
