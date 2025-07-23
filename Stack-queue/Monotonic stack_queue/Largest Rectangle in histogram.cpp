/*Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:
Input: heights = [2,4]
Output: 4*/




class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nse(n);
        vector<int>pse(n);
        stack<int>st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()]>heights[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i]=n;
               

            }else{
                nse[i]=st.top();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i]=-1;
               
            }else{
                pse[i]=st.top();
            }
            st.push(i);
        }

        int maxi=0;
        for(int i=0; i<n; i++){
            int area=heights[i] *(nse[i]-pse[i]-1);
            maxi=max(maxi, area);

        }
        return maxi;


        
    }
};
 
