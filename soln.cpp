#include <bits/stdc++.h>
using namespace std;

double prob(int k, int g, int v) {
    long long total = (long long)(g + 1) * (v + 1);
    int x = max(0, k - v);
    int y = min(g, k);
    long long valid = max(0, y - x + 1);
    return (double)valid / total;
}
double mini=0.00000001;

void func(){
	int n,g,v;
	cin>>n>>g>>v;
	
	double ans=0;
	
	vector<double> two(n+1,0);
	
	for(int i=0;i<=g+v;i++){
		if(i>n){
			two[n]+=prob(i,g,v);
			continue;
		}
		two[i]=prob(i,g,v);
    }
    vector<double> dp(n+1,0);
    ans+=two[n]*1;
    
	for(int i=1;i<n+1;i++){
		double temp=0;
		for(int j=0;j<i;j++){
			for(int k=n;k>=0;k--){
				if(j+k<i){
					break;
				}
				temp+=two[j]*two[k];
			}			
		}
		dp[i]=temp;
	}
    
    ans+=dp[n]*2;
    
    int k=3;
    
    while(true){
    	for(int i=1;i<n+1;i++){
			double temp=0;
			for(int j=0;j<i;j++){
				temp+=two[j]*dp[i-j];
			}
			dp[i]=temp;	
		}
		ans+=dp[n]*k;
		if(dp[n]*k<mini){
			break;
		}
		k++;      
    }
    
    cout<<ans<<endl;
	
	
	
}

int main(){
	func();
	return 0;	
}
