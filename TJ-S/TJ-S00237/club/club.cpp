#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int cop[3];
int ap[100005];
int al[100005];
int a[100005][3];
int satisfy;
int unsatisfy;
int chao;
int chazhi[100005];
    
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	//输入组数t
    while(t>0)
	{
    t-=1;
	cin>>n;
	cop[1]=0;
	cop[2]=0;
	cop[3]=0;
	for(int i=1;i<=n;i++){
		chazhi[i]=20006;
	}

    
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int most=0,second=0;
		int n=a[i][1];
		int p=a[i][2];
		int q=a[i][3];
		if(n>=p&&n>=q&&p>=q){
			most=1,second=2;
		}
		else if(n>=p&&n>=q&&q>p){
			most=1,second=3;
		} 
		else if(p>n&&p>=q&&n>=q){
			most=2,second=1;
		}
		else if(p>n&&p>=q&&q>=n){
			most=2,second=3;
		} 
		else if(q>n&&q>p&&n>=p){
			most=3,second=2;
		}
		else if(q>n&&q>p&&p>n){
			most=3,second=1;
		}
		ap[i]=most;
		al[i]=second;
	}
	//输入满意度 
	
	for(int i=1;i<=n;i++){
		cop[ap[i]]++;
	}

	//统计对第1,2,3个岗位最满意的人数 
	satisfy=0;
	unsatisfy=0;

	for(int i=1;i<=n;i++){
		satisfy+=a[i][ap[i]];
	}

	int tt=n/2;
	if(cop[1]<=tt&&cop[2]<=tt&&cop[3]<=tt){
		cout<<satisfy<<endl;
        continue;
	}
	
	for(int i=1;i<=3;i++){
		if(cop[i]>n/2) chao=i;
	}

	//哪个岗位超了 
	for(int i=1;i<=n;i++){
		if(ap[i]==chao){
			chazhi[i]=a[i][ap[i]]-a[i][al[i]];
		}
	}

  
	//排序，谁的差值最小谁走人 
	int ji=cop[chao]-n/2;

    sort(chazhi,chazhi+n+1);
   
    for(int i=1;i<n&&ji>0;i++){
    	unsatisfy+=chazhi[i];
    	ji--;
	}
	
    satisfy-=unsatisfy;

	cout<<satisfy<<endl;
	
	
    }
	
	return 0;
} 
