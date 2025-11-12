#include<bits/stdc++.h>;
//CCF×£ÎÒÎôÁ°0+1²»Íá£¡£¡£¡ 
//CCF×£ÎÒÎôÁ°0+1²»Íá£¡£¡£¡
//CCF×£ÎÒÎôÁ°0+1²»Íá£¡£¡£¡ 
//CCF×£ÎÒÎôÁ°0+1²»Íá£¡£¡£¡ 
//CCF×£ÎÒÎôÁ°0+1²»Íá£¡£¡£¡ 
//CCF×£ÎÒÎôÁ°0+1²»Íá£¡£¡£¡   
//CCF×£ÎÒÎôÁ°0+1²»Íá£¡£¡£¡ 
//CCF×£ÎÒÎôÁ°0+1²»Íá£¡£¡£¡ 
//CCF×£ÎÒÏ¾µû0+1²»Íá£¡£¡£¡ 
//CCF×£ÎÒÏ¾µû0+1²»Íá£¡£¡£¡ 
//CCF×£ÎÒÏ¾µû0+1²»Íá£¡£¡£¡ 
//CCF×£ÎÒÏ¾µû0+1²»Íá£¡£¡£¡ 
//CCF×£ÎÒÏ¾µû0+1²»Íá£¡£¡£¡ 
//CCF×£ÎÒÏ¾µû0+1²»Íá£¡£¡£¡ 
//CCF×£ÎÒÏ¾µû0+1²»Íá£¡£¡£¡ 
//CCF×£ÎÒÏ¾µû0+1²»Íá£¡£¡£¡ 
//CCF×£ÎÒÏ¾µû0+1²»Íá£¡£¡£¡ 
//CCF×£ÎÒ·çÝÀ0+1²»Íá£¡£¡£¡ 
//CCF×£ÎÒ·çÝÀ0+1²»Íá£¡£¡£¡
//CCF×£ÎÒ·çÝÀ0+1²»Íá£¡£¡£¡
//CCF×£ÎÒ·çÝÀ0+1²»Íá£¡£¡£¡
//CCF×£ÎÒ·çÝÀ0+1²»Íá£¡£¡£¡
//CCF×£ÎÒ·çÝÀ0+1²»Íá£¡£¡£¡
//CCF×£ÎÒ¼ÇÒäÕ½½¢²»Íá£¡£¡£¡
//CCF×£ÎÒ¼ÇÒäÕ½½¢²»Íá£¡£¡£¡
//CCF×£ÎÒ¼ÇÒäÕ½½¢²»Íá£¡£¡£¡
//CCF×£ÎÒ¼ÇÒäÕ½½¢²»Íá£¡£¡£¡
//CCF×£ÎÒ¼ÇÒäÕ½½¢²»Íá£¡£¡£¡
//ÎôÃÅÓÀ´æ£¡ 
//ÎôÃÅÓÀ´æ£¡
//ÎôÃÅÓÀ´æ£¡
//ÎôÃÅÓÀ´æ£¡
//°®ÃÅÓÀ´æ£¡
//°®ÃÅÓÀ´æ£¡
//°®ÃÅÓÀ´æ£¡
//°®ÃÅÓÀ´æ£¡
using namespace std;
const int N=114;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin>>n>>m;
	vector<int> s;
	int seat[12][12]={0};
	int a;
	cin>>a;
	s.push_back(a);
	int ans=a;
	for(int i=0;i<n*m-1;i++){
		int a;
		cin>>a;
		s.push_back(a);
	}
	sort(s.begin(),s.end(),greater<int>());
	for(int i=0;i<m;i++){ 
		if(i%2==0){
			int k=0;
			for(int j=i*n;j<i*n+n;j++){
				seat[k][i]=s[j];
				//cout<<s[j]<<" dcf"<<j;
				k++;
			}
			//cout<<" \n";
			//cout<<" tdu";
	    }else{
	    	int k=0;
	    	for(int j=i*n+n-1;j>=i*n;j--){
				seat[k][i]=s[j];
				k++;
			}
		}
    }
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		if(seat[i][j]==ans){
    			cout<<j+1<<" "<<i+1;
    			break;
			}
	    }
    }
    /*&for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cout<<seat[i][j]<<" ";
	    }
	    cout<<"\n";
    }*/
	return 0;
}
