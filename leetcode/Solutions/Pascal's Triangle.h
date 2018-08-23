class Solution_PascalTriangle {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        for( int i = 0; i < numRows; i++ ){
            vector<int> tmp( i+1, 1 );
            if( i+1 <= 2 )  ;
            else{
                for( int i = 1; i < i+1; i++ ){
                    tmp[i] = ret[i][i-1] + ret[i][i];
                }
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};