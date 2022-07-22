#include<stack> 
int largestRectangle(vector < int > & hist) {
   // Write your code here.
     int maxi = 0;
    stack<int> st;
    int n = hist.size();
    
    for(int i=0; i<=n; i++){
        while(!st.empty() && (i==n || hist[st.top()] >= hist[i])){
            int height = hist[st.top()];
            st.pop();
            int width;
            
            if(st.empty() )
                width = i;
            else
                width  = i -  st.top() -1;
            maxi = max(maxi, height*width);
        }
        
        st.push(i);
    }
    return maxi;
 }
