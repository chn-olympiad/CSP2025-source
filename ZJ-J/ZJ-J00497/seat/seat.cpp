#include<bits/stdc++.h>

using namespace std;

vector<int> v;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
//	freopen("seat3.in","r",stdin);
//	freopen("ans.out","w",stdout);
	
	int n,m;
	
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++){
		int num;
		
		cin>>num;
		
		v.push_back(num);
	}
	
	int cj=v[0];//小R成绩
	
	sort(v.begin(),v.end(),cmp);//从高到低排序 
	
	int x=1,y=1,d=1;//坐标
	
	bool fla=1;//我该不该转 
	
	for(int i=0;i<n*m;i++){
//		cout<<x<<" "<<y<<endl;
		if(v[i]==cj){//find it
			
			cout<<y<<" "<<x<<endl;
			
			break;
			
		}
		
		//don`t find it
		
		if((x==n||x==1)&&(fla==0)){
			y++;
			
			d*=-1;
			
			fla=1;
		}else{
			x+=d;
			
			fla=0;
		}
	} 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
in:
2 2
99 100 97 98
out:
1 2
in:
3 3
94 95 96 97 98 99 100 93 92
out: 
3 1
in:
2 2
98 99 100 97
out:
2 2
T2大约15分钟切了

犯唐了

时间复杂度O(NM)

但Nmax和Mmax都是10

话说这个大样例怎么这么水 
*/
