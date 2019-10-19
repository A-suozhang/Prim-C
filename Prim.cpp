
# include <iostream>

# define LENGTH(a)(sizeof(a)/sizeof(a[0])) // Interesting Way

using namespace std;

typedef char Vertex;


// Define The Graph Here
// I Know It's quite stupid
# define NumVertex 5
Vertex _Vex[NumVertex] = {'0','1','2','3','4'};
int _AdjacentMatrix[NumVertex][NumVertex] = {{0, 7, 5, 0, 20},
                                            {7, 0, 10, 15, 16},
                                            {5, 10, 0, 0, 30},
                                            {0, 15, 0, 0, 4},
                                            {20,16, 30, 4, 0}};


class Graph{
    public:
        Vertex Vexs[NumVertex]; // Adtually It's useless since we only call it by index, you can name it as you like
        int AdjacentMatrix[NumVertex][NumVertex];
        Graph();
        ~Graph();    
        void initializeGraph();
        void PrintGraph();
        void MST_Prim();
};

/*  并不支持构造函数直接给数组赋值
Graph::Graph(Vertex _Vex[], int** _AdjacentMatrix){
    Vexs =_Vex;
    AdjacentMatrix = _AdjacentMatrix;
}
*/

Graph::Graph(){
    cout << "Graph Created." << endl;
}

Graph::~Graph(){
    cout << "Graph Deleted" << endl;
}

void Graph::initializeGraph(){
    // 传一个二维数组作为形参实在有点麻烦
    // memcpy(_Vex,this->Vexs,sizeof(Vexs));
    // memcpy(_AdjacentMatrix,this->AdjacentMatrix,sizeof(AdjacentMatrix));

    // Here Comes Some Dirty Code
    for (int i=0;i<NumVertex;i++){
        this->Vexs[i] = _Vex[i];
    }
    
    for (int i=0;i<NumVertex;i++){
        for(int j=0;j<NumVertex;j++){
            this->AdjacentMatrix[i][j] = _AdjacentMatrix[i][j];
        }
    }

    cout << "Graph Initialized." << endl;
}

void Graph::PrintGraph(){
    cout << "The Vertexs Are:";
    for(int i=0;i<NumVertex;i++){
        cout << this->Vexs[i] << ',';
    }
    cout << endl;

    cout << "The Adjacent Matrix:" << endl;
    for (int i=0;i<NumVertex;i++){
        for (int j=0;j<NumVertex;j++){
            cout << this-> AdjacentMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

// The Miniest Span Tree Prim Algo
void Graph::MST_Prim(){

    int NumVertexSelected = 0;
    int SelecetedVertex[NumVertex] ={0};

    SelecetedVertex[0] = 1; //Choose The 0th Vertex As Starting Point
    int x;
    int y;

    cout << "Edge" << " : " << "Weight" << endl;
    while(NumVertexSelected < NumVertex-1){
        int min = 65536; // Initialize Min As A Big Value
        x = 0;  // Being The Temp Min Edge's x&y index
        y = 0;

        for(int i=0;i<NumVertex;i++){
            if(SelecetedVertex[i]){     // Selected Vertex In Tree, Finding The Min Edge Linked with Them  
                for (int j=0;j<NumVertex;j++){
                    // if the node haven't been Selected && Is A Edge(diagonal elemnet of Adjacent Matrix are Zero)
                    // Also We Use 0 when no link,so we must exclude it
                    if (!SelecetedVertex[j] && this->AdjacentMatrix[i][j]){
                        if (min > this->AdjacentMatrix[i][j]){  // If A New Min Occurs
                            min = this->AdjacentMatrix[i][j];
                            x = i;
                            y = j;
                        }
                    } 
                }
            }
        }
        cout << x << "-" << y << ":" << this->AdjacentMatrix[x][y] << endl;
        SelecetedVertex[y] = 1;     // Y Node Has Been Chosen
        NumVertexSelected = NumVertexSelected+1;
    }

}


int main(){
    Graph g0;
    g0.initializeGraph();
    g0.PrintGraph();
    g0.MST_Prim();

    return 0;

}

