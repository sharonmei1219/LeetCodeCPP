class Solution {
public:
    
    class PosIter{
    public:
        PosIter(int row, int col): row(row), col(col){}
        virtual PosIter * next() = 0;
        int getRow()  {return row;}
        int getCol()  {return col;}
        protected:
        int row, col;
        
    };
    
    class MoveRight:public PosIter{
        public:
        MoveRight(int row, int col, int m, int n)
            :PosIter(row, col)
            ,m(m)
            ,n(n)
        {}
        
        PosIter * next(){
            if(col + row < n - 2 ){
                return new MoveRight(row, col + 1, m, n);
            }else{
                return new MoveDown(row, col + 1, m, n);
            }
        }
        private:
        int m, n;
    };

    class MoveDown:public PosIter{
        public:
        MoveDown(int row, int col, int m, int n)
            :PosIter(row, col)
            ,m(m)
            ,n(n)
        {}
        
        PosIter * next(){
            if(row - col < m - n - 1 ){
                return new MoveDown(row + 1, col, m, n);
            }else{
                return new MoveLeft(row + 1, col, m, n);
            }
        }
        private:
        int m, n;
    };
    
    
    class MoveLeft:public PosIter{
        public:
        MoveLeft(int row, int col, int m, int n)
            :PosIter(row, col)
            ,m(m)
            ,n(n)
        {}
        
        PosIter * next(){
            if(col + row > m ){
                return new MoveLeft(row, col-1, m, n);
            }else{
                return new MoveUp(row, col-1, m, n);
            }
        }
        private:
        int m, n;
    };

    
    class MoveUp:public PosIter{
        public:
        MoveUp(int row, int col, int m, int n)
            :PosIter(row, col)
            ,m(m)
            ,n(n)
        {}
        
        PosIter * next(){
            if(row - col > 2 ){
                return new MoveUp(row - 1, col, m, n);
            }else{
                return new MoveRight(row - 1, col, m, n);
            }
        }
        private:
        int m, n;
    };
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return {};
        int cnt = 0;
        const int m = matrix.size(), n = matrix[0].size();
        vector<int> result;
        PosIter * posIter = new MoveRight(0, -1, m, n);
        while(cnt < m * n){
            PosIter * next = posIter->next();
            delete posIter;
            posIter = next;
            const int row = posIter->getRow(), col = posIter->getCol();
            // result.push_back(posIter->getRow());
            // result.push_back(posIter->getCol());
            result.push_back(matrix[row][col]);
            cnt ++;
        }
        return result;
    }

};