/*Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.
Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.*/



class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int mod=1e9+7;
        int n=arr.size();
        vector<int>pre(n , 0);
        vector<int>next(n , 0);
        stack<int>st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                pre[i]=st.top();

            }else{
                pre[i]=-1;
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(!st.empty()){
                next[i]=st.top();

            }else{
                next[i]=n;
            }
            st.push(i);
        }

        long long res=0;
        for(int i=0; i<n; i++){
            int left=i-pre[i];
            int right=next[i]-i;
            res = (res + 1LL*arr[i] * left * right% mod) % mod;
        }
        return res;

       

       
    }
};
