
#include <vector>
#include <stdlib.h>
#include <limits>
#include <ostream>
using namespace std;
class Graph{

    public:
        Graph(){
            vertices = rand()%5 + 5;
            matrix.resize(vertices);
            for( size_t i = 0 ; i < vertices; ++i)
                matrix[i].resize(vertices);

            for( size_t i = 0 ; i < vertices; ++i)
                for( size_t j = 0 ; j < vertices; ++j)
                    if(rand()%3 == 0)
                        matrix[i][j] = numeric_limits<float>::max();
                    else                    
                        matrix[i][j] = rand()%9 + 1;
        }
        Graph(size_t n):vertices(n){
            matrix.resize(vertices);
            for( size_t i = 0 ; i < vertices; ++i)
                matrix[i].resize(vertices);

            for( size_t i = 0 ; i < vertices; ++i)
                for( size_t j = 0 ; j < vertices; ++j)
                    if(rand()%3 == 0)
                        matrix[i][j] = numeric_limits<float>::max();
                    else                    
                        matrix[i][j] = rand()%9 + 1;
        }

        float cost(int i, int j){
            return matrix[i][j];
        }
        size_t num_vertices(){return vertices;}
        
    private:
        size_t vertices;
        vector<vector<float>> matrix;
};

ostream& operator <<(ostream &out, Graph &g){
    for( size_t i = 0 ; i < g.num_vertices(); ++i)
                for( size_t j = 0 ; j < g.num_vertices(); ++j)
                    out <<"From "<<i<<" to "<<j<<" -> "<<g.cost(i,j)<<endl;
    
    return out;
}