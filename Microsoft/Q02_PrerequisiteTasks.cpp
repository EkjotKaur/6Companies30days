#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    int bfs(vector<vector<int>>&G, vector<int>&V, int i)
    {
        if(V[i]) return 0;
        V[i]=1;
        for(int j=0; j<G[i].size(); j++)
        {
            if(V[G[i][j]]==1) return 0;
            if(V[G[i][j]]==2) continue;
            if(!bfs(G, V, G[i][j])) return 0;
        }
        V[i]=2;
        return 1;
        
    }

public:
	bool isPossible(int N, vector<pair<int, int> >& P) {
	    // Code here
	    vector<vector<int>>G(N);
	    for(int i=0; i<P.size(); i++)
	    {
	        if(P[i].first == P[i].second ) return 0;
	        G[P[i].second].push_back(P[i].first);
	    }
	    
	    vector<int>V(N);
	    
	    int flag = 0;
	    for(int i=0; i<N; i++)
	    {
	        if(V[i]==2) continue;
	        if(V[i]==1) return 0;
	        if(!bfs(G, V, i)) return 0;
	    }
	        
	    return 1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends
