#include <bits/stdc++.h>
using namespace std;
int n,k,cnt,add,ans;
vector<int> a;
int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		a.push_back(x);
	}
	for(int i=1;i<=n;i++){//长度 
		add=0;
		for(int j=0;j<n;j++){//遍历 
		    
			if(a[j]!=-1){//异或和 
				add=add xor a[j];
				cnt++;
				if(cnt<i){//长度不满足 
					continue;
				}else if(cnt==i && add==k){//长度满足要求且异或和满足要求 
			        for(int h=j;h>j-cnt;h--){
			        	a[h]=-1;
			        }
		        	add=add xor a[j-cnt+1];
					cnt--;
		        	ans++;
		        }else if(cnt==i && add!=k){//长度满足要求但异或和不满足 
			    	add=add xor a[j-cnt+1];
				    cnt--;
			    }
			    
		    }else{//区间间断 
		    	cnt=0;
		    	add=0;
		    }
	    }
    }
    printf("%d",ans);
	
	return 0;
}
