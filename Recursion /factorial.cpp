class Solution{	
	public:
		int fact(int N){
			//your code goes here
            if(N==0){
                return 1;
            }
            return N*fact(N-1);

		}
};
