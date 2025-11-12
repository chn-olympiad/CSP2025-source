#include<bits/stdc++.h>
using namespace std;
struct san3daj{
	int yi=0;
	int er=0;
	int san=0;
	int zongshu=0;
};
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		san3daj san3dai[1000];
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>san3dai[i].yi>>san3dai[i].er>>san3dai[i].san;
			san3dai[i].zongshu=max(san3dai[i].yi,max(san3dai[i].er,san3dai[i].san));
		}
		if(san3dai[1].er==0&&san3dai[1].san==0&&san3dai[2].er==0&&san3dai[2].san==0){//特判 ———————— 
			long long jishuqi=0;
			for(int i=1;i<=n;i++){
			jishuqi+=san3dai[i].yi;
			}
			cout<<jishuqi;
			continue;
		}//—————————————————————————————————————————————————— 
		bool chuk=false;
		while(true){//把加分最多的放前面 
			chuk=false;
			for(int i=1;i<n;i++){
				if(san3dai[i+1].zongshu>san3dai[i].zongshu){
					swap(san3dai[i],san3dai[i+1]);
					chuk=true;
					continue;
				}
			}
			if(chuk==false){
					break;
				}
		}
		long long jishuqi=0,a,yi=0,er=0,san=0;//dp:每个人第一想去的 
		
		for(int i=1;i<=n;i++){//遍历一遍去1学院的最大值并进入 
			a=max(san3dai[i].yi,max(san3dai[i].er,san3dai[i].san));
				if(a==san3dai[i].yi&&yi<n/2){//最爱的是yi 
					jishuqi+=a;	
					yi++;
					continue;
				}else if(san3dai[i].er>san3dai[i].san&&er<n/2){
						jishuqi+=san3dai[i].er;
						er++;
						continue;
				}else{
					jishuqi+=san3dai[i].san;
					san++;
					continue;
				}	
				
				if(a==san3dai[i].er&&er<n/2){//最爱的是er
					jishuqi+=a;	
					er++;
					continue;
				}else if(san3dai[i].yi>san3dai[i].san&&yi<n/2){
						jishuqi+=san3dai[i].yi;
						yi++;
						continue;
				}else{
					jishuqi+=san3dai[i].san;
					san++;
					continue;
				}
				
				if(a==san3dai[i].san&&san<n/2){//最爱的是san
					jishuqi+=a;	
					san++;
					continue;
				}else if(san3dai[i].er>san3dai[i].yi&&er<n/2){
						jishuqi+=san3dai[i].er;
						er++;
						continue;
				}else{
					jishuqi+=san3dai[i].yi;
					yi++;
					continue;
				}
		}
		cout<<jishuqi;
	}
	return 0;
}

